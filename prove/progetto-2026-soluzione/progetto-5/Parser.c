#include "Parser.h"
#include "CommandType.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

Parser* parser_init(FILE* file)
{
  Parser* p = (Parser*)xmalloc(sizeof(Parser));

  p->file = file;
  p->hasMoreCommands = 1;
  p->currLine = 0;
  p->currCommand = NULL;

  parser_advance(p);
  return p;
}

void parser_free(Parser* p)
{
  if (p == NULL) return;
  if (p->currCommand != NULL) free(p->currCommand);
  free(p);
}

char* clean_line(char* line)
{
  if (!line) return NULL;

  char* cleaned = (char*)xmalloc(strlen(line) + 1);
  int i = 0, j = 0;
  while (isspace((unsigned char)line[i])) ++i;

  while (line[i] != 0)
  {
    if (line[i] == '/' && line[i+1] == '/') break;

    cleaned[j] = line[i];
    ++i;
    ++j;
  }

  while (j > 0 && isspace((unsigned char)cleaned[j-1])) --j;
  cleaned[j] = 0;
  return cleaned;
}

void parser_advance(Parser* p)
{
  if (!p->hasMoreCommands) return;

  char *line = NULL;
  size_t len = 0;

  if (p->currCommand) 
  {
    free(p->currCommand);
    p->currCommand = NULL;
  }

  while (1) 
  {
    if (getline(&line, &len, p->file) == -1) 
    {
      free(line);
      p->hasMoreCommands = 0;
      return;
    }

    char *cleaned = clean_line(line);
    p->currLine++;

    if (cleaned[0] == '\0') 
    {
      free(cleaned);
      continue;
    }

    p->currCommand = cleaned;
    break;
  }

  free(line);
}


CommandType parser_command_type(Parser* p)
{
  assert(p->hasMoreCommands && "parser_command_type() called, but the parser has no current command");

  switch (p->currCommand[0])
  {
    case '@': return A_COMMAND;
    case '(': return L_COMMAND;
    default : return C_COMMAND;
  }
}

char* parser_symbol(Parser* p)
{
  CommandType ct = parser_command_type(p);
  assert(ct != C_COMMAND && "parser_symbol() can only be called if the current command is of type A_COMMAND or L_COMMAND");

  size_t len = strlen(p->currCommand) + 1 ;
  char* symbol = xmalloc(len);

  if (ct == L_COMMAND)
  {
    if (p->currCommand[len - 2] != ')' || len < 4)
    {
      fprintf(stderr, "Error at line %d: Invalid L_COMMAND format: %s\n", p->currLine, p->currCommand);
      exit(1);
    }
    memcpy(symbol, p->currCommand + 1, len - 2);
    symbol[len - 3] = '\0';
  }
  else if (ct == A_COMMAND)
  {
    if (len < 3)
    {
      fprintf(stderr, "Error at line %d: Invalid A_COMMAND format: %s\n", p->currLine, p->currCommand);
      exit(1);
    }
    memcpy(symbol, p->currCommand + 1, len - 1);
    symbol[len - 2] = '\0';
  }
  else
  {
    assert(0 && "Unexpected command type at parser_symbol()");
  }

  return symbol;
}

char* parser_dest(Parser* p)
{
  CommandType ct = parser_command_type(p);
  assert(ct == C_COMMAND && "parser_dest() can only be called if the current command is of type C_COMMAND");

  int pos = -1; // end idx (position of '\0')
  int i = 0;
  while (p->currCommand[i] != '\0')
  {
    if (p->currCommand[i] == '=')
    {
      pos = i;
      break;
    }
    ++i;
  }

  if (pos == -1) return NULL; // null dest

  char* dest = (char*)xmalloc(pos+1);
  memcpy(dest, p->currCommand, pos+1);
  dest[pos] = '\0';

  return dest;
}

char* parser_comp(Parser* p)
{
  CommandType ct = parser_command_type(p);
  assert(ct == C_COMMAND && "parser_comp() can only be called if the current command is of type C_COMMAND");

  int s_pos = -1; // start idx
  int e_pos = -1; // end idx (position of '\0')
  int i = 0;
  while (p->currCommand[i] != '\0')
  {
    if (p->currCommand[i] == '=') s_pos = i+1;
    if (p->currCommand[i] == ';') 
    {
      e_pos = i;
      break;
    }
    ++i;
  }

  if (s_pos == -1) s_pos = 0;
  if (e_pos == -1) e_pos = strlen(p->currCommand) + 1;

  size_t len = e_pos - s_pos + 1;
  char* comp = (char*)xmalloc(len);
  memcpy(comp, p->currCommand + s_pos, len);
  comp[len - 1] = '\0';

  return comp;
}

char* parser_jump(Parser* p)
{
  CommandType ct = parser_command_type(p);
  assert(ct == C_COMMAND && "parser_jump() can only be called if the current command is of type C_COMMAND");

  int pos = -1; // start idx
  int i = 0;
  while (p->currCommand[i] != '\0')
  {
    if (p->currCommand[i] == ';')
    {
      pos = i + 1;
      break;
    }
    ++i;
  }

  if (pos == -1) return NULL; // null jump

  size_t len = strlen(p->currCommand) + 1 - pos;
  char* jmp = (char*)xmalloc(len);
  memcpy(jmp, p->currCommand + pos, len);
  jmp[len - 1] = '\0';

  return jmp;
}

void parser_reset(Parser* p)
{
  fseek(p->file, 0, SEEK_SET);
  p->hasMoreCommands = 1;
  p->currLine = 0;
  p->currCommand = NULL;
  parser_advance(p);
}