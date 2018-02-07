// common.h 
// Jacob Mealey
// Note! Some functions are from portOS 
#ifndef COMMON_H
#define COMMON_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdbool.h> /* C doesn't have booleans by default. */

#include <stddef.h>
#include <stdint.h>

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

uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);
void outb(uint16_t port, uint8_t value);
int string_length(char* string);
void concatc(char* a, char b, char* c);
void removec(char* a, char* b);
int string_compare(char* str1, char* str2);
#endif
