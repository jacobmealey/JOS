// shell.h
// dumb shell for JOS
// Author: Jacob Mealey

#ifndef SHELL_H
#define SHELL_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "common.h"
#include "ata.h"
void shInit();
void clearBuffer();
int commandCheck(char * command);
void shWrite(char data);
#endif
