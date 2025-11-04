.PHONY: all clean

TARGET = calling_convention
BUILD_DIR = build
SRC_DIR = src

# Enable cross-compilation by setting CROSS_COMPILE to non-empty value
CROSS_COMPILE = 

# Locate the cross-compilation tools
PREFIX := $(HOME)/opt/cross/bin
TARGET_ARCH := i686-elf

ifneq ($(CROSS_COMPILE),)
CC := $(PREFIX)/$(TARGET_ARCH)-gcc
AS := $(PREFIX)/$(TARGET_ARCH)-as
LD := $(PREFIX)/$(TARGET_ARCH)-ld
endif

# Define source files and corresponding object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS += $(wildcard $(SRC_DIR)/*.S)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter %.c,$(SRCS)))
OBJS += $(patsubst $(SRC_DIR)/%.S,$(BUILD_DIR)/%.o,$(filter %.S,$(SRCS)))

all: $(OBJS) | $(BUILD_DIR)
	@echo "Linking $(TARGET)..."
	@echo "Object files: $^"
	$(LD) -Map=$(BUILD_DIR)/$(TARGET).map -o $(BUILD_DIR)/$(TARGET) $^
	objdump -D  -M att $(BUILD_DIR)/$(TARGET) > $(BUILD_DIR)/$(TARGET).S
	@echo "\n"

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile object files for C source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "Compiling $< to $@"
	$(CC) -g -O0 -c $< -o $@
	@echo "\n"

# Compile object files for assembly source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S | $(BUILD_DIR)
	@echo "Compiling $< to $@"
	$(AS) -g -O0 -c $< -o $@
	@echo "\n"

clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)/*
	@echo "\n"