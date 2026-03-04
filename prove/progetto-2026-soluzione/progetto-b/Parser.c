#include "CommandType.h"
#include "Parser.h"
#include "utils.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Parser* parser_init(FILE* file)
{
  Parser* p = xmalloc(sizeof(Parser));

  p->file = file;
  p->hasMoreCommands = true;
  p->currLine = 0;
  p->currCommand = NULL;

  parser_advance(p);
  return p;
}

void parser_free(Parser* p)
{
  if (p == NULL) return;
  if (p->file) rewind(p->file);
  free(p->currCommand);
  free(p);
}

static char* clean_line(char* line)
{
  if (!line) return NULL;

  char* cleaned = xmalloc(strlen(line) + 1);
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
  cleaned[j] = '\0';
  return cleaned;
}

void parser_advance(Parser* p)
{
  if (!p->hasMoreCommands) return;

  char* line = NULL;
  size_t len = 0;

  free(p->currCommand);
  p->currCommand = NULL;

  while (1) 
  {
    if (getline(&line, &len, p->file) == -1) 
    {
      free(line);
      p->hasMoreCommands = false;
      return;
    }

    char* cleaned = clean_line(line);
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

static char* get_token_n(const char* str, int n)
{
  if (!str || n <= 0) return NULL;

  size_t i = 0;

  // salta spazi iniziali -> non dovrebbero essercene, ma utile per sicurezza
  while (str[i] && isspace((unsigned char)str[i])) i++;

  // avanza fino all'n-esimo token, se non ce ne sono abbastanza -> NULL
  for (int k = 1; k < n; k++) 
  {
    // consuma la parola corrente
    while (str[i] && !isspace((unsigned char)str[i])) i++;
    if (!str[i]) return NULL;

    // consuma gli spazi
    while (str[i] && isspace((unsigned char)str[i])) i++;
    if (!str[i]) return NULL;
  }

  size_t start = i;

  while (str[i] && !isspace((unsigned char)str[i])) i++;

  size_t tokenLen = i - start;
  if (tokenLen == 0) return NULL;

  char* token = xmalloc(tokenLen + 1);
  memcpy(token, str + start, tokenLen);
  token[tokenLen] = '\0';

  return token;
}

CommandType parser_command_type(Parser* p)
{
  assert(p->hasMoreCommands && "Parser_command_type() called, but the parser has no current command");

  char* command = get_token_n(p->currCommand, 1);
  assert(command && "Unexpected command not found at parser_command_type()");

  CommandType type;

  if      (strcmp(command, "push")     == 0) type = C_PUSH;
  else if (strcmp(command, "pop")      == 0) type = C_POP;
  else if (strcmp(command, "label")    == 0) type = C_LABEL;
  else if (strcmp(command, "goto")     == 0) type = C_GOTO;
  else if (strcmp(command, "if-goto")  == 0) type = C_IF;
  else if (strcmp(command, "function") == 0) type = C_FUNCTION;
  else if (strcmp(command, "call")     == 0) type = C_CALL;
  else if (strcmp(command, "return")   == 0) type = C_RETURN;

  else if (strcmp(command, "add") == 0 ||
           strcmp(command, "sub") == 0 ||
           strcmp(command, "neg") == 0 ||
           strcmp(command, "eq")  == 0 ||
           strcmp(command, "gt")  == 0 ||
           strcmp(command, "lt")  == 0 ||
           strcmp(command, "and") == 0 ||
           strcmp(command, "or")  == 0 || 
           strcmp(command, "not") == 0) type = C_ARITHMETIC;

  else type = C_NULL;

  free(command);
  return type;
}

char* parser_arg1(Parser* p)
{
  CommandType type = parser_command_type(p);

  if (type == C_NULL)
  {
    fprintf(stderr, "Error at line %d: Unknown command: %s\n", p->currLine, p->currCommand);
    return NULL;
  }

  assert(type != C_RETURN && "parser_arg1() should not be called if the current command is C_RETURN");

  char* arg = NULL;

  // Per arithmetic, return il comando stesso
  if (type == C_ARITHMETIC) arg = get_token_n(p->currCommand, 1);
  // Per gli altri comandi, return del primo argomento
  else arg = get_token_n(p->currCommand, 2);

  if (!arg)
  {
    fprintf(stderr, "Error at line %d: Command has insufficient arguments: %s\n", p->currLine, p->currCommand);
    return NULL;
  }

  return arg;
}

int parser_arg2(Parser* p)
{
  CommandType type = parser_command_type(p);

  if (type == C_NULL)
  {
    fprintf(stderr, "Error at line %d: Unknown command: %s\n", p->currLine, p->currCommand);
    return -1;
  }

  assert(type != C_RETURN && type != C_IF && 
         type != C_GOTO && type != C_ARITHMETIC && type != C_LABEL && 
         "parser_arg2() should only be called for C_PUSH, C_POP, C_FUNCTION, or C_CALL commands");

  char* arg = get_token_n(p->currCommand, 3);

  if (!arg)
  {
    fprintf(stderr, "Error at line %d: Command has insufficient arguments: %s\n", p->currLine, p->currCommand);
    return -1;
  }

  int value;
  if (!parse_int(arg, &value)) 
  {
    fprintf(stderr, "Error at line %d: Argument 2 is not a valid int: %s\n", p->currLine, p->currCommand);
    free(arg);
    return -1;
  }
  
  free(arg);

  if (value < 0)
  {
    fprintf(stderr, "Error at line %d: Argument 2 can't be negative: %s\n", p->currLine, p->currCommand);
    return -1;
  }

  return value;
}
