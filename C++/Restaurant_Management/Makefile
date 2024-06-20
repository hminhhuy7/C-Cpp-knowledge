CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -std=c11 -IHeaders
CXXFLAGS := -Wall -Wextra -std=c++11 -IHeaders
TARGET := main

SRC_C := $(wildcard Sources/*.c)
SRC_CPP := $(wildcard Sources/*.cpp)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC_C) $(SRC_CPP)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)