
#include "MergeSortAlgo.h"

/*
	Algoithm that sorts a given array.
*/
void MergeSortAlgo::MergeSort(int list[], int temp[], int low, int high) {
	// Base case: If array size is 1, then it's already sorted.
	if(low == high)
		return;

	int mid = (low + ((high-low) / 2));	// Get mid index.

	// The following will recursively split the runs into 2 halves until
	// the array size is 1, then merge and return up the call stack.

	MergeSort(list, temp, low, mid);	// split/merge left-half
	MergeSort(list, temp, mid+1, high);	// split/merge right-half
	merge(list, temp, low, mid, high);	// marge the 2 half runs
}

/*
	Function that merges two halves subarrays in order.
*/
void MergeSortAlgo::merge(int list[], int temp[], int low, int mid, int high) {
	int index = low;
	int LH = low;
	int RH = mid+1;

	// Store values until one of the subarrays is iterated over.
	while(LH <= mid && RH <= high) {
		if(list[LH] <= list[RH])
			temp[index++] = list[LH++];	// Leftside has the lesser value, store it.
		else
			temp[index++] = list[RH++];	// Rightside has the lesser value, store it.
	}

	// Copy remaining elements of leftside if necessary, unnecessary for rightside b/c
	// it'd already be in its sorted position.
	while(LH <= mid)
		temp[index++] = list[LH++];

	// Update original array.
	for(int i = low; i <= high; i++)
		list[i] = temp[i];
}

/*
	Brief description of merge sort algorithm.
*/
void MergeSortAlgo::MergeSortDescription() {
	cout << "\nWhen you see [...], input any key to continue.\n";
	pause();
	
	cout << "\nMerge sort is a divide-and-conquer algorithm which halves an array\n";
	cout << "into 2 subarrays. Eventually the array will be divided into subarrays\n";
	cout << "of size 1, which is considered sorted. These subarrays will then merge\n";
	cout << "into sorted subarrays until eventually merging into a single sorted array.\n";
	pause();
}

/*
	Detailed step-by-step walkthrough of a merge sort algorithm.
*/
void MergeSortAlgo::MergeSortExplained(int list[], int temp[], int low, int high) {
	edit(orange, "\nMergeSort() function called:\n");

	if(low == high) {
		cout << "Subarray has been split into size of 1.\n";
		cout << "From here, return back up the call stack.\n";
		pause();
		return;
	}
	cout << "Initialize the mid value depending on the given low & high.\n";
	cout << "mid = ", edit(cyan, to_string(low), " + ((");
	edit(cyan, to_string(high), " - ");
	edit(cyan, to_string(low), ") / 2)\n");
	int mid = (low + ((high-low)/2));
	cout << "mid = ", edit(purple, to_string(mid), "\n[ ");
	// Print the entire list.
	for(int i = low; i <= high; i++) {
		if(i == mid)
			cout << purple << list[i] << " " << reset;
		else if(i == low || i == high)
			cout << cyan << list[i] << " " << reset;
		else
			cout << list[i] << " ";
	}
	cout << "]\n";
	pause();

	cout << "\nCommence splitting on ", edit(yellow, "leftside", " of given array:\n[ ");
	// Print the left-half of the list.
	for(int i = low; i <= mid; i++) {
		if(i == mid)
			cout << purple << list[i] << " " << reset;
		else if(i == low)
			cout << cyan << list[i] << " " << reset;
		else
			cout << list[i] << " ";
	}
	cout << "]\n";
	pause();
	MergeSortExplained(list, temp, low, mid); // recursive call on left-half

	cout << "\nCommence splitting on ", edit(red, "rightside", " of given array:\n[ ");
	// Print the right-half of the list.
	for(int i = mid+1; i <= high; i++) {
		if(i == high)
			cout << cyan << list[i] << " " << reset;
		else
			cout << list[i] << " ";
	}
	cout << "]\n";
	pause();
	MergeSortExplained(list, temp, mid+1, high); // recursive call on right-half

	cout << "\nOur subarrays are split, now we will merge them together in order.\n";
	pause();
	mergeExplained(list, temp, low, mid, high); // merge the halves
}

/*
	Detailed step-by-step walkthrough of how the two halves subarrays are
	merged together.
*/
void MergeSortAlgo::mergeExplained(int list[], int temp[], int low, int mid, int high) {
	edit(orange, "\nmerge() function called:\n");
	int index = low;
	int left_i = low;
	int right_i = mid+1;

	cout << "The following loop will merge the 2 subarrays by inserting the lesser\n";
	cout << "elements first. Once one of the subarrays is fully iterated over, then\n";
	cout << "break. Observe this in action.\n";
	pause();

	while(left_i <= mid && right_i <= high) {
		cout << "\nObserve the array:\n";
		cout << "[ ";
		// Print the left-half of the list.
		for(int i = low; i <= mid; i++) {
			if(i == left_i)	
				cout << yellow << list[i] << " " << reset;
			else if(i == mid)
				cout << purple << list[i] << " " << reset;
			else if(i == index)
				cout << green << list[i] << " " << reset;
			else
				cout << list[i] << " ";
		}
		cout << "] [ ";
		// Print the right-half of the list.
		for(int i = mid+1; i <= high; i++) {
			if(i == right_i)
				cout << red << list[i] << " " << reset;
			else if(i == index)
				cout << green << list[i] << " " << reset;
			else
				cout << list[i] << " ";
		}
		cout << "]\n  ";
		// Print the letter symbols for the left-half of the list.
		for(int i = low; i <= mid; i++) {
			if(i == left_i)
				cout << yellow << "L" << space(list[i]) << reset;
			else if(i == mid)
				cout << purple << "M" << space(list[i]) << reset;
			else
				cout << space(list[i]) << " ";
		}
		cout << "    ";
		// Print the letter symbols for the right-half of the list.
		for(int i = mid+1; i <= high; i++) {
			if(i == right_i)
				cout << red << "R" << space(list[i]) << reset;
			else
				cout << space(list[i]) << " ";
		}
		cout << "\n  ";
		// Print the pointer symbols for the left-half of the list.
		for(int i = low; i <= mid; i++) {
			if(i == index)
				cout << green << "^" << space(list[i]) << reset;
			else
				cout << space(list[i]) << " ";
		}
		cout << "    ";
		// Print the pointer symbols for the right-half of the list.
		for(int i = mid+1; i <= high; i++) {
			if(i == index)
				cout << green << "^" << space(list[i]) << reset;
			else
				cout << space(list[i]) << " ";
		}
		cout << "\n";

		if(list[left_i] <= list[right_i]) {
			edit(yellow, to_string(list[left_i]), " <= ");
			edit(red, to_string(list[right_i]), "\n");
			cout << "Store ", edit(yellow, to_string(list[left_i]), " into temp array.\n");
			temp[index++] = list[left_i++];
			pause();
		}
		else {
			edit(yellow, to_string(list[left_i]), " > ");
			edit(red, to_string(list[right_i]), "\n");
			cout << "Store ", edit(red, to_string(list[right_i]), " into temp array.\n");
			temp[index++] = list[right_i++];
			pause();
		}
	}
	if(left_i > mid) {
		cout << "\nThe left subarray is fully iterated over. So the rest of the righthand\n";
		cout << "elements are already in its order in the temp array.\n";
		pause();
	}
	else {
		cout << "\nThe right subarray is fully iterated over. So store the rest of the lefthand\n";
		cout << "elements into the temp array.\n";
		pause();
	}

	while(left_i <= mid) {
		temp[index++] = list[left_i++];
	}

	cout << "The array is now: [ ";
	// Print the list.
	for(int i = low; i <= high; i++) {
		cout << temp[i] << " ";
	}
	cout << "]\n";
	// Copy temp array into original array to update.
	for(int i = low; i <= high; i++) {
		list[i] = temp[i];
	}
}
