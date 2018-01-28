echo "Compiling Kernel"
i386-elf-gcc -c kernel/kernel.c -o kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "compiling vga driver"
i386-elf-gcc -c kernel/vga.c -o kernel/vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "compiling ps/2"
i386-elf-gcc -c kernel/keyboard.c -o kernel/keyboard.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "compiling common"
i386-elf-gcc -c kernel/common.c -o kernel/common.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "compiling shell"
i386-elf-gcc -c kernel/shell.c -o kernel/shell.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "Linking Kernel and Bootloader"
i386-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel/keyboard.o kernel/common.o kernel/shell.o kernel/kernel.o kernel/vga.o -lgcc
echo "running system"
qemu-system-i386 -kernel myos.bin
