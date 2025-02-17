# Compiler
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -O2 -I./inc -I./CMSIS

# Linker
LDFLAGS = -T ldscripts/STM32F103RB.ld -nostartfiles -Wl,--gc-sections

# Source files
SRCS = src/main.c src/system_stm32f10x.c
OBJS = $(SRCS:.c=.o)

# Output
TARGET = main.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)