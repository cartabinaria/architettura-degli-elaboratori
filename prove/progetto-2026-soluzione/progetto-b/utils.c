#include "utils.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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

char* xstrdup(const char* s) 
{
  size_t n = strlen(s) + 1;
  char* p = xmalloc(n);
  memcpy(p, s, n);
  return p;
}

bool is_dir(const char* path) 
{
  struct stat st;
  if (stat(path, &st) != 0) return false;
  return S_ISDIR(st.st_mode) ? true : false;
}

bool is_reg_file(const char* path) 
{
  struct stat st;
  if (stat(path, &st) != 0) return false;
  return S_ISREG(st.st_mode) ? true : false;
}

bool check_extension(const char* fileName, const char* ext)
{
  if (!fileName || !ext) return false;
  const char* dot = strrchr(fileName, '.');
  return dot && dot[1] && strcmp(dot + 1, ext) == 0;
}

char* get_base_name(const char* path)
{
  if (!path) return NULL;

  const char* slash = strrchr(path, '/');
  const char* base = slash ? slash + 1 : path;

  const char* dot = strrchr(base, '.');

  size_t len = dot ? (size_t)(dot - base) : strlen(base);
  char* out = xmalloc(len + 1);
  memcpy(out, base, len);
  out[len] = '\0';
  return out;
}

char* generate_out_name(const char* path, const char* outExt)
{
  if (!path || !outExt) return NULL;

  size_t pathLen = strlen(path);
  if (pathLen == 0) return NULL;

  // Trim degli slash finali per le directory: "a/b///" -> "a/b"
  size_t trimmedLen = pathLen;
  while (trimmedLen > 0 && path[trimmedLen - 1] == '/') trimmedLen--;
  if (trimmedLen == 0) return NULL;

  char* trimmed = xmalloc(trimmedLen + 1);
  memcpy(trimmed, path, trimmedLen);
  trimmed[trimmedLen] = '\0';

  // --- Caso DIRECTORY: "<dir>/<base>.<outExt>"
  if (is_dir(trimmed)) 
  {
    const char* slash = strrchr(trimmed, '/');
    const char* base  = slash ? slash + 1 : trimmed;
    size_t baseLen = strlen(base);

    // out = trimmed + "/" + base + "." + outExt
    size_t outLen = trimmedLen + 1 + baseLen + 1 + strlen(outExt) + 1;
    char* out = xmalloc(outLen);

    snprintf(out, outLen, "%s/%s.%s", trimmed, base, outExt);

    free(trimmed);
    return out;
  }

  // --- Caso FILE REGOLARE: cambia estensione
  if (is_reg_file(trimmed)) 
  {
    const char* slash = strrchr(trimmed, '/');
    const char* base  = slash ? slash + 1 : trimmed;
    const char* dot   = strrchr(base, '.');

    if (dot) 
    {
      // sostituisco estensione: copio fino al '.' incluso
      size_t prefixLen = (size_t)(dot - trimmed) + 1;
      char* out = xmalloc(prefixLen + strlen(outExt) + 1);

      memcpy(out, trimmed, prefixLen);
      out[prefixLen] = '\0';
      strcat(out, outExt);

      free(trimmed);
      return out;
    } 
    else 
    {
      // niente estensione: aggiungo ".outExt"
      size_t outLen = trimmedLen + 1 + strlen(outExt) + 1;
      char* out = xmalloc(outLen);

      snprintf(out, outLen, "%s.%s", trimmed, outExt);

      free(trimmed);
      return out;
    }
  }

  free(trimmed);
  return NULL; // path invalido
}

bool parse_int(const char* s, int* out)
{
  if (!s || !out) return false;

  char* end = NULL;
  long v = strtol(s, &end, 10);

  if (end == s) return false;

  while (*end && isspace((unsigned char)*end)) end++;

  if (*end != '\0') return false;

  if (v < INT_MIN || v > INT_MAX) return false;

  *out = (int)v;
  return true;
}