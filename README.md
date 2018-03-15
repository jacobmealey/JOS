# JOS
### Jacobs Operating System

![JOS](/screenshot.png)

JOS is a small operating that I am working on as an independant study, JOS is a pretty monolithic kernel (basic commands and
filesystems are compiled into the kernel) I do not believe this is the best approach, but this is my first real dive in to 
building an Operating System. 

#### Todo:
  - ~~be able to list the contents of a file~~
  - be able to create and delete files 
  - build a unix-like file structure (/bin , /usr, /home etc)
  - start building userspace applications
     - improved shell
     - text editor
     - compiler (?)
  - OPTIMIZE 

JOS is written completely in C (and a bit of assembly) at the moment but, I am looking to implement other languages into the code base where I see fit. It would be nice to have rust compatibility, C++ is already 'implemented' - that is if you have the whole i386-elf cross compiler collection - I just haven't found a use for it yet. 


#### Information and other sources:

  [fat32](https://www.pjrc.com/tech/8051/ide/fat32.html)
  
  [OS Dev](https://wiki.osdev.org/Main_Page)
  
  [Thor OS](https://github.com/wichtounet/thor-os)
  
  [Code OS](https://github.com/aaron-sonin/codeOS2)
  
  [Decimal - Hex - Binary](https://www.ascii.cl/conversion.htm)
