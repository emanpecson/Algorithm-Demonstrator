# Make file for Algorithm Demonstrator

OBJS	= main.o Menu.o Algorithms.o BinarySearchAlgo.o MergeSortAlgo.o QuickSortAlgo.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= Menu.h Algorithms.h BinarySearchAlgo.h MergeSortAlgo.h QuickSortAlgo.h

all: main

main: $(OBJS)
				$(CC) $(CCFLAGS) -o main $(OBJS)

main.o: main.cpp $(DEPS)
				$(CC) $(CCFLAGS) -c main.cpp

Menu.o: Menu.cpp $(DEPS)
				$(CC) $(CCFLAGS) -c Menu.cpp

Algorithms.o: Algorithms.cpp $(DEPS)
				$(CC) $(CCFLAGS) -c Algorithms.cpp

BinarySearchAlgo.o: BinarySearchAlgo.cpp $(DEPS)
				$(CC) $(CCFLAGS) -c BinarySearchAlgo.cpp

MergeSortAlgo.o: MergeSortAlgo.cpp $(DEPS)
				$(CC) $(CCFLAGS) -c MergeSortAlgo.cpp

QuickSortAlgo.o: QuickSortAlgo.cpp $(DEPS)
				$(CC) $(CCFLAGS) -c QuickSortAlgo.cpp

# cleaning
clean:
				rm $(OBJS) main