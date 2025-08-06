# Library Makefile
# This makefile builds a shared library

LIB_NAME = mylib
LIB_VERSION = 1.0
CC = gcc
CFLAGS = -Wall -Wextra -fPIC -O2
LDFLAGS = -shared

# Source files
SOURCES = math_utils.c string_utils.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = lib$(LIB_NAME).so.$(LIB_VERSION)
SYMLINK = lib$(LIB_NAME).so

.PHONY: all clean install

all: $(TARGET)
	@echo "Library $(LIB_NAME) built successfully"

$(TARGET): $(OBJECTS)
	@echo "Linking library $@..."
	$(CC) $(LDFLAGS) -o $@ $^
	ln -sf $(TARGET) $(SYMLINK)

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning library..."
	rm -f $(OBJECTS) $(TARGET) $(SYMLINK)

install: $(TARGET)
	@echo "Installing library to /usr/local/lib..."
	@echo "cp $(TARGET) /usr/local/lib/"
	@echo "ln -sf /usr/local/lib/$(TARGET) /usr/local/lib/$(SYMLINK)"
	@echo "ldconfig"

# Show library info
info:
	@echo "Library: $(LIB_NAME)"
	@echo "Version: $(LIB_VERSION)"
	@echo "Target: $(TARGET)"
	@echo "Sources: $(SOURCES)"
