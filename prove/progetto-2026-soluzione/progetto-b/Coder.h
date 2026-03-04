#ifndef CODER_H
#define CODER_H

#include <stdbool.h>
#include <stdio.h>

typedef struct
{
  char* fileName;
  char* currentFunction;
  FILE* outputFile;
  int uniqueId;
} Coder;

Coder* coder_init(FILE* outputFile);
void coder_free(Coder* cod);
void coder_update_fileName(Coder* cod, const char* name);
void coder_update_functionName(Coder* cod, const char* name);
void coder_write_start(Coder* cod);
bool coder_write_arithmetic(Coder* cod, const char* op);
bool coder_write_push(Coder* cod, const char* segment, int addr);
bool coder_write_pop(Coder* cod, const char* segment, int addr);
bool coder_write_function(Coder* cod, const char* name, int nLocals);
bool coder_write_call(Coder* cod, const char* name, int nArgs);
void coder_write_label(Coder* cod, const char* label);
void coder_write_goto(Coder* cod, const char* label);
void coder_write_if(Coder* cod, const char* label);
void coder_write_return(Coder* cod);

#endif