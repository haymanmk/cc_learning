# Source Makefile
# This makefile builds the main application and depends on the library

APP_NAME = myapp
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I../lib
LDFLAGS = -L../lib -lmylib -lm

# Source files
SOURCES = main.c app_logic.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = $(APP_NAME)

# Library dependency
LIB_DIR = ../lib
LIB_TARGET = $(LIB_DIR)/libmylib.so

.PHONY: all clean install lib-check

all: lib-check $(TARGET)
	@echo "Application $(APP_NAME) built successfully"

# Check if library exists, build if needed
lib-check:
	@if [ ! -f $(LIB_TARGET) ]; then \
		echo "Library not found, building it first..."; \
		$(MAKE) -C $(LIB_DIR); \
	fi

$(TARGET): $(OBJECTS)
	@echo "Linking application $@..."
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning application..."
	rm -f $(OBJECTS) $(TARGET)

install: $(TARGET)
	@echo "Installing application to /usr/local/bin..."
	@echo "cp $(TARGET) /usr/local/bin/"

# Run the application
run: $(TARGET)
	@echo "Running $(APP_NAME)..."
	LD_LIBRARY_PATH=../lib ./$(TARGET)

# Force rebuild with clean library
rebuild: clean
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) all

# Show app info
info:
	@echo "Application: $(APP_NAME)"
	@echo "Target: $(TARGET)"
	@echo "Sources: $(SOURCES)"
	@echo "Library dependency: $(LIB_TARGET)"
