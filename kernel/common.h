// common.h for all common tasks 
// Author: Jacob Mealey
//
// note some functions and blocks of code are from PortOS [https://github.com/MatthewGallant/PortOS] 
// and from CodeOS [https://github.com/Codepixl/CodeOS]

#ifndef COMMON_H
#define COMMON_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdbool.h> /* C doesn't have booleans by default. */

#include <stddef.h>
#include <stdint.h>

#include "vga.h"
#include "heap.h"

#define normal 0x0F
#define blue 0x01
#define green 0x02
#define cyan 0x03
#define red 0x04
#define purple 0x05
#define orange 0x06
#define light_grey 0x07
#define dark_grey 0x08
#define light_blue 0x09
#define light_green 0x0A
#define light_cyan 0x0B
#define light_red 0x0C
#define light_purple 0x0D
#define yellow 0x0E
#define normal_highlight 0xF0
#define blue_highlight 0xF1
#define green_highlight 0xF2
#define cyan_highlight 0xF3
#define red_highlight 0xF4
#define purple_highlight 0xF5
#define orange_highlight 0xF6
#define light_grey_highlight 0xF7
#define dark_grey_highlight 0xF8
#define light_blue_hightlight 0xF9
#define light_green_highlight 0xFA
#define light_cyan_highlight 0xFB
#define light_red_highlight 0xFC
#define light_purple_highlight 0xFD
#define yellow_highlight 0xFE


uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);
void outb(uint16_t port, uint8_t value);
int stringLength(char* string);
void concatChar(char* a, char b, char* c);
void removeChar(char* a, char* b);
int stringCompare(char* str1, char* str2);
void println(char * string);
void pause();
int indexOf(char c, char * string);
int indexOfn(char c, int n, char * string);
void substr(int i, char * src, char * dest);
void strcpy(char* string_one, char* string_two);
void substrr(int s, int e, char* source, char* destination);
void * memcpy(void * dest, const void * src, size_t count);
int strcmp(char* str1, char* str2);
int contains(char * string, char* contained);
int countOf(char c, char *str);
void powerdown();
#endif
