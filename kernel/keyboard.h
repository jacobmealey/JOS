#ifndef KEYBOARD_H
#define KEYBOARD_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>

unsigned char kbdus[256];
uint8_t inb(uint16_t);
char getScancode();
void handleKeys();

#endif
