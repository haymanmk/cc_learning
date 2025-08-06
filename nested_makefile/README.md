# Nested Makefile Example

This project demonstrates how to create and use nested makefiles that reference each other. It's a comprehensive example showing different patterns and best practices for organizing makefiles in a multi-directory project.

## Project Structure

```
nested_makefile/
├── Makefile                 # Root makefile - orchestrates the entire build
├── README.md               # This file
├── lib/                    # Shared library
│   ├── Makefile           # Library-specific makefile
│   ├── math_utils.c       # Math utility functions
│   ├── math_utils.h
│   ├── string_utils.c     # String utility functions
│   └── string_utils.h
├── src/                    # Main application
│   ├── Makefile           # Application makefile (depends on lib)
│   ├── main.c             # Main application entry point
│   ├── app_logic.c        # Application-specific logic
│   └── app_logic.h
├── tools/                  # Utility tools
│   ├── Makefile           # Tools makefile (depends on lib)
│   ├── calculator.c       # Calculator tool
│   └── string_processor.c # String processing tool
└── tests/                  # Test suite
    ├── Makefile           # Test makefile (depends on lib and src)
    ├── test_runner.c      # Main test runner
    ├── test_math.c        # Math library tests
    ├── test_math.h
    ├── test_string.c      # String library tests
    └── test_string.h
```

## Key Concepts Demonstrated

### 1. Root Makefile Coordination
The root `Makefile` coordinates builds across subdirectories:
- Uses `$(MAKE) -C <directory>` to invoke makefiles in subdirectories
- Defines dependencies between subdirectories (e.g., src depends on lib)
- Provides global targets like `all`, `clean`, `install`

### 2. Dependency Management
- **Library First**: Both `src` and `tools` depend on `lib` and will build it automatically
- **Cross-Dependencies**: Tests depend on both `lib` and `src`
- **Conditional Building**: Subdirectory makefiles check if dependencies exist

### 3. Makefile Patterns Used

#### Recursive Make
```makefile
$(SUBDIRS):
    $(MAKE) -C $@
```

#### Dependency Checking
```makefile
lib-check:
    @if [ ! -f $(LIB_TARGET) ]; then \
        $(MAKE) -C $(LIB_DIR); \
    fi
```

#### Parallel Builds
The root makefile can build independent subdirectories in parallel.

## How to Use

### Build Everything
```bash
make all
```

### Build Specific Components
```bash
make lib          # Build only the library
make src          # Build library + application
make tools        # Build library + tools
make tests        # Build library + src + tests
```

### Run Components
```bash
# Run the main application
cd src && make run

# Run tools
cd tools && make run-calculator
cd tools && make run-string-processor

# Run tests
cd tests && make test
```

### Clean Everything
```bash
make clean        # Clean all subdirectories
```

### Install
```bash
make install      # Install all components (simulated)
```

## Advanced Makefile Features Shown

### 1. Cross-Directory Dependencies
- `src/Makefile` automatically builds `lib` if needed
- `tests/Makefile` builds both `lib` and `src` dependencies
- Root makefile defines explicit dependency order

### 2. Shared Variables and Standards
Each makefile uses consistent:
- Compiler flags (`CFLAGS`)
- Naming conventions
- Target patterns

### 3. Error Handling
- Makefiles check for required dependencies
- Provide helpful error messages
- Support force rebuilds

### 4. Multiple Target Types
- **Libraries**: Shared library with versioning
- **Executables**: Main application and tools
- **Tests**: Automated test suite

## Learning Points

### Make Invocation Patterns
1. **Recursive Make**: `$(MAKE) -C directory`
2. **Conditional Make**: Check file existence before building
3. **Dependency Ordering**: Explicit target dependencies

### Best Practices Demonstrated
1. **Modularity**: Each directory has focused responsibility
2. **Reusability**: Library can be used by multiple components
3. **Testing**: Comprehensive test suite with multiple run modes
4. **Documentation**: Clear target descriptions and help

### Common Patterns
1. **Library Dependencies**: How to link against local libraries
2. **Include Paths**: Using `-I../lib` for headers
3. **Library Paths**: Using `-L../lib` for linking
4. **Runtime Paths**: Using `LD_LIBRARY_PATH` for running

## Try These Commands

```bash
# Build and run everything
make all
cd src && make run

# Use the tools
cd tools
make run-calculator 5 add 3
make run-string-processor reverse "Hello World"

# Run comprehensive tests
cd tests && make test

# Clean and rebuild everything
make clean
make rebuild

# Get information about components
make info
cd lib && make info
cd src && make info
```

This example provides a solid foundation for understanding how to structure complex projects with nested makefiles that work together efficiently.
