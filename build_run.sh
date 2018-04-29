# Build Script for JOS
# Jacob Mealey 
echo "Compiling Bootloader"
i386-elf-as boot.s -o obj/boot.o
echo "Compiling Kernel"
i386-elf-gcc -c kernel/kernel.c -o obj/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling vga driver"
i386-elf-gcc -c kernel/vga.c -o obj/vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling ps/2"
i386-elf-gcc -c kernel/keyboard.c -o obj/keyboard.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling common"
i386-elf-gcc -c kernel/common.c -o obj/common.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling shell"
i386-elf-gcc -c kernel/shell.c -o obj/shell.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling ata driver"
i386-elf-gcc -c kernel/ata.c -o obj/ata.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling fat"
i386-elf-gcc -c kernel/fat.c -o obj/fat.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling heap"
i386-elf-gcc -c kernel/heap.c -o obj/heap.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wall
echo "compiling files"
i386-elf-g++ -c kernel/files.cpp -o obj/files.o -static-libstdc++  -ffreestanding -O2 -Wall -Wextra -Wwrite-strings
echo "compiling parser"
i386-elf-gcc -c kernel/parse.c -o obj/parse.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wall
echo "compiling file_parser"
i386-elf-gcc -c kernel/file_parse.c -o obj/file_parse.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wall
echo "Linking Kernel and Bootloader"
i386-elf-g++ -T linker.ld -o JOS.bin -ffreestanding -O2 -nostdlib\
       	obj/boot.o obj/keyboard.o obj/common.o obj/shell.o obj/kernel.o obj/vga.o\
	obj/ata.o obj/fat.o obj/heap.o obj/files.o obj/parse.o obj/file_parse.o -lgcc
echo "running system"
qemu-system-x86_64 -kernel JOS.bin -drive format=raw,file=disk.img -device isa-debug-exit,iobase=0xf4,iosize=0x04
