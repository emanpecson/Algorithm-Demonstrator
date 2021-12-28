#ifndef MERGESORTALGO_H
#define MERGESORTALGO_H

#include "Algorithms.h"

/*
	MergeSortAlgo class type which derives from the Algorithms class type.
	Provides functions for demonstrating the algorithm.
*/
class MergeSortAlgo : public Algorithms {
private:
	void merge(int[], int[], int, int, int);
	void mergeExplained(int[], int[], int, int, int);
public:
	void MergeSort(int[], int[], int, int);
	void MergeSortDescription();
	void MergeSortExplained(int[], int[], int, int);
};

#endif
