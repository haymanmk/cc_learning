.PHONY: all clean
# define build directory
BUILD_DIR = build

# create build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# create a list of object files by substituting .cc with .o
SRC_FILES = $(wildcard src/*.cc)
OBJ_FILES = $(patsubst src/%.cc,$(BUILD_DIR)/%.o,$(SRC_FILES))

# link relocatable objects into executable
all: $(call OBJ_FILES)
	$(CXX) -o $(BUILD_DIR)/main $(call OBJ_FILES)

# compile source files into object files
$(BUILD_DIR)/%.o: src/%.cc
	$(CXX) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)