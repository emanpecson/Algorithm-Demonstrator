#include "BinarySearchAlgo.h"

/*
	Algoithm that searches for an element within a sorted list.
*/
int BinarySearchAlgo::BinarySearch(int list[], int size, int target) {
	int low = 0;		// minimum index
	int high = size-1;	// maximum index

	while(low <= high) {
		int mid = (low + high) / 2;

		if(list[mid] == target)
			return mid;		// return mid index
		else if(list[mid] < target)
			low = mid+1;	// disclude the left side
		else
			high = mid-1;	// disclude the right side
	}
	return -1;	// return when loop is exhausted, target not found
}

/*
	Brief description of binary search algorithm.
*/
void BinarySearchAlgo::BinarySearchDescription() {
	cout << "\nWhen you see [...], input any key to continue.\n";
	pause();

	cout << "\nBinary search is a divide-and-conquer algorithm which makes\n";
	cout << "searching for a target in a sorted list much faster by halving\n";
	cout << "the search space with each iteration\n";
	pause();
}

/*
	Detailed step-by-step walkthrough of a binary search algorithm.
*/
void BinarySearchAlgo::BinarySearchExplained(int list[], int size, int target) {
	edit(orange, "\nBinarySearch() function called:\n");
	bool success = false;

	cout << "The variables that will help us in this process is a ";
	edit(cyan, "low index\n", "(initialized at 0), a ");
	edit(cyan, "high index ", "(initialized at size-1), and a\n");
	edit(purple, "mid index", ".\n");
	int low = 0;
	int high = size-1;
	int mid;
	pause();

	cout << "\nIn a loop, we will compare the value at the ", edit(purple, "mid index", " to the ");
	edit(red, "target ("+to_string(target)+")", ".\n");
	cout << "If they're equal, then we're done and we just return that mid index.\n";
	cout << "But in the case that the middle element is less than the target, then discard the\n";
	cout << "search space less than the target by setting the low index to mid + 1. In the\n";
	cout << "case that the middle element is greater than the target, then discard the search\n";
	cout << "space greater than the target by setting the high index to mid - 1.\n";
	pause();

	cout << "\nThis process will repeat until eventually the middle element equals the\n";
	cout << "target element, or the element wasn't found. Observe this in action:\n";
	pause();

	while(low <= high && !success) {
		cout << "\nGet the value of the mid index:\n";
		cout << "mid = (";
		edit(cyan, to_string(low), " + ");
		edit(cyan, to_string(high), ") / 2\n");
		mid = (low + high) / 2;
		cout << "mid = ";
		edit(purple, to_string(mid), "\n");
		pause();

		cout << "\nObserve our search space:\n";
		// Output the list.
		cout << "[ ";
		for(int i = low; i <= high; i++) {
			if(i == mid)
				cout << purple << list[i] << " " << reset;
			else if(list[i] == target)
				cout << red << list[i] << " " << reset;
			else if(i == low || i == high)
				cout << cyan << list[i] << " " << reset;
			else
				cout << list[i] << " ";
		}
		cout << "]\n  ";
		// Output symbols to represent special elements in the list.
		for(int i = low; i <= high; i++) {
			if(i == mid)
				cout << purple << "M" << space(list[i]) << reset;
			else if(list[i] == target)
				cout << red << "T" << space(list[i]) << reset;
			else if(i == low)
				cout << cyan << "L" << space(list[i])  << reset;
			else if(i == high)
				cout << cyan << "H" << space(list[i]) << reset;
			else
				cout << space(list[i]) << " ";
		}
		cout << " \n";
		pause();
		
		cout << "\nCompare value to the target:\n";
		if(list[mid] == target) {
			edit(purple, to_string(list[mid]), " == ");
			edit(red, to_string(target), "\n");
			pause();

			cout << "\nTarget found at index ", edit(purple, to_string(mid), ".\nSuccessful search!\n");
			success = true;
			pause();
		}
		else if(list[mid] < target) {
			edit(purple, to_string(list[mid]), " < ");
			edit(red, to_string(target), "\n");
			pause();

			cout << "\nDiscard the less than side.\n";
			low = mid+1;
			cout << "Now our low index is: ", edit(cyan, to_string(low), "\n");
			pause();
		}
		else {
			edit(purple, to_string(list[mid]), " > ");
			edit(red, to_string(target), "\n");
			pause();
			
			cout << "\nDiscard the greater than side\n";
			high = mid-1;
			cout << "Now our high index is: ", edit(cyan, to_string(high), "\n");
			pause();
		}
	}
	if(!success) {
		cout << "\nThe loop has been exhausted. Target doesn't exist!\n";
		pause();
	}
}
