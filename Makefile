# Directories
OBJ_DIR = bin/obj
BIN_DIR = bin

# Source files
SOURCES = testcmp.cpp mycomplex.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Executable program
TARGET = $(BIN_DIR)/complex

# Default rule
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJECTS)
	@echo "Linking: $^"
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Program $(TARGET) has been compiled and linked."

# Rule for compiling object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	@echo "Compiling: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$< successfully compiled to an object file."

# Clean generated files
clean:
	@echo "Cleaning up generated files..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)/complex
	@echo "Clean-up complete."

# Declare phony targets
.PHONY: all clean
