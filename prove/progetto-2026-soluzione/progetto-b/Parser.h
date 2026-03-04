#ifndef PARSER_H
#define PARSER_H

#include "CommandType.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct 
{
  FILE* file;
  char* currCommand;
  int currLine;
  bool hasMoreCommands;
} Parser;

Parser* parser_init(FILE* file);
void parser_free(Parser* p);
void parser_advance(Parser* p);
CommandType parser_command_type(Parser* p);
char* parser_arg1(Parser* p);
int parser_arg2(Parser* p);

#endif