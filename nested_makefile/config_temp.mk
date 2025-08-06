configure: 
	@echo "# Configuring project..."
	@echo CONFIG_VERSION = $(CONFIG_VERSION)
	@echo CONFIG_LIB_NAME = $(CONFIG_LIB_NAME)
	@echo CONFIG_TOOLS_DIR = $(CONFIG_TOOLS_DIR)
	@echo CONFIG_LIB_DIR = $(CONFIG_LIB_DIR)
	@echo CONFIG_SRC_DIR = $(CONFIG_SRC_DIR)
	@echo CONFIG_TESTS_DIR = $(CONFIG_TESTS_DIR)
	@echo "# Configuration complete. You can now run 'make' to build the project."

include params.mk