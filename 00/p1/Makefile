# Find all .cpp files recursively
SRC_DIR := src
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')

# Generate object file names from source file names
OBJ_FILES := $(SRC_FILES:.cpp=.o)

# Output executable name
TARGET = ../p1.exe

# Default target
all: $(TARGET)
	make clean

# Link the object files to create the executable
$(TARGET): $(OBJ_FILES)
	g++ -o $@ $^

# Compile each .cpp file to a corresponding .o file
%.o: %.cpp
	g++ -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES)

.PHONY: all clean
