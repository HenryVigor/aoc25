# Find all .cpp files recursively
SRC_DIR_P1 := p1/src
SRC_FILES_P1 := $(shell find $(SRC_DIR_P1) -name '*.cpp')
SRC_DIR_P2 := p2/src
SRC_FILES_P2 := $(shell find $(SRC_DIR_P2) -name '*.cpp')

# Generate object file names from source file names
OBJ_FILES_P1 := $(SRC_FILES_P1:.cpp=.o)
OBJ_FILES_P2 := $(SRC_FILES_P2:.cpp=.o)

# Output executable name
TARGET_P1 = p1.exe
TARGET_P2 = p2.exe

# Default target
all: $(TARGET_P1) $(TARGET_P2)
	make clean

# Link the object files to create the executable
$(TARGET_P1): $(OBJ_FILES_P1)
	g++ -o $@ $^

$(TARGET_P2): $(OBJ_FILES_P2)
	g++ -o $@ $^

# Compile each .cpp file to a corresponding .o file
%.o: %.cpp
	g++ -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES_P1)
	rm -f $(OBJ_FILES_P2)

.PHONY: all clean
