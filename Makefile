# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o Assembler.o DataConverter.o
	$(CXX) $(CXXFLAGS) -o main main.o Assembler.o DataConverter.o

# The main.o target can be written more simply

main.o: main.cpp DataConverter.h Assembler.h
	$(CXX) $(CXXFLAGS) -c main.cpp

DataConverter.o: DataConverter.h

Assembler.o: Assembler.h DataConverter.h

clean:
	rm -f  *o  main