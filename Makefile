# Compiler
CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb -std=gnu99 -Wall -O0
LDFLAGS = -nostdlib -T STM32F103RB.ld -Wl,-Map=final.map
MAIN = src/main

all:src/main.o src/stm32_startup.o final.elf

src/main.o:src/main.c
	$(CC) $(CFLAGS) -o $@ $^

src/stm32_startup.o:src/stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf:src/main.o src/stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^
clean:
	rm -rf src/*.o *.elf *.map