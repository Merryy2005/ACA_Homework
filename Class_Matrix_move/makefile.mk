# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -O0 -fno-elide-constructors

# Define the target executable
TARGET = a

# Define source files
SRCS = main.cpp Matrix.cpp

# Define object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule for linking the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule for compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
