CC = i386-elf-gcc

myos.bin: 
	$(CC) -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel/vga.o kernel/kernel.o -lgcc

kernel.o: 
	$(CC) -c kernel/kernel.c -o kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

vga.o: 
	$(CC) -c kernel/vga.c -o kernel/vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

clean:
	rm -f kernel/kernel.o kernel/vga.o
