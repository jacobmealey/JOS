/* Surely you will remove the processor conditionals and this comment
zsh:1: command not found: 5*/
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
 
#include "vga.h"
#include "keyboard.h"
#include "shell.h"
#include "ata.h"


#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main(void) 
{

		/* Initialize terminal interface */
		uint16_t color = 0x0F; 
		/* Newline support is left as an exercise. */
		clear_screen(color);
		sh_init();
		prepareDisk(0, 0);
		getFSType(0);
		sh_write(getFSType(0));
		while(true)
			handleKeys();
}
