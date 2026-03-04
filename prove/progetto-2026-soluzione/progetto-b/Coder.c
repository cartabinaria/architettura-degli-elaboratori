#include "Coder.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

Coder* coder_init(FILE* outputFile)
{
  if (!outputFile) return NULL;
  
  Coder* cod = xmalloc(sizeof(Coder));
  cod->outputFile = outputFile;
  cod->uniqueId = 0;
  cod->currentFunction = NULL;

  cod->fileName = xstrdup("bootstrap");

  return cod;
}

void coder_free(Coder* cod)
{
  if (!cod) return;
  free(cod->fileName);
  free(cod->currentFunction);
  free(cod);
}

void coder_update_fileName(Coder* cod, const char* name)
{
  if (!cod || !name) return;

  char* newName = xstrdup(name);
  free(cod->fileName);
  cod->fileName = newName;
}

void coder_update_functionName(Coder* cod, const char* name)
{
  if (!cod || !name) return;

  char* newName = xstrdup(name);

  free(cod->currentFunction);
  cod->currentFunction = newName;
}

static void write_general_compare(Coder* cod, const char* jump)
{
  // return address in R13

  fprintf(cod->outputFile, "($%s$)\n", jump);      // crea label generale
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n");  // pop in D
  fprintf(cod->outputFile, "A=A-1\nD=M-D\n");      // metto la differenza degli argomenti in D (x - y)
  fprintf(cod->outputFile, "@SP\nA=M-1\nM=-1\n");  // metto -1 (true) sullo stack
  fprintf(cod->outputFile, "@R13\nA=M\n");         // setto l'indirizzo di ritorno salvato in R13
  fprintf(cod->outputFile, "D;J%s\n", jump);       // se il controllo passa, salto lasciando true sullo stack 
  fprintf(cod->outputFile, "@SP\nA=M-1\nM=0\n");   // altrimento metto false (0)
  fprintf(cod->outputFile, "@R13\nA=M\n0;JMP\n");  // salto all'indirizzo salvato in R13
}

static void write_general_return(Coder* cod)
{
  fprintf(cod->outputFile, "($RETURN$)\n");                            // crea label generale
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

static void write_push_address(Coder* cod, const char* adr)
{
  fprintf(cod->outputFile, "@%s\nD=M\n", adr);           // slava in D l'indirizzo in adr
  fprintf(cod->outputFile, "@SP\nAM=M+1\nA=A-1\nM=D\n"); // effettua il push e incrementa SP
}

static void write_general_call(Coder* cod)
{
  // indirizzo funzione chiamata in R13
  // nArgs in R14
  // return address in R15

  fprintf(cod->outputFile, "($CALL$)\n");                // crea label generale
  fprintf(cod->outputFile, "@R15\nD=M\n");               // slava in D l'indirizzo del return
  fprintf(cod->outputFile, "@SP\nAM=M+1\nA=A-1\nM=D\n"); // effettua il push e incrementa SP
  write_push_address(cod, "LCL");                        // push LCL
  write_push_address(cod, "ARG");                        // push ARG
  write_push_address(cod, "THIS");                       // push THIS
  write_push_address(cod, "THAT");                       // push THAT
  fprintf(cod->outputFile, "@R14\nD=M\n@5\nD=D+A\n");    // D = offset = nArgs + 5;
  fprintf(cod->outputFile, "@SP\nD=M-D\n");              // salvo in D SP-n-5
  fprintf(cod->outputFile, "@ARG\nM=D\n");               // aggiorno ARG -> ARG = SP-n-5
  fprintf(cod->outputFile, "@SP\nD=M\n@LCL\nM=D\n");     // LCL = SP
  fprintf(cod->outputFile, "@R13\nA=M\n0;JMP\n");        // salto alla funzione chiamata 
}

void coder_write_start(Coder* cod)
{
  // inizializzazione di SP a 256
  fprintf(cod->outputFile, "@256\nD=A\n@SP\nM=D\n"); 

  // call di Sys.init
  coder_write_call(cod, "Sys.init", 0);

  // codice unico per i return
  write_general_return(cod);

  // codice unico per i compare
  write_general_compare(cod, "GT");
  write_general_compare(cod, "LT");
  write_general_compare(cod, "EQ");

  // codice unico per l'inizializzazione delle chiamate a funzione
  write_general_call(cod);
}

static void write_binary(Coder* cod, char opSymbol)
{
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n");   // pop del secondo argomento in D
  fprintf(cod->outputFile, "A=A-1\n");              // decremento indirizzo per accedere al primo argomento
  // salvo il risultato dell'operazione al posto del primo argomento (SP decrementato solo di 1)
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
  fprintf(cod->outputFile, "@$COMPARE_LABEL_%d$\n", cod->uniqueId);  // label unica
  fprintf(cod->outputFile, "D=A\n@13\nM=D\n");                       // salva indirizzo di ritorno in R13 
  fprintf(cod->outputFile, "@$%s$\n0;JMP\n", jump);                  // salta alla label generale       
  fprintf(cod->outputFile, "($COMPARE_LABEL_%d$)\n",cod->uniqueId);

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

  else if (strcmp(op, "eq")  == 0) write_compare(cod, "EQ");
  else if (strcmp(op, "gt")  == 0) write_compare(cod, "GT");
  else if (strcmp(op, "lt")  == 0) write_compare(cod, "LT");

  else return false;

  return true;
}

// Scrive il codice per salvare in A l'indirizzo del segmento in cui voglio fare push/pop
static bool write_segment_address(Coder* cod, const char* segment, int addr)
{
  if (addr < 0) return false;

  if (strcmp(segment, "constant") == 0) 
  {
    fprintf(cod->outputFile, "@%d\n", addr);
    return true; 
  }
  else if (strcmp(segment, "static") == 0)
  {
    fprintf(cod->outputFile, "@%s.%d\n", cod->fileName, addr);
    fprintf(cod->outputFile, "D=M\n");
    return true;
  }
  else if (strcmp(segment, "pointer") == 0)
  {
    if (addr > 1) return false;

    fprintf(cod->outputFile, "@%d\n", 3 + addr);
    return true;
  }
  else if (strcmp(segment, "temp") == 0)
  {
    if (addr > 7) return false;

    fprintf(cod->outputFile, "@%d\n", 5 + addr);
    return true;
  }

  const char* base = 
    (strcmp(segment, "local")    == 0) ? "LCL" :
    (strcmp(segment, "argument") == 0) ? "ARG" :
    (strcmp(segment, "this")     == 0) ? "THIS" :
    (strcmp(segment, "that")     == 0) ? "THAT" : "";

  if (base[0] == '\0') // segmento insesistente 
  {
    return false;
  }

  fprintf(cod->outputFile, "@%d\nD=A\n", addr);   // metto l'offset in D
  fprintf(cod->outputFile, "@%s\nA=D+M\n", base); // A = indirizzo base + offset

  return true;
}

bool coder_write_push(Coder* cod, const char* segment, int addr)
{
  if (!write_segment_address(cod, segment, addr)) return false;
  
  if (strcmp(segment, "constant") == 0) 
    fprintf(cod->outputFile, "D=A\n");   // per constant A contiene il valore
  else
    fprintf(cod->outputFile, "D=M\n");   // per gli altri A contiene l'indirizzo del valore

  fprintf(cod->outputFile, "@SP\nAM=M+1\nA=A-1\nM=D\n"); // effettua il push e incrementa SP

  return true;
}

bool coder_write_pop(Coder* cod, const char* segment, int addr)
{
  if (strcmp(segment, "constant") == 0) return false; // non si può fare pop constant
  if (!write_segment_address(cod, segment, addr)) return false;

  fprintf(cod->outputFile, "D=A\n@R13\nM=D\n");   // salvo l'indirizzo in cui fare il pop in R13
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n"); // pop del valore in D
  fprintf(cod->outputFile, "@R13\nA=M\nM=D\n");   // copio il valore salvato in D nell'indirizzo giusto

  return true;
}

bool coder_write_function(Coder* cod, const char* name, int nLocals)
{
  if (nLocals < 0) return false;

  coder_update_functionName(cod, name);

  fprintf(cod->outputFile, "(%s)\n", name); // label per il nome della funzione

  // inizializzazione delle variabili locali a 0
  for (int i = 0; i < nLocals; ++i)
  {
    fprintf(cod->outputFile, "@SP\nAM=M+1\nA=A-1\nM=0\n"); // effettua il push di 0 e incrementa SP 
  }

  return true;
}

bool coder_write_call(Coder* cod, const char* name, int nArgs)
{
  if (nArgs < 0) return false;

  fprintf(cod->outputFile, "@$RETURN_LABEL_%d$\n", cod->uniqueId);
  fprintf(cod->outputFile, "D=A\n@15\nM=D\n");                          // salva in R15 l'indirizzo del return
  fprintf(cod->outputFile, "@%d\nD=A\n@R14\nM=D\n", nArgs);             // salva il numero di argomenti in R14
  fprintf(cod->outputFile, "@%s\nD=A\n@R13\nM=D\n", name);              // slava in R13 l'indirizzo della funzione
  fprintf(cod->outputFile, "@$CALL$\n0;JMP\n");                         // salta alla label generale       
  fprintf(cod->outputFile, "($RETURN_LABEL_%d$)\n", cod->uniqueId);     // label per il return

  cod->uniqueId++;

  return true;
}

void coder_write_label(Coder* cod, const char* label)
{
  const char* f = cod->currentFunction ? cod->currentFunction : cod->fileName;
  fprintf(cod->outputFile, "(%s$%s)\n", f, label);
}

void coder_write_goto(Coder* cod, const char* label)
{
  const char* f = cod->currentFunction ? cod->currentFunction : cod->fileName;
  fprintf(cod->outputFile, "@%s$%s\n0;JMP\n", f, label);
}

void coder_write_if(Coder* cod, const char* label)
{
  const char* f = cod->currentFunction ? cod->currentFunction : cod->fileName;
  fprintf(cod->outputFile, "@SP\nAM=M-1\nD=M\n");
  fprintf(cod->outputFile, "@%s$%s\nD;JNE\n", f, label);
}

void coder_write_return(Coder* cod)
{
  fprintf(cod->outputFile, "@$RETURN$\n0;JMP\n"); // salta al codice unico per il return
}
