#include "Coder.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* coder_dest(char* dest)
{
  char* code = (char*)xmalloc(4); 

  if      (dest == NULL)             strcpy(code, "000");
  else if (strcmp(dest, "M")   == 0) strcpy(code, "001");
  else if (strcmp(dest, "D")   == 0) strcpy(code, "010");
  else if (strcmp(dest, "A")   == 0) strcpy(code, "100");
  else if (strcmp(dest, "MD")  == 0) strcpy(code, "011");
  else if (strcmp(dest, "AM")  == 0) strcpy(code, "101");
  else if (strcmp(dest, "AD")  == 0) strcpy(code, "110");
  else if (strcmp(dest, "AMD") == 0) strcpy(code, "111");
  else
  {
    free(code);
    return NULL;
  }

  return code;
}

char* coder_comp(char* comp)
{
  char* code = (char*)xmalloc(8);

  if      (strcmp(comp, "0")   == 0) strcpy(code, "0101010");
  else if (strcmp(comp, "1")   == 0) strcpy(code, "0111111");
  else if (strcmp(comp, "-1")  == 0) strcpy(code, "0111010");
  else if (strcmp(comp, "D")   == 0) strcpy(code, "0001100");
  else if (strcmp(comp, "A")   == 0) strcpy(code, "0110000");
  else if (strcmp(comp, "!D")  == 0) strcpy(code, "0001101");
  else if (strcmp(comp, "!A")  == 0) strcpy(code, "0110001");
  else if (strcmp(comp, "-D")  == 0) strcpy(code, "0001111");
  else if (strcmp(comp, "-A")  == 0) strcpy(code, "0110011");
  else if (strcmp(comp, "D+1") == 0) strcpy(code, "0011111");
  else if (strcmp(comp, "A+1") == 0) strcpy(code, "0110111");
  else if (strcmp(comp, "D-1") == 0) strcpy(code, "0001110");
  else if (strcmp(comp, "A-1") == 0) strcpy(code, "0110010");
  else if (strcmp(comp, "D+A") == 0) strcpy(code, "0000010");
  else if (strcmp(comp, "D-A") == 0) strcpy(code, "0010011");
  else if (strcmp(comp, "A-D") == 0) strcpy(code, "0000111");
  else if (strcmp(comp, "D&A") == 0) strcpy(code, "0000000");
  else if (strcmp(comp, "D|A") == 0) strcpy(code, "0010101");
  else if (strcmp(comp, "M")   == 0) strcpy(code, "1110000");
  else if (strcmp(comp, "!M")  == 0) strcpy(code, "1110001");
  else if (strcmp(comp, "-M")  == 0) strcpy(code, "1110011");
  else if (strcmp(comp, "M+1") == 0) strcpy(code, "1110111");
  else if (strcmp(comp, "M-1") == 0) strcpy(code, "1110010");
  else if (strcmp(comp, "D+M") == 0) strcpy(code, "1000010");
  else if (strcmp(comp, "D-M") == 0) strcpy(code, "1010011");
  else if (strcmp(comp, "M-D") == 0) strcpy(code, "1000111");
  else if (strcmp(comp, "D&M") == 0) strcpy(code, "1000000");
  else if (strcmp(comp, "D|M") == 0) strcpy(code, "1010101");
  else 
  {
    free(code);
    return NULL;
  }

  return code;
}

char* coder_jump(char* jump)
{
  char* code = (char*)xmalloc(4);

  if      (jump == NULL)             strcpy(code, "000");
  else if (strcmp(jump, "JGT") == 0) strcpy(code, "001");
  else if (strcmp(jump, "JEQ") == 0) strcpy(code, "010");
  else if (strcmp(jump, "JGE") == 0) strcpy(code, "011");
  else if (strcmp(jump, "JLT") == 0) strcpy(code, "100");
  else if (strcmp(jump, "JNE") == 0) strcpy(code, "101");
  else if (strcmp(jump, "JLE") == 0) strcpy(code, "110");
  else if (strcmp(jump, "JMP") == 0) strcpy(code, "111");
  else 
  {
    free(code);
    return NULL;
  }

  return code;
}

char* coder_number(int n)
{
  if (n < 0 || n >= (1 << 15)) return NULL;

  char* bin = (char*)xmalloc(16);

  for (int i = 14; i >= 0; --i) 
  {
    bin[14 - i] = (n & (1 << i)) ? '1' : '0';
  }

  bin[15] = '\0';

  return bin;
}

