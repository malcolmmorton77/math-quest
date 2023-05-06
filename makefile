# Author: Malcolm M.
# This makefile creates the program for math prompts
CC=g++ # macro defined for what compiler to use

all: run.exe clean run

run.exe: prompt.o
	$(CC) -o run.exe prompt.o

prompt.o: prompt.cpp prompt.h
	$(CC) -c prompt.cpp

clean: # remove the object files
	rm *.o

run:
	clear
	./run.exe

clean_all: # clear current directory of any pesky object files and executables
	rm *.o *.exe
	clear