#ifndef PARSER_H
#define PARSER_H

#include "CommandType.h"
#include <stdio.h>

typedef struct 
{
  FILE* file;
  char* currCommand;
  int currLine;
  int hasMoreCommands;
} Parser;

Parser* parser_init(FILE* file);
void parser_free(Parser* p);
void parser_advance(Parser* p);
CommandType parser_command_type(Parser* p);
char* parser_symbol(Parser* p);
char* parser_dest(Parser* p);
char* parser_comp(Parser* p);
char* parser_jump(Parser* p);
void parser_reset(Parser* p);

#endif