#include "Parser.h"
#include "Coder.h"
#include "VMtranslator.h"
#include "utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VMtranslator* vmt_init(const char* fileName, FILE* inputFile, FILE* outputFile)
{
  VMtranslator* vmt = (VMtranslator*)xmalloc(sizeof(VMtranslator));

  vmt->inputFile = inputFile;
  vmt->outputFile = outputFile;

  vmt->fileName = (char*)xmalloc(strlen(fileName) + 1);
  strcpy(vmt->fileName, fileName);

  return vmt;
}

void vmt_free(VMtranslator* vmt)
{
  if (!vmt) return;
  if (vmt->fileName) free(vmt->fileName);
  free(vmt);
}

/** 
 * handle_arithmetic è l'unica funzione che ha bisogno solo di arg1, ma che può generare un errore
 **/
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

/**
 *  handle_push_like gestisce le funzioni che hanno bisogno di arg1 e arg2 e che possono generare un errore,
 *  ovvero handle_push, handle_pop, handle_function, handle_call
 **/ 
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

/**
 *  handle_label_like gestisce le funzioni che hanno bisogno solo di arg1 e che non generano un errore,
 *  ovvero handle_label, handle_goto, handle_if
 **/ 
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

bool vmt_generate(VMtranslator* vmt)
{
  bool status = true;
  Parser* parser = parser_init(vmt->inputFile);
  Coder* coder = coder_init(vmt->outputFile, vmt->fileName);

  coder_write_start(coder);

  while (parser->hasMoreCommands)
  {
    CommandType type = parser_command_type(parser);
    switch (type)
    {
    case C_ARITHMETIC:
      if (!handle_arithmetic(parser, coder)) status = false;
      break;
    case C_PUSH:
      if (!handle_push(parser, coder)) status = false;
      break;
    case C_POP:
      if (!handle_pop(parser, coder)) status = false;
      break;
    case C_LABEL:
      if (!handle_label(parser, coder)) status = false;
      break;
    case C_GOTO:
      if (!handle_goto(parser, coder)) status = false;
      break;
    case C_IF:
      if (!handle_if(parser, coder)) status = false;
      break;
    case C_FUNCTION:
      if (!handle_function(parser, coder)) status = false;
      break;
    case C_CALL:
      if (!handle_call(parser, coder)) status = false;
      break;
    case C_RETURN:
      coder_write_return(coder);
      break;
    case C_NULL:
      fprintf(stderr, "Error at line %d: Unknown command: %s\n", parser->currLine, parser->currCommand);
      status = false;
      break;
    default:
      assert(0 && "Unexpected command type during translation");
      break;
    }

    if (status == false) goto cleanUp;

    parser_advance(parser);
  }

cleanUp:
  parser_free(parser);
  coder_free(coder);

  return status;
}
