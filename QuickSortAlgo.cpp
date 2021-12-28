#include "QuickSortAlgo.h"

/*
	Function that parts a given array by swapping so that all of the elements
	less than the pivot will be on the left-hand side and all of the elements
	greater than the pivot will be on the right-hand side.
*/
int QuickSortAlgo::partition(int sub[], int start, int end) {
	int pivot = sub[end];	// Choose a pivot (rightmost).
	int p_index = start;	// Index to represent left-hand side indices.

	// Loop through the array.
	for(int i = start; i < end; i++)
		// Places all less than elements on the left-hand side of the array.
		if(sub[i] <= pivot) {
			std::swap(sub[i], sub[p_index]);
			p_index++;
		}
	// Then swap so that the pivot is in the middle, where all less is to the left
	// and all greater is to the right.
	std::swap(sub[p_index], sub[end]);

	return p_index;	// Return the pivot.
}

/*
	Detailed walkthrough of how the partition function parts an array
	so that all less-than elements are on the left-side of a pivot and all
	greater-than elements are on the right-side of a pivot.
*/
int QuickSortAlgo::partitionExplained(int sub[], int start, int end) {
	edit(orange, "\npartition() function called:\n");
	cout << "Initialize a pivot variable for this subarray.\n";
	int pivot = sub[end];
	int p_index = start;
	cout << "pivot = ", edit(red, to_string(sub[end]), "\n");
	pause();

	cout << "\nObserve a loop which iterates from the start of the subarray to\n";
	cout << "the end. If the ", edit(purple, "p_index element", " is less than the pivot, swap w/\n");
	cout << "the ", edit(cyan, "current base element", ". Observe this in action.\n");
	pause();

	for(int i = start; i < end; i++) {
		cout << "\nObserve the subarray:\n";
		cout << "[ ";
		// Print the list & highlight special elements.
		for(int j = start; j <= end; j++) {
			if(sub[j] == pivot)
				cout << red << sub[j] << " " << reset;
			else if(j == i)
				cout << cyan << sub[j] << " " << reset;
			else if(j == p_index)
				cout << purple << sub[j] << " " << reset;
			else
				cout << sub[j] << " ";
		}
		cout << "]\n  ";
		// Print the pivot, and p_index pointer symbols for the list.
		for(int j = start; j <= end; j++) {
			if(sub[j] == pivot)
				cout << red << "P" << space(sub[j]) << reset;
			else if(j == p_index)
				cout << purple << "^" << space(sub[j]) << reset;
			else
				cout << space(sub[j]) << " ";
		}
		cout << "\n  ";
		// Print the current element pointer symbol for the list.
		for(int j = start; j <= end; j++) {
			if(j == i)
				cout << cyan << "^" << space(sub[j]) << reset;
			else
				cout << space(sub[j]) << " ";
		}
		cout << "\n";

		if(sub[i] <= pivot) {
			edit(cyan, to_string(sub[i]), " <= ");
			edit(red, to_string(sub[end]), "\n");
			cout << "Swap ", edit(cyan, to_string(sub[i]), " & ");
			edit(purple, to_string(sub[p_index]), "\n");
			std::swap(sub[i], sub[p_index++]);
			pause();
		}
		else {
			edit(cyan, to_string(sub[i]), " > ");
			edit(red, to_string(sub[end]), "\n");
			cout << "Don't swap.\n";
			pause();
		}
	}

	cout << "\nThe ", edit(cyan, "current base element", " has reached the end.\n");
	cout << "Swap the ", edit(purple, "p_index element ("+to_string(sub[p_index])+")", " & ");
	edit(red, "pivot ("+to_string(pivot)+")", ".\nThat way, the pivot is in the middle.\n");
	std::swap(sub[p_index], sub[end]);
	cout << "[ ";
	// Print the list.
	for(int j = start; j <= end; j++) {
		if(sub[j] == pivot)
			cout << red << sub[j] << " " << reset;
		else
			cout << sub[j] << " ";
	}
	cout << "]\n";
	pause();

	return p_index;	// Return the pivot.
}

/*
	Algorithm that sorts a given array by parting arrays.
*/
void QuickSortAlgo::QuickSort(int sub[], int start, int end) {
	if(start >= end)	// Base condition triggers when there's only 1 element.
		return;			// Return back up the call stack.

	int pivot = partition(sub, start, end);	// Sort the following subarrays based on the partition.
	QuickSort(sub, start, pivot-1);			// Sort subarray less than the pivot.
	QuickSort(sub, pivot+1, end);			// Sort subarray more than the pivot.
}

/*
	Brief description of quick sort algorithm.
*/
void QuickSortAlgo::QuickSortDescription() {
	cout << "\nWhen you see [...], input any key to continue.\n";
	pause();

	cout << "\nQuick sort is a divide-and-conquer algorithm which halves an array into\n";
	cout << "2 subarrays. A \"pivot\" is selected from the end of an array which will\n";
	cout << "be the value that the rest of the array gets compared to. Thus, all elements\n";
	cout << "less than and greater than the pivot will have into its own subarray,\n";
	cout << "respectively. These steps are recursively repeated onto each subarray created\n";
	cout << "until we have a list of sorted pivots.\n";
	pause();
}

/*
	Detailed walkthrough of how the Quick Sort algorithm sorts a list.
*/
void QuickSortAlgo::QuickSortExplained(int sub[], int start, int end) {
	edit(orange, "\nQuickSort() function called:\n");

	if(start >= end) {
		cout << "This subarray only has one element. Now return back up the call stack.\n";
		cout << red << sub[start] << endl << reset;
		pause();
		return;
	}

	cout << "We will now part this array into 2 subarrays and return the pivot.\n";
	pause();
	int pivot = partitionExplained(sub, start, end);	// Get pivot & part the subarray.

	cout << "\nNow that this array is parted into 2 more subarrays, we will call the first\n";
	cout << "Quick Sort to sort left of the pivot.\n";
	cout << "[ ";
	for(int i = start; i <= pivot-1; i++)
		cout << sub[i] << " ";
	cout << "]\n";
	pause();
	QuickSortExplained(sub, start, pivot-1);	// Sort subarray less than the pivot.

	cout << "\nWe will call the second Quick Sort to sort right of the pivot.\n";
	cout << "[ ";
	for(int i = pivot+1; i <= end; i++)
		cout << sub[i] << " ";
	cout << "]\n";
	cout << "\nWe will now call the second Quick Sort to sort right of the pivot. This will sort\n";
	cout << "from right after the pivot to the end of the array.\n";
	pause();
	QuickSortExplained(sub, pivot+1, end);	// Sort subarray greater than the pivot.

	cout << "Second Quick Sort is finished, the array is now: [ ";
	// Print the list.
	for(int i = start; i <= end; i++)
		cout << sub[i] << " ";
	cout << "]\n";
}
