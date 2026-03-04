#include "Coder.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

Coder* coder_init(FILE* outputFile, const char* fileName)
{
  Coder* cod = (Coder*)xmalloc(sizeof(Coder));
  cod->outputFile = outputFile;
  cod->uniqueId = 0;

  cod->fileName = (char*)xmalloc(strlen(fileName) + 1);
  strcpy(cod->fileName, fileName);

  return cod;
}

void coder_free(Coder* cod)
{
  if (!cod) return;
  if (cod->fileName) free(cod->fileName);
  free(cod);
}

void coder_write_start(Coder* cod)
{
  fprintf(cod->outputFile, "@256\nD=A\n@SP\nM=D\n"); // inizializza SP a 256
}

static void write_binary(Coder* cod, char opSymbol)
{
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n");   // pop del secondo argomento in D
  fprintf(cod->outputFile, "A=A-1\n");              // decremento indirizzo per accedere al primo argomento
  // salvo il risultato dell'operazione in M, al posto del primo argomento (SP decrementato solo di 1)
  if (opSymbol == '-')
    fprintf(cod->outputFile, "M=M-D\n");            // in caso di - dobbiamo fare M-D (diverso da D-M)
  else
    fprintf(cod->outputFile, "M=D%cM\n", opSymbol); // caso generale: D op M (tutti gli operatori sono commutativi)
}

static void write_unary(Coder* cod, char opSymbol)
{
  fprintf(cod->outputFile, "@SP\nA=M-1\n");      // ottengo indirizzo valore
  fprintf(cod->outputFile, "M=%cM\n", opSymbol); // M = op M (operatore unario su M)
}

static void write_compare(Coder* cod, const char* jump)
{
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n");  // pop in D
  fprintf(cod->outputFile, "A=A-1\nD=M-D\n");      // metto la differenza degli argomenti in D (x - y)
  fprintf(cod->outputFile, "@SP\nA=M-1\nM=-1\n");  // metto -1 (true) sullo stack
  fprintf(cod->outputFile, "@$COMPARE_LABEL_%d$\n", cod->uniqueId); // label unica
  fprintf(cod->outputFile, "D;%s\n", jump);        // se il controllo passa, salto lasciando true sullo stack 
  fprintf(cod->outputFile, "@SP\nA=M-1\nM=0\n");   // altrimento metto false (0)
  fprintf(cod->outputFile, "($COMPARE_LABEL_%d$)\n", cod->uniqueId); // label
  cod->uniqueId++;
}

bool coder_write_arithmetic(Coder* cod, const char* op)
{
  if      (strcmp(op, "add") == 0) write_binary(cod, '+');
  else if (strcmp(op, "sub") == 0) write_binary(cod, '-');
  else if (strcmp(op, "and") == 0) write_binary(cod, '&');
  else if (strcmp(op, "or")  == 0) write_binary(cod, '|');

  else if (strcmp(op, "neg") == 0) write_unary(cod, '-');
  else if (strcmp(op, "not") == 0) write_unary(cod, '!');

  else if (strcmp(op, "eq")  == 0) write_compare(cod, "JEQ");
  else if (strcmp(op, "gt")  == 0) write_compare(cod, "JGT");
  else if (strcmp(op, "lt")  == 0) write_compare(cod, "JLT");

  else return false;

  return true;
}

bool coder_write_push(Coder* cod, const char* segment, int addr)
{
  if (addr < 0) return false;

  if (strcmp(segment, "constant") == 0) 
  {
    fprintf(cod->outputFile, "@%d\n", addr);
    fprintf(cod->outputFile, "D=A\n");
  }
  else if (strcmp(segment, "static") == 0)
  {
    fprintf(cod->outputFile, "@%s.%d\n", cod->fileName, addr);
    fprintf(cod->outputFile, "D=M\n");
  }
  else if (strcmp(segment, "local") == 0)
  {
    fprintf(cod->outputFile, "@%d\n", addr);
    fprintf(cod->outputFile, "D=A\n");              // metto l'offset in D
    fprintf(cod->outputFile, "@LCL\nA=D+M\nD=M\n"); // A = indirizzo base LCL + offset, salvo in D
  }
  else if (strcmp(segment, "argument") == 0)
  {
    fprintf(cod->outputFile, "@%d\n", addr);
    fprintf(cod->outputFile, "D=A\n");               // metto l'offset in D
    fprintf(cod->outputFile, "@ARG\nA=D+M\nD=M\n");  // A = indirizzo base ARG + offset, salvo in D
  }
  else
  {
    return false;
  }

  fprintf(cod->outputFile, "@SP\nA=M\nM=D\n"); // effettua il push del valore messo in D
  fprintf(cod->outputFile, "@SP\nM=M+1\n");    // incrementa lo SP

  return true;
}

bool coder_write_pop(Coder* cod, const char* segment, int addr)
{
  if (addr < 0) return false;

  if (strcmp(segment, "constant") == 0) return false;
  
  else if (strcmp(segment, "static") == 0)
  {
    fprintf(cod->outputFile, "@%s.%d\n", cod->fileName, addr);
  }
  else if (strcmp(segment, "local") == 0)
  {
    fprintf(cod->outputFile, "@%d\n", addr);
    fprintf(cod->outputFile, "D=A\n");         // metto l'offset in D
    fprintf(cod->outputFile, "@LCL\nA=D+M\n"); // A = indirizzo base LCL + offset
  }
  else if (strcmp(segment, "argument") == 0)
  {
    fprintf(cod->outputFile, "@%d\n", addr);
    fprintf(cod->outputFile, "D=A\n");          // metto l'offset in D
    fprintf(cod->outputFile, "@ARG\nA=D+M\n");  // A = indirizzo base ARG + offset
  }
  else
  {
    return false;
  }

  fprintf(cod->outputFile, "D=A\n@R13\nM=D\n");   // salvo l'indirizzo in cui fare il pop in R13
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n"); // pop del valore in D
  fprintf(cod->outputFile, "@R13\nA=M\nM=D\n");   // copio il valore salvato in D nell'indirizzo giusto

  return true;
}

bool coder_write_function(Coder* cod, const char* name, int nLocals)
{
  if (nLocals < 0) return false;

  fprintf(cod->outputFile, "(%s)\n", name); // label per il nome della funzione

  // inizializzazione delle variabili locali a 0
  for (int i = 0; i < nLocals; ++i)
  {
    fprintf(cod->outputFile, "@SP\nA=M\nM=0\n"); // effettua il push di 0
    fprintf(cod->outputFile, "@SP\nM=M+1\n");    // incrementa lo SP
  }

  return true;
}

static void write_push_address(Coder* cod, const char* adr)
{
  fprintf(cod->outputFile, "@%s\nD=M\n", adr); // slava in D l'indirizzo in adr
  fprintf(cod->outputFile, "@SP\nA=M\nM=D\n"); // effettua il push dell'indirizzo
  fprintf(cod->outputFile, "@SP\nM=M+1\n");    // incrementa lo SP
}

bool coder_write_call(Coder* cod, const char* name, int nArgs)
{
  if (nArgs < 0) return false;

  fprintf(cod->outputFile, "@$RETURN_LABEL_%d$\nD=A\n", cod->uniqueId); // slava in D l'indirizzo di ritorno
  fprintf(cod->outputFile, "@SP\nA=M\nM=D\n"); // effettua il push dell'indirizzo di ritorno
  fprintf(cod->outputFile, "@SP\nM=M+1\n");    // incrementa lo SP

  write_push_address(cod, "LCL");
  write_push_address(cod, "ARG");
  write_push_address(cod, "THIS");
  write_push_address(cod, "THAT");

  int offset = nArgs + 5;

  fprintf(cod->outputFile, "@%d\nD=A\n", offset);    // salvo in D l'offset
  fprintf(cod->outputFile, "@SP\nD=M-D\n");          // salvo in D SP-n-5
  fprintf(cod->outputFile, "@ARG\nM=D\n");           // aggiorno ARG

  fprintf(cod->outputFile, "@SP\nD=M\n@LCL\nM=D\n"); // LCL = SP

  fprintf(cod->outputFile, "@%s\n0;JMP\n", name);    // salta alla funzione

  fprintf(cod->outputFile, "($RETURN_LABEL_%d$)\n", cod->uniqueId); // label per il return
  cod->uniqueId++;

  return true;
}

void coder_write_label(Coder* cod, const char* label)
{
  fprintf(cod->outputFile, "(%s)\n", label); 
}

void coder_write_goto(Coder* cod, const char* label)
{
  fprintf(cod->outputFile, "@%s\n", label); 
  fprintf(cod->outputFile, "0;JMP\n");
}

void coder_write_if(Coder* cod, const char* label)
{
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n"); // pop dello stack in D
  fprintf(cod->outputFile, "@%s\n", label); 
  fprintf(cod->outputFile, "D;JNE\n");            // salta se il valore != 0 (false)
}

void coder_write_return(Coder* cod)
{
  fprintf(cod->outputFile, "@LCL\nD=M\n@R14\nM=D\n");                  // FRAME = LCL -> (FRAME è salvato in R14)
  fprintf(cod->outputFile, "@5\nD=A\n@R14\nA=M-D\nD=M\n@R15\nM=D\n");  // RET = *(FRAME - 5) -> (RET salvato in R15)
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n@ARG\nA=M\nM=D\n");      // posiziona il valore di ritorno: *ARG = pop()
  fprintf(cod->outputFile, "@ARG\nD=M+1\n@SP\nM=D\n");                 // SP = ARG + 1
  fprintf(cod->outputFile, "@R14\nA=M-1\nD=M\n@THAT\nM=D\n");          // THAT = *(FRAME - 1)
  fprintf(cod->outputFile, "@2\nD=A\n@R14\nA=M-D\nD=M\n@THIS\nM=D\n"); // THIS = *(FRAME - 2)
  fprintf(cod->outputFile, "@3\nD=A\n@R14\nA=M-D\nD=M\n@ARG\nM=D\n");  // ARG  = *(FRAME - 3)
  fprintf(cod->outputFile, "@4\nD=A\n@R14\nA=M-D\nD=M\n@LCL\nM=D\n");  // LCL  = *(FRAME - 4)
  fprintf(cod->outputFile, "@R15\nA=M\n0;JMP\n");                      // goto RET
}