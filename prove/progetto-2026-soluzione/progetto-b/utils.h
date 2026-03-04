#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

void* xmalloc(size_t size);
char* xstrdup(const char* s);
bool is_dir(const char* path);
bool is_reg_file(const char* path);
bool check_extension(const char* fileName, const char* ext);
char* get_base_name(const char* fileName);
char* generate_out_name(const char* fileName, const char* outExt);
bool parse_int(const char* s, int* out);

#endif