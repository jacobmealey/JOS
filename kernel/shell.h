// shell.h
// dumb shell for JOS
// Author: Jacob Mealey

#ifndef SHELL_H
#define SHELL_H

// Includes
#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "common.h"
#include "ata.h"
#include "fat.h"


void shInit();
void prompt();
void clearBuffer();
void commandCheck(char * command);
void shWrite(char data);
#endif
