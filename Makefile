# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude -Isrc

# Target executable
BIN = amazon_inventory

# Source files
SRC = src/main.cpp src/Product.cpp src/Utils.cpp

# Default target: build executable
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

# Run program
run: all
	./$(BIN)

# Clean executable and test binary
clean:
	rm -f $(BIN) test_hash
	
# Run tests
test:
	$(CXX) $(CXXFLAGS) tests/test_HashTable.cpp -o test_hash
	./test_hash

.PHONY: all run clean test
