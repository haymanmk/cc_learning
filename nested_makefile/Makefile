# Main/Root Makefile
# This demonstrates how to create nested makefiles that reference each other

# Project configuration
PROJECT_NAME = NestedMakefileExample
VERSION = 1.0.0

# Directories with their own makefiles
SUBDIRS = src lib tools tests

# Default target
.PHONY: all clean install help $(SUBDIRS)

all: $(SUBDIRS)
	@echo "Building complete project: $(PROJECT_NAME) v$(VERSION)"

# Build each subdirectory by calling their makefiles
lib:
	@echo "Building lib..."
	$(MAKE) -C lib

tools: lib
	@echo "Building tools (depends on lib)..."
	$(MAKE) -C lib
	$(MAKE) -C tools

src: lib
	@echo "Building src (depends on lib)..."
	$(MAKE) -C lib
	$(MAKE) -C src

tests: src lib
	@echo "Building tests (depends on src and lib)..."
	$(MAKE) -C lib
	$(MAKE) -C src
	$(MAKE) -C tests

# Clean all subdirectories
clean:
	@echo "Cleaning all subdirectories..."
	@for dir in $(SUBDIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "Cleaning $$dir..."; \
			$(MAKE) -C $$dir clean; \
		fi; \
	done
	@echo "Root clean complete"

# Install target (calls install in subdirectories that support it)
install: all
	@echo "Installing $(PROJECT_NAME)..."
	@for dir in $(SUBDIRS); do \
		if [ -f $$dir/Makefile ]; then \
			if $(MAKE) -C $$dir -q install 2>/dev/null; then \
				echo "Installing from $$dir..."; \
				$(MAKE) -C $$dir install; \
			fi; \
		fi; \
	done

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build entire project"
	@echo "  clean   - Clean all build artifacts"
	@echo "  install - Install the project"
	@echo "  src     - Build source code (depends on lib)"
	@echo "  lib     - Build library"
	@echo "  tools   - Build tools"
	@echo "  tests   - Build and run tests (depends on src, lib)"
	@echo "  help    - Show this help message"

# Force rebuild of subdirectories
rebuild: clean all

# Show project info
info:
	@echo "Project: $(PROJECT_NAME)"
	@echo "Version: $(VERSION)"
	@echo "Subdirectories: $(SUBDIRS)"

# Create configuration file
configure:
	$(MAKE) -s -f config_temp.mk > config.mk
