#include "utils.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* xmalloc(size_t size)
{
  void* p = malloc(size);
  if (!p)
  {
    fprintf(stderr, "Error: Out of memory allocatinng %zu bytes of memory\n", size);
    exit(1);
  }

  return p;
}

bool check_extension(const char* fileName, const char* ext)
{
  if (!fileName || !ext) return false;
  const char* dot = strrchr(fileName, '.');
  return dot && dot[1] && strcmp(dot + 1, ext) == 0;
}

char* get_base_name(const char* fileName)
{
  if (!fileName) return NULL;

  const char* path = strrchr(fileName, '/');
  const char* base = path ? path + 1 : fileName;

  const char* dot = strrchr(base, '.');

  size_t len = dot ? (size_t)(dot - base) : strlen(base);
  char* out = xmalloc(len + 1);
  memcpy(out, base, len);
  out[len] = '\0';
  return out;
}

char* generate_out_name(const char* fileName, const char* outExt)
{
  if (!fileName || !outExt) return NULL;

  const char* slash = strrchr(fileName, '/');
  const char* base  = slash ? slash + 1 : fileName;

  const char* dot = strrchr(base, '.');
  if (!dot) return NULL;

  size_t prefixLen = (size_t)(dot - fileName) + 1;
  char* out = xmalloc(prefixLen + strlen(outExt) + 1);

  memcpy(out, fileName, prefixLen);
  out[prefixLen] = '\0';
  strcat(out, outExt);
  return out;
}

bool parse_int_strict(const char* s, int* out)
{
  if (!s || !out) return false;

  errno = 0;
  char* end = NULL;
  long v = strtol(s, &end, 10);

  if (end == s) return false;

  while (*end && isspace((unsigned char)*end)) end++;

  if (*end != '\0') return false;

  if (errno == ERANGE || v < INT_MIN || v > INT_MAX) return false;

  *out = (int)v;
  return true;
}