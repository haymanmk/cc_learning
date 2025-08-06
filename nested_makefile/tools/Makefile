# Tools Makefile
# This makefile builds utility tools

CC = gcc
CFLAGS = -Wall -Wextra -O2 -I../lib
LDFLAGS = -L../lib -lmylib -lm

# Tools to build
TOOLS = calculator string_processor
TOOL_SOURCES = calculator.c string_processor.c
TOOL_OBJECTS = $(TOOL_SOURCES:.c=.o)

# Library dependency
LIB_DIR = ../lib
LIB_TARGET = $(LIB_DIR)/libmylib.so

.PHONY: all clean install lib-check $(TOOLS)

all: lib-check $(TOOLS)
	@echo "All tools built successfully"

# Individual tool targets
calculator: calculator.o lib-check
	@echo "Building calculator tool..."
	$(CC) -o $@ $< $(LDFLAGS)

string_processor: string_processor.o lib-check
	@echo "Building string processor tool..."
	$(CC) -o $@ $< $(LDFLAGS)

# Check if library exists, build if needed
lib-check:
	@if [ ! -f $(LIB_TARGET) ]; then \
		echo "Library not found, building it first..."; \
		$(MAKE) -C $(LIB_DIR); \
	fi

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning tools..."
	rm -f $(TOOL_OBJECTS) $(TOOLS)

install: $(TOOLS)
	@echo "Installing tools to /usr/local/bin..."
	@for tool in $(TOOLS); do \
		echo "cp $$tool /usr/local/bin/"; \
	done

# Run tools
run-calculator: calculator
	@echo "Running calculator..."
	LD_LIBRARY_PATH=../lib ./calculator

run-string-processor: string_processor
	@echo "Running string processor..."
	LD_LIBRARY_PATH=../lib ./string_processor

# Show tools info
info:
	@echo "Tools: $(TOOLS)"
	@echo "Library dependency: $(LIB_TARGET)"
