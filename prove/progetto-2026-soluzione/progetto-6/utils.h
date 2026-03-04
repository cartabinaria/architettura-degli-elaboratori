#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

void* xmalloc(size_t size);
bool check_extension(const char* fileName, const char* ext);
char* get_base_name(const char* fileName);
char* generate_out_name(const char* fileName, const char* outExt);
bool parse_int_strict(const char* s, int* out);

#endif