.PHONY: all

# This file is going to build linkable objects before they are assembled into a executable file.

# Create a list of object files by substituting .c with .o
SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

all: $(OBJ_FILES) Makefile

# Prepare for all linkable objects
$(BUILD_DIR)/%.o: %.c
	$(CC) -O0 -g -c $< -o $@