#ifndef VM_TRANSLATOR_H
#define VM_TRANSLATOR_H

#include "Parser.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct 
{
  char* fileName;
  FILE* inputFile;
  FILE* outputFile;
} VMtranslator;

VMtranslator* vmt_init(const char* fileName, FILE* inputFile, FILE* outputFile);
void vmt_free(VMtranslator* vmt);
bool vmt_generate(VMtranslator* vmt);

#endif