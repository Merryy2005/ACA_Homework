# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Source files
SRCS = Animal.cpp Bear.cpp Elephant.cpp Giraffe.cpp Lion.cpp Tiger.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = a.exe

# Default target
all: $(EXEC)

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $
