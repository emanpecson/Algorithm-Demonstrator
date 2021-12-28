#ifndef BINARYSEARCHALGO_H
#define BINARYSEARCHALGO_H

#include "Algorithms.h"

/*
	BinarySearchAlgo class type which derives from the Algorithms class type.
	Provides functions for demonstrating the algorithm.
*/
class BinarySearchAlgo : public Algorithms {
public:
	int BinarySearch(int[], int, int);
	void BinarySearchDescription();
	void BinarySearchExplained(int[], int, int);
};

#endif
