#include "Assembler.h"
#include "Coder.h"
#include "Parser.h"
#include "Map.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Assembler* assembler_init(FILE* inputFile, FILE* outputFile)
{
  Assembler* asmr = (Assembler*)xmalloc(sizeof(Assembler));

  asmr->inputFile = inputFile;
  asmr->outputFile = outputFile;
  asmr->parser = parser_init(inputFile);
  asmr->nextVariableAddress = 16;
  asmr->symbolTable = map_init();

  map_push(asmr->symbolTable, "R0", 0);
  map_push(asmr->symbolTable, "R1", 1);
  map_push(asmr->symbolTable, "R2", 2);
  map_push(asmr->symbolTable, "R3", 3);
  map_push(asmr->symbolTable, "R4", 4);
  map_push(asmr->symbolTable, "R5", 5);
  map_push(asmr->symbolTable, "R6", 6);
  map_push(asmr->symbolTable, "R7", 7);
  map_push(asmr->symbolTable, "R8", 8);
  map_push(asmr->symbolTable, "R9", 9);
  map_push(asmr->symbolTable, "R10", 10);
  map_push(asmr->symbolTable, "R11", 11);
  map_push(asmr->symbolTable, "R12", 12);
  map_push(asmr->symbolTable, "R13", 13);
  map_push(asmr->symbolTable, "R14", 14);
  map_push(asmr->symbolTable, "R15", 15);
  map_push(asmr->symbolTable, "SP", 0);
  map_push(asmr->symbolTable, "LCL", 1);
  map_push(asmr->symbolTable, "ARG", 2);
  map_push(asmr->symbolTable, "THIS", 3);
  map_push(asmr->symbolTable, "THAT", 4);
  map_push(asmr->symbolTable, "SCREEN", 16384);
  map_push(asmr->symbolTable, "KBD", 24576);

  return asmr;
}

void assembler_parse_labels(Assembler* asmr)
{
  int addressCounter = 0;
  while (asmr->parser->hasMoreCommands)
  {
    CommandType ct = parser_command_type(asmr->parser);
    if (ct == L_COMMAND)
    {
      char* symbol = parser_symbol(asmr->parser);
      if (map_get(asmr->symbolTable, symbol) == -1)
      {
        map_push(asmr->symbolTable, symbol, addressCounter);
      }
      else
      {
        fprintf(stderr, "Error at line %d: Invalid L_COMMAND (Duplicate symbol found): %s\n", asmr->parser->currLine, asmr->parser->currCommand);
        exit(1);
      }
      free(symbol);
    }
    else  
      addressCounter++;

    parser_advance(asmr->parser);
  }
  parser_reset(asmr->parser);
}

void assembler_generate(Assembler* asmr)
{
  assembler_parse_labels(asmr);

  while (asmr->parser->hasMoreCommands)
  {
    CommandType ct = parser_command_type(asmr->parser);
    switch (ct)
    {
    case L_COMMAND:
      break;
    
    case A_COMMAND:
    {
      char* symbol = parser_symbol(asmr->parser);
      char* bin = NULL;
      if (!is_numeric(symbol))
      {
        int n = map_get(asmr->symbolTable, symbol);
        if (n == -1)
        {
          map_push(asmr->symbolTable, symbol, asmr->nextVariableAddress);
          n = asmr->nextVariableAddress;
          asmr->nextVariableAddress++;
        }
        bin = coder_number(n);
      }
      else
      {
        int n = strtol(symbol, NULL, 10);
        bin = coder_number(n);    
      }

      if (!bin)
      {
        fprintf(stderr, "Error at line %d: Invalid A_COMMAND: %s\n", asmr->parser->currLine, asmr->parser->currCommand);
        exit(1);
      }
      fprintf(asmr->outputFile, "0%s\n", bin);
      free(bin);
      free(symbol);

      break;
    }
    case C_COMMAND:
    {
      char* dest = parser_dest(asmr->parser);
      char* comp = parser_comp(asmr->parser);
      char* jump = parser_jump(asmr->parser);
      char* code_dest = coder_dest(dest);
      if (!code_dest)
      {
        fprintf(stderr, "Error at line %d: Invalid dest: %s\n", asmr->parser->currLine, asmr->parser->currCommand);
        exit(1);
      }
      char* code_comp = coder_comp(comp);
      if (!code_comp)
      {
        fprintf(stderr, "Error at line %d: Invalid comp: %s\n", asmr->parser->currLine, asmr->parser->currCommand);
        exit(1);
      }
      char* code_jump = coder_jump(jump);
      if (!code_jump)
      {
        fprintf(stderr, "Error at line %d: Invalid jump: %s\n", asmr->parser->currLine, asmr->parser->currCommand);
        exit(1);
      }

      fprintf(asmr->outputFile, "111%s%s%s\n", code_comp, code_dest, code_jump);
      if (dest) free(dest);
      if (comp) free(comp);
      if (jump) free(jump);
      free(code_dest);
      free(code_comp);
      free(code_jump);

      break;
    }
    default:
      assert(0 && "Unexpected command type during assembly");
      break;
    }

    parser_advance(asmr->parser);
  }
}

void assembler_free(Assembler* asmr)
{
  if (asmr == NULL) return;

  if (asmr->parser != NULL) parser_free(asmr->parser);
  if (asmr->symbolTable != NULL) map_free(asmr->symbolTable);
  free(asmr);
}