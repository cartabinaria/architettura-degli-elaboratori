#ifndef VM_TRANSLATOR_H
#define VM_TRANSLATOR_H

#include "Coder.h"
#include "dataStructures.h"
#include <stdbool.h>
#include <stdio.h>

#define MAX_INPUT_FILES 100

typedef struct 
{
  FILE* inputFiles[MAX_INPUT_FILES];
  char* inputFileNames[MAX_INPUT_FILES];
  int numInputFiles;
  FILE* outputFile;
  Coder* coder;
  BstNode* callsCollector;
} VMtranslator;

VMtranslator* vmt_init(FILE* outputFile);
void vmt_free(VMtranslator* vmt);
bool vmt_collect_file(VMtranslator* vmt, FILE* file, const char* fileName);
bool vmt_translate_all(VMtranslator* vmt);

#endif