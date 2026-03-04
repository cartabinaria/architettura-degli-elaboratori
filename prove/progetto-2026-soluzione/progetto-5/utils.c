#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void* xmalloc(size_t size)
{
  void* p = malloc(size);
  if (!p)
  {
    fprintf(stderr, "Error: out of memory allocatinng %zu bytes of memory", size);
    exit(1);
  }

  return p;
}

int check_extension(const char* fileName, const char* ext)
{
  char* dot = strrchr(fileName, '.');

  if (dot == NULL) return 0; // false

  int startEx = dot - fileName + 1;
  int i = startEx;
  while (fileName[i] != 0 && ext[i - startEx] != 0)
  {
    if (fileName[i] != ext[i - startEx]) return 0; // false

    ++i;
  }

  if (fileName[i] != 0 || ext[i - startEx] != 0) return 0; // false

  return 1; // true
}

char* generate_out_name(const char* fileName)
{
  const char* ext = ".hack";
  const char* dot = strrchr(fileName, '.');

  size_t baseLen = (dot != NULL ? (size_t)(dot - fileName) : strlen(fileName));

  char* out = (char*)xmalloc(baseLen + strlen(ext) + 1);

  memcpy(out, fileName, baseLen);
  out[baseLen] = '\0';

  strcat(out, ext);

  return out;
}

int is_numeric(const char* s) 
{
  if (s == NULL || *s == '\0')  // stringa vuota o NULL -> non valida
    return 0;

  for (int i = 0; s[i] != '\0'; i++) 
  {
    if (!isdigit((unsigned char)s[i]))
      return 0;
  }
  return 1;
}


