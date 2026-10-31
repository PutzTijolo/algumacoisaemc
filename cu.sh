gcc -m32 -ffreestanding -nostdlib -fno-pie -fno-pic -Os -T linker.ld bootloader.c -o fractal16.bin && qemu-system-i386 -fda fractal16.bin
