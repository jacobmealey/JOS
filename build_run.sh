echo "Compiling Kernel"
i386-elf-gcc -c kernel/kernel.c -o kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "compiling vga driver"
i386-elf-gcc -c kernel/vga.c -o kernel/vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "Linking Kernel and Bootloader"
i386-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel/kernel.o kernel/vga.o -lgcc
echo "running system"
qemu-system-i386 -kernel myos.bin
