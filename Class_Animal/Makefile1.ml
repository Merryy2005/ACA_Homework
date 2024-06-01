# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS := Animal.cpp Bear.cpp Elephant.cpp Giraffe.cpp Lion.cpp Tiger.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

TARGET = myprogram

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean
clean 
	rm -f $(TARGET) $(OBJS)
