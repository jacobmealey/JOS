	.file	"kernel.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Hello, kernel World!\n"
.LC1:
	.string	"THIS IS ALL ME BABY!\n"
.LC2:
	.string	"WELCOME TO MY OS"
	.text
	.align 4
	.globl	kernel_main
	.type	kernel_main, @function
kernel_main:
.LFB0:
	.cfi_startproc
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	call	terminal_initialize
	subl	$12, %esp
	.cfi_def_cfa_offset 28
	pushl	$.LC0
	.cfi_def_cfa_offset 32
	call	terminal_writestring
	movl	$.LC1, (%esp)
	call	terminal_writestring
	movl	$.LC2, (%esp)
	call	terminal_writestring
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	kernel_main, .-kernel_main
	.comm	terminal_buffer,4,4
	.comm	terminal_color,1,1
	.comm	terminal_column,4,4
	.comm	terminal_row,4,4
	.ident	"GCC: (GNU) 7.2.0"
