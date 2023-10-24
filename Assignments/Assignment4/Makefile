CXX = g++

all: main

main: main.o CSRMatrix.o
	$(CXX) -o $@ $^

%.o: %.cpp CSRMatrix.hpp
	$(CXX) -g -c $<

.PHONY: clean

clean:
	rm -f *.o main