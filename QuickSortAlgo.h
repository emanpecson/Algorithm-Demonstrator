#ifndef QUICKSORTALGO_H
#define QUICKSORTALGO_H

#include "Algorithms.h"

/*
	QuickSortAlgo class type which derives from the Algorithms class type.
	Provides functions for demonstrating the algorithm.
*/
class QuickSortAlgo : public Algorithms {
private:
	int partition(int[], int, int);
	int partitionExplained(int[], int, int);
public:
	void QuickSort(int[], int, int);
	void QuickSortDescription();
	void QuickSortExplained(int[], int, int);
};

#endif
