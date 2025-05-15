# Compiler
CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb -std=c99 -Wall -O0 -g
CFLAGS += -mthumb -mabi=aapcs -mlittle-endian
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fshort-enums -fomit-frame-pointer
CFLAGS += -ffreestanding

# Default target
TARGET ?= stm32f103rb

# Add the TARGET define to CFLAGS
CFLAGS += -D$(TARGET)



# Directories
BUILD_DIR = build
SRC_DIR = src
HAL_SRC_DIR = $(SRC_DIR)/hal
APP_SRC_DIR = $(SRC_DIR)/app
DRIVER_SRC_DIR = $(SRC_DIR)/drivers/$(TARGET)
BOARD_SPECIFIC_DIR = board_specific
COMMON_SRC_DIR = $(SRC_DIR)/common

# Include directories
CFLAGS += -I$(HAL_SRC_DIR) -I$(DRIVER_SRC_DIR) -I$(BOARD_SPECIFIC_DIR) -I$(COMMON_SRC_DIR)



# Linker script and startup file based on target
LDSCRIPT = $(BOARD_SPECIFIC_DIR)/$(TARGET).ld

LDFLAGS = -nostdlib -T $(LDSCRIPT) -Wl,-Map=$(BUILD_DIR)/final.map
LDFLAGS += -specs=nosys.specs
LDFLAGS += -Wl,--verbose

LDFLAGS += -mthumb -mabi=aapcs -mlittle-endian
LDFLAGS += -Wl,-zdefs -Wl,--warn-common



# Source files
APP_SRCS = $(wildcard $(APP_SRC_DIR)/*.c)
APP_OBJS = $(patsubst $(APP_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(APP_SRCS))

DRIVER_SRCS = $(wildcard $(DRIVER_SRC_DIR)/*.c)
DRIVER_OBJS = $(patsubst $(DRIVER_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(DRIVER_SRCS))

HAL_SRCS = $(wildcard $(HAL_SRC_DIR)/*.c)
HAL_OBJS = $(patsubst $(HAL_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(HAL_SRCS))

COMMON_SRCS = $(wildcard $(COMMON_SRC_DIR)/*.c)
COMMON_OBJS = $(patsubst $(COMMON_SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(COMMON_SRCS))


OBJS = $(APP_OBJS) $(DRIVER_OBJS) $(HAL_OBJS) $(COMMON_OBJS)


$(info Compiling: $<)
$(info DRIVER_SRCS: $(DRIVER_SRCS))
$(info HAL_SRCS: $(HAL_SRCS))
$(info COMMON_SRCS: $(COMMON_SRCS))
$(info APP_SRC_DIR: $(APP_SRC_DIR))
$(info APP_SRCS: $(APP_SRCS))
$(info APP_OBJS: $(APP_OBJS))
$(info OBJS: $(OBJS))

#$(BUILD_DIR):
#	@echo "test1"
#	mkdir -p $(BUILD_DIR)

# Create build dir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile APP sources
$(BUILD_DIR)/%.o: $(APP_SRC_DIR)/%.c
	@echo "Compiling APP $*"
	$(CC) $(CFLAGS) -o $@ $<

# Compile COMMON sources
$(BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.c
	@echo "Compiling COMMON $*"
	$(CC) $(CFLAGS) -o $@ $<

# Compile DRIVER sources
$(BUILD_DIR)/%.o: $(DRIVER_SRC_DIR)/%.c
	@echo "Compiling DRIVER $*"
	$(CC) $(CFLAGS) -o $@ $<

# Compile HAL sources
$(BUILD_DIR)/%.o: $(HAL_SRC_DIR)/%.c
	@echo "Compiling HAL $*"
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/final.elf: $(OBJS)
	@echo "Building final.elf from: $(OBJS)"
	$(CC) $(LDFLAGS) -o $@ $^



# Target rules
$(BUILD_DIR)/final.hex: $(BUILD_DIR)/final.elf
	arm-none-eabi-objcopy -O ihex $(BUILD_DIR)/final.elf $(BUILD_DIR)/final.hex


# Some MCUs and flash loaders expect unprogrammed areas to be filled with 0xFF.
$(BUILD_DIR)/final.bin: $(BUILD_DIR)/final.elf
	arm-none-eabi-objcopy -O binary --gap-fill=0xFF $(BUILD_DIR)/final.elf $(BUILD_DIR)/final.bin

all: $(BUILD_DIR) $(BUILD_DIR)/final.elf $(BUILD_DIR)/final.bin $(BUILD_DIR)/final.hex
#$(BUILD_DIR)/final.bin $(BUILD_DIR)/final.hex
# $< $@
# 


clean:
	rm -rf $(BUILD_DIR)
