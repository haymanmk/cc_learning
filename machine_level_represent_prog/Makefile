.PHONY: all clean
# Get current directory
PROJ_ROOT := $(CURDIR)
# Build directory
BUILD_DIR := $(PROJ_ROOT)/build
# Source directory
SRC_DIR := $(PROJ_ROOT)/src

all: $(BUILD_DIR) Makefile $(SRC_DIR)/Makefile
	$(MAKE) -C $(SRC_DIR) BUILD_DIR=$(BUILD_DIR)
	$(CC) -O0 -g -o $(BUILD_DIR)/main $(BUILD_DIR)/*.o

# Check if build directory exists. If not, create a new one.
$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
