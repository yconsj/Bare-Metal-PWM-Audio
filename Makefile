# Compiler
CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb -std=c99 -Wall -O0 -g

# Default target
TARGET ?= stm32f103rb

# Add the TARGET define to CFLAGS
CFLAGS += -D$(TARGET)



# Directories
BUILD_DIR = build
SRC_DIR = src
HAL_SRC_DIR = $(SRC_DIR)/hal/
APP_SRC_DIR = $(SRC_DIR)/app/
DRIVER_SRC_DIR = $(SRC_DIR)/drivers/$(TARGET)
BOARD_SPECIFIC_DIR = board_specific

# Include directories
CFLAGS += -I$(HAL_SRC_DIR) -I$(DRIVER_SRC_DIR) -I$(BOARD_SPECIFIC_DIR)


$(info $(DRIVER_SRC_DIR))
$(info $(HAL_SRC_DIR))

# Linker script and startup file based on target
LDSCRIPT = $(BOARD_SPECIFIC_DIR)/$(TARGET).ld
STARTUP_FILE = $(DRIVER_SRC_DIR)/$(TARGET)_startup.c  # Startup moved to driver dir

LDFLAGS = -nostdlib -T $(LDSCRIPT) -Wl,-Map=$(BUILD_DIR)/final.map

# Source files
DRIVER_SRCS = $(wildcard $(DRIVER_SRC_DIR)/*.c)
DRIVER_OBJS = $(patsubst $(DRIVER_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(DRIVER_SRCS))

HAL_SRCS = $(wildcard $(HAL_SRC_DIR)/*.c)
HAL_OBJS = $(patsubst $(HAL_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(HAL_SRCS))

MAIN_OBJ = $(BUILD_DIR)/main.o
STARTUP_OBJ = $(BUILD_DIR)/$(TARGET)_startup.o

OBJS = $(MAIN_OBJ) $(STARTUP_OBJ) $(DRIVER_OBJS) $(HAL_OBJS)

# Target rules
all: $(BUILD_DIR) $(BUILD_DIR)/final.elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(APP_SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(DRIVER_SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(HAL_SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/$(TARGET)_startup.o: $(STARTUP_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)
