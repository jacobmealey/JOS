// vga.c
// VGA driver for JOS
// Author: Jacob Mealey
//
// modified code from PortOS

#ifndef VGA_H
#define VGA_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>

#include "common.h"

void clear_screen(uint8_t color);

void putchar(char c, uint8_t color);

void printf(char *c, uint8_t color);

void move_cursor();

void scroll(uint8_t color);

void printInt(int i, uint8_t color);

int getX();

int getY();

int getPos();

void setPos(int x, int y);

void centerPrint(char * text, uint8_t color);
#endif
