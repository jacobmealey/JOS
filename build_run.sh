# Build Script for JOS
# Jacob Mealey 
echo "Compiling Bootloader"
i386-elf-as boot.s -o boot.o
echo "Compiling Kernel"
i386-elf-gcc -c kernel/kernel.c -o kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling vga driver"
i386-elf-gcc -c kernel/vga.c -o kernel/vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling ps/2"
i386-elf-gcc -c kernel/keyboard.c -o kernel/keyboard.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling common"
i386-elf-gcc -c kernel/common.c -o kernel/common.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling shell"
i386-elf-gcc -c kernel/shell.c -o kernel/shell.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling ata driver"
i386-elf-gcc -c kernel/ata.c -o kernel/ata.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling fat"
i386-elf-gcc -c kernel/fat.c -o kernel/fat.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Wall
echo "compiling heap"
i386-elf-gcc -c kernel/heap.c -o kernel/heap.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wall
echo "compiling files"
i386-elf-g++ -c kernel/files.cpp -o kernel/files.o -static-libstdc++  -ffreestanding -O2 -Wall -Wextra -Wwrite-strings
echo "compiling parser"
i386-elf-gcc -c kernel/parse.c -o kernel/parse.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wall
echo "compiling file_parser"
i386-elf-gcc -c kernel/file_parse.c -o kernel/file_parse.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wall
echo "Linking Kernel and Bootloader"
i386-elf-g++ -T linker.ld -o JOS.bin -ffreestanding -O2 -nostdlib\
       	boot.o kernel/keyboard.o kernel/common.o kernel/shell.o kernel/kernel.o kernel/vga.o\
	kernel/ata.o kernel/fat.o kernel/heap.o kernel/files.o kernel/parse.o kernel/file_parse.o -lgcc
echo "cleaning up"
rm *.o
rm kernel/*.o
echo "running system"
qemu-system-x86_64 -kernel JOS.bin -drive format=raw,file=disk.img -device isa-debug-exit,iobase=0xf4,iosize=0x04
