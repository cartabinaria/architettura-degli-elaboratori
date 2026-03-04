#include "Coder.h"
#include "dataStructures.h"
#include "Parser.h"
#include "VMtranslator.h"
#include "utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VMtranslator* vmt_init(FILE* outputFile)
{
  if (!outputFile) return NULL;

  VMtranslator* vmt = xmalloc(sizeof(*vmt));
  // inizializza tutto a zero (array a NULL, num=0, ...)
  memset(vmt, 0, sizeof(*vmt));

  vmt->outputFile = outputFile;

  vmt->coder = coder_init(vmt->outputFile);
  if (!vmt->coder) 
  {
    free(vmt);
    return NULL;
  }

  coder_write_start(vmt->coder);
  return vmt;
}

void vmt_free(VMtranslator* vmt)
{
  if (!vmt) return;

  for (int i = 0; i < vmt->numInputFiles; i++) 
  {
    if (vmt->inputFiles[i]) 
    {
      fclose(vmt->inputFiles[i]);
      vmt->inputFiles[i] = NULL;
    }
    free(vmt->inputFileNames[i]);
    vmt->inputFileNames[i] = NULL;
  }

  if (vmt->coder) 
  {
    coder_free(vmt->coder);
    vmt->coder = NULL;
  }

  if (vmt->callsCollector) 
  {
    bst_free(vmt->callsCollector);
    vmt->callsCollector = NULL;
  }

  free(vmt);
}

bool vmt_collect_file(VMtranslator* vmt, FILE* file, const char* fileName)
{
  if (!vmt || !file || !fileName) return false;

  if (vmt->numInputFiles >= MAX_INPUT_FILES) 
  {
    fprintf(stderr, "Error: vmt_collect_file() failed: max number of input files reached\n");
    return false;
  }

  int i = vmt->numInputFiles;

  vmt->inputFiles[i] = file;
  vmt->inputFileNames[i] = xstrdup(fileName);
  vmt->numInputFiles++;

  return true;
}

// handle_arithmetic è l'unica funzione che ha bisogno solo di arg1, ma che può generare un errore
static bool handle_arithmetic(Parser* parser, Coder* coder)
{
  char* op = parser_arg1(parser);
  if (!op) return false;

  if (!coder_write_arithmetic(coder, op))
  {
    fprintf(stderr, "Error at line %d: Invalid operation: %s", parser->currLine, parser->currCommand);
    free(op);
    return false;
  } 
  free(op);
  return true;
}

// handle_push_like gestisce le funzioni che hanno bisogno di arg1 e arg2 e che possono generare un errore,
// ovvero handle_push, handle_pop, handle_function, handle_call
typedef bool (*WriteSegFn)(Coder*, const char*, int);

static bool handle_push_like(Parser* parser, Coder* coder, WriteSegFn fn, const char* errMsg) 
{
  char* arg1 = parser_arg1(parser);
  if (!arg1) return false;

  int arg2 = parser_arg2(parser);
  if (arg2 == -1) { free(arg1); return false; }

  if (!fn(coder, arg1, arg2)) 
  {
    fprintf(stderr, "Error at line %d: %s: %s\n", parser->currLine, errMsg, parser->currCommand);
    free(arg1);
    return false;
  }

  free(arg1);
  return true;
}

static bool handle_push(Parser* p, Coder* c) 
{
  return handle_push_like(p, c, coder_write_push, "Invalid memory segment or address");
}

static bool handle_pop(Parser* p, Coder* c) 
{
  return handle_push_like(p, c, coder_write_pop, "Invalid memory segment or address");
}

static bool handle_function(Parser* p, Coder* c) 
{
  return handle_push_like(p, c, coder_write_function, "Invalid function declaration");
}

static bool handle_call(Parser* p, Coder* c) 
{
  return handle_push_like(p, c, coder_write_call, "Invalid function call");
}

// handle_label_like gestisce le funzioni che hanno bisogno solo di arg1 e che non generano un errore,
// ovvero handle_label, handle_goto, handle_if
typedef void (*WriteLabelFn)(Coder*, const char*);

static bool handle_label_like(Parser* parser, Coder* coder, WriteLabelFn fn) 
{
  char* label = parser_arg1(parser);
  if (!label) return false;

  fn(coder, label);
  free(label);
  return true;
}

static bool handle_label(Parser* p, Coder* c) 
{
  return handle_label_like(p, c, coder_write_label);
}

static bool handle_goto(Parser* p, Coder* c) 
{
  return handle_label_like(p, c, coder_write_goto);
}

static bool handle_if(Parser* p, Coder* c) 
{
  return handle_label_like(p, c, coder_write_if);
}

static bool translate_file(VMtranslator* vmt, Parser* parser)
{
  while (parser->hasMoreCommands)
  {
    CommandType type = parser_command_type(parser);

    switch (type)
    {
    case C_ARITHMETIC:
      if (!handle_arithmetic(parser, vmt->coder)) return false;
      break;
    case C_PUSH:
      if (!handle_push(parser, vmt->coder)) return false;
      break;
    case C_POP:
      if (!handle_pop(parser, vmt->coder)) return false;
      break;
    case C_LABEL:
      if (!handle_label(parser, vmt->coder)) return false;
      break;
    case C_GOTO:
      if (!handle_goto(parser, vmt->coder)) return false;
      break;
    case C_IF:
      if (!handle_if(parser, vmt->coder)) return false;
      break;
    case C_FUNCTION:
    {
      char* name = parser_arg1(parser);
      // se una funzione non viene mai chiamata non viene tradotta
      if (!bst_contains(vmt->callsCollector, name))
      {
        free(name);
        parser_advance(parser);
        while (parser->hasMoreCommands && parser_command_type(parser) != C_FUNCTION) 
          parser_advance(parser);
        
        continue;
      }
      else 
      {
        free(name);
        if (!handle_function(parser, vmt->coder)) return false;
      }
      break;
    }
    case C_CALL:
      if (!handle_call(parser, vmt->coder)) return false;
      break;
    case C_RETURN:
      coder_write_return(vmt->coder);
      break;
    case C_NULL:
      fprintf(stderr, "Error at line %d: Unknown command: %s\n", parser->currLine, parser->currCommand);
      return false;
    default:
      assert(0 && "Unexpected command type during translation");
      return false;
    }

    parser_advance(parser);
  }

  return true;
}

static void collect_calls(BstListNode** callsTree, Parser* parser)
{
  char* functionName = NULL;

  while (parser->hasMoreCommands)
  {
    CommandType type = parser_command_type(parser);

    if (type == C_FUNCTION)
    {
      free(functionName);
      functionName = parser_arg1(parser);
    }
    else if (type == C_CALL)
    {
      char* called = parser_arg1(parser);
      // se ho del codice che non appartiene a nessuna funzione, lo faccio figurare appartenente a Sys.init
      *callsTree = bstlist_insert(*callsTree, functionName ? functionName : "Sys.init", called);
      free(called);
    }

    parser_advance(parser);
  }

  free(functionName);
}

static void insert_calls(BstListNode* callsTree, VMtranslator* vmt, const char* functionName)
{
  if (bst_contains(vmt->callsCollector, functionName)) return;

  vmt->callsCollector = bst_insert(vmt->callsCollector, functionName);
  const ListNode* callsList = bstlist_get(callsTree, functionName);
  while (callsList)
  {
    insert_calls(callsTree, vmt, callsList->val);
    callsList = callsList->next;
  }
}

bool vmt_translate_all(VMtranslator* vmt)
{
  // 1) colleziono tutte le chiamate per ogni funzione
  BstListNode* callsTree = NULL;
  for (int i = 0; i < vmt->numInputFiles; ++i)
  {
    Parser* parser = parser_init(vmt->inputFiles[i]);
    if (!parser) return false;

    collect_calls(&callsTree, parser);
    parser_free(parser);
  }
  
  // 2) filtro le funzioni in base a quelle effettivamente chiamate dal programma
  insert_calls(callsTree, vmt, "Sys.init");
  bstlist_free(callsTree);
  

  // 3) traduco tutti i file
  for (int i = 0; i < vmt->numInputFiles; ++i)
  {
    Parser* parser = parser_init(vmt->inputFiles[i]);
    if (!parser) return false;

    coder_update_fileName(vmt->coder, vmt->inputFileNames[i]);
    
    if (!translate_file(vmt, parser))
    {
      parser_free(parser);
      return false;
    }
    parser_free(parser);
  }

  return true;
}
