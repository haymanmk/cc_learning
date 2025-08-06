# Tests Makefile
# This makefile builds and runs tests for the project

CC = gcc
CFLAGS = -Wall -Wextra -O2 -I../lib -I../src
LDFLAGS = -L../lib -lmylib -lm

# Test files
TEST_SOURCES = test_math.c test_string.c test_runner.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_TARGET = test_runner

# Dependencies
LIB_DIR = ../lib
SRC_DIR = ../src
LIB_TARGET = $(LIB_DIR)/libmylib.so
APP_OBJECTS = $(SRC_DIR)/app_logic.o

.PHONY: all clean test lib-check src-check

all: lib-check src-check $(TEST_TARGET)
	@echo "Tests built successfully"

# Check dependencies
lib-check:
	@if [ ! -f $(LIB_TARGET) ]; then \
		echo "Library not found, building it first..."; \
		$(MAKE) -C $(LIB_DIR); \
	fi

src-check:
	@if [ ! -f $(APP_OBJECTS) ]; then \
		echo "Source objects not found, building src first..."; \
		$(MAKE) -C $(SRC_DIR); \
	fi

$(TEST_TARGET): $(TEST_OBJECTS) $(APP_OBJECTS)
	@echo "Linking test runner..."
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@echo "Compiling test $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning tests..."
	rm -f $(TEST_OBJECTS) $(TEST_TARGET)

# Run tests
test: $(TEST_TARGET)
	@echo "Running tests..."
	LD_LIBRARY_PATH=../lib ./$(TEST_TARGET)

# Run tests with verbose output
test-verbose: $(TEST_TARGET)
	@echo "Running tests with verbose output..."
	LD_LIBRARY_PATH=../lib ./$(TEST_TARGET) --verbose

# Individual test targets
test-math: $(TEST_TARGET)
	@echo "Running math tests only..."
	LD_LIBRARY_PATH=../lib ./$(TEST_TARGET) --math-only

test-string: $(TEST_TARGET)
	@echo "Running string tests only..."
	LD_LIBRARY_PATH=../lib ./$(TEST_TARGET) --string-only

# Show test info
info:
	@echo "Test target: $(TEST_TARGET)"
	@echo "Test sources: $(TEST_SOURCES)"
	@echo "Dependencies: $(LIB_TARGET), $(APP_OBJECTS)"
