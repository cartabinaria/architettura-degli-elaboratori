#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Parser.h"
#include "Map.h"
#include <stdio.h>

typedef struct
{
  FILE* inputFile;
  FILE* outputFile;
  Parser* parser;
  Map* symbolTable;
  int nextVariableAddress;
} Assembler;

Assembler* assembler_init(FILE* inputFile, FILE* outputFile);
void assembler_generate(Assembler* asmr);
void assembler_free(Assembler* asmr);

#endif