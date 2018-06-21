OBJ = obj/boot.o obj/kernel.o obj/vga.o obj/keyboard.o obj/common.o obj/shell.o \
      obj/ata.o obj/fat.o obj/heap.o obj/parse.o obj/file_parse.o\
      obj/josl.o obj/calc.o

C_FLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
CPP_FLAGS = -static-libstdc++  -ffreestanding -O2 -Wall -Wextra -Wwrite-strings 

JOS.bin : $(OBJ)
	i386-elf-ld -T linker.ld -o JOS.bin $(OBJ) 
obj/boot.o : boot.s
	i386-elf-as boot.s -o obj/boot.o
obj/kernel.o : kernel/kernel.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/kernel.c -o obj/kernel.o $(C_FLAGS)
obj/vga.o : kernel/vga.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/vga.c -o obj/vga.o $(C_FLAGS)
obj/keyboard.o : kernel/keyboard.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/keyboard.c -o obj/keyboard.o $(C_FLAGS)
obj/common.o : kernel/common.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/common.c -o obj/common.o $(C_FLAGS)
obj/shell.o : kernel/shell.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/shell.c -o obj/shell.o $(C_FLAGS)
obj/ata.o : kernel/ata.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/ata.c -o obj/ata.o $(C_FLAGS)
obj/fat.o : kernel/fat.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/fat.c -o obj/fat.o $(C_FLAGS)
obj/heap.o : kernel/heap.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/heap.c -o obj/heap.o $(C_FLAGS)
obj/parse.o : kernel/parse.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/parse.c -o obj/parse.o $(C_FLAGS)
obj/file_parse.o : kernel/file_parse.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/file_parse.c -o obj/file_parse.o $(C_FLAGS)
obj/josl.o : kernel/josl.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/josl.c -o obj/josl.o $(C_FLAGS)
obj/calc.o : kernel/calc.c
	clang --target=i386-pc-none-elf -march=i386 -c kernel/calc.c -o obj/calc.o $(C_FLAGS)
run: JOS.bin
	qemu-system-x86_64 -kernel JOS.bin -drive format=raw,file=disk.img -device isa-debug-exit,iobase=0xf4,iosize=0x04
clean: 
	rm obj/*
