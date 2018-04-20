// kernel.c 
// Author: Jacob Mealey
//
// skeleton code from wiki.osdev.org

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
 
/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
 
// Includes 
#include "vga.h"
#include "keyboard.h"
#include "shell.h"
#include "fat.h"


#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main(void) 
{

	clear_screen(normal);
	shInit();
	setupDisk();
	fatInfo();
	prompt();

	while(true)
	handleKeys();
}
