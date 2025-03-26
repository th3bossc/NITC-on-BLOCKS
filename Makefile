# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -g
LDFLAGS := -lssl -lcrypto  # Link OpenSSL libraries

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Find all .cpp files in src/ and subdirectories
SOURCES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Executable name
TARGET := $(BIN_DIR)/blockchain

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile each .cpp file to .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | create_build_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure build/ has all necessary subdirectories
create_build_dirs:
	@mkdir -p $(dir $(OBJECTS))

# Create necessary directories
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CXXFLAGS += -g
debug: clean all

.PHONY: all clean run debug create_build_dirs
