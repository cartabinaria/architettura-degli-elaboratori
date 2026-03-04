#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

void* xmalloc(size_t size);
int check_extension(const char* fileName, const char* ext);
char* generate_out_name(const char* fileName);
int is_numeric(const char* s) ;

#endif