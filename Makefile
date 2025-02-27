# Compiler
CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb -std=c99 -Wall -O0 -g
LDFLAGS = -nostdlib -T STM32F103RB.ld -Wl,-Map=$(BUILD_DIR)/final.map

BUILD_DIR = build
SRC_DIR = src
DRIVER_SRC_DIR = $(SRC_DIR)/drivers
APP_SRC_DIR = $(SRC_DIR)/app

DRIVER_SRCS = $(wildcard src/drivers/*.c)
DRIVER_OBJS = $(patsubst $(DRIVER_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(DRIVER_SRCS))

MAIN_OBJ 	= $(BUILD_DIR)/main.o
STARTUP_OBJ = $(BUILD_DIR)/stm32_startup.o

OBJS = $(MAIN_OBJ) $(STARTUP_OBJ) $(DRIVER_OBJS)

# Target rules
all: $(BUILD_DIR) $(BUILD_DIR)/final.elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# $@ = Target
# $^ = All prerequisites
# $< = First prerequisite

$(BUILD_DIR)/final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/app/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/drivers/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)