# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS := Animal.cpp Bear.cpp Elephant.cpp Giraffe.cpp Lion.cpp Tiger.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

TARGET = myprogram

# Default target
all: $(TARGET)
	$(CXX) $(CXXFLAGS) -c -o $@ $^

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
