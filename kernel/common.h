#ifndef COMMON_H
#define COMMON_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>
int string_length(char* string);
void concatc(char* a, char b, char* c);
int string_compare(char* str1, char* str2);
#endif
