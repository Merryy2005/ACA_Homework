# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files for writing and reading matrices
WRITE_SOURCES = WriteMatrix.cpp Matrix.cpp
READ_SOURCES = MultiplyMatrix.cpp Matrix.cpp

# Object files for writing and reading matrices
WRITE_OBJECTS = $(WRITE_SOURCES:.cpp=.o)
READ_OBJECTS = $(READ_SOURCES:.cpp=.o)

# Executable names
WRITE_EXEC = write_matrix
READ_EXEC = read_matrix

# Default target
all: $(WRITE_EXEC) $(READ_EXEC)

# Write Matrix executable
$(WRITE_EXEC): $(WRITE_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Read Matrix executable
$(READ_EXEC): $(READ_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(WRITE_OBJECTS) $(WRITE_EXEC) $(READ_OBJECTS) $(READ_EXEC)
