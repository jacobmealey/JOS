// Shell for JOS
// Jacob Mealey
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
void sh_init();
void sh_write(char data);
#endif
