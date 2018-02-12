// keyboard.h
// keyboard / ps2 driver for JOS
// Author Jacob Mealey

#ifndef KEYBOARD_H
#define KEYBOARD_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>

unsigned char keyboard_bus[256];
char getScancode();
void handleKeys();

#endif
