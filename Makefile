

CXX = g++
CC = gcc
CXXFLAGS = -Wall -std=c++11
CFLAGS = -Wall -std=c99

CXX_SRC = MatrixLibrary.cpp
C_SRC = matrix_lib.c

CXX_EXEC = matrix_cpp
C_EXEC = matrix_c

.PHONY: all clean run_cpp run_c

all: $(CXX_EXEC) $(C_EXEC)

$(CXX_EXEC): $(CXX_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(C_EXEC): $(C_SRC)
	$(CC) $(CFLAGS) -o $@ $^

run_cpp: $(CXX_EXEC)
	./$(CXX_EXEC)

run_c: $(C_EXEC)
	./$(C_EXEC)

clean:
	rm -f $(CXX_EXEC) $(C_EXEC)
