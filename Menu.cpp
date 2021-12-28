#include "Menu.h"

/*
	Prompt main menu.
*/
void Menu::mainMenuPrompt() {
	cout << "----------------------------------------\n";
	cout << "[1] Demonstrate Binary Search Algorithm.\n";
	cout << "[2] Demonstrate Merge Sort Algorithm.\n";
	cout << "[3] Demonstrate Quick Sort Algorithm.\n";
	cout << "[Q] Quit.\n";
	cout << "----------------------------------------\n";
	cout << "Select: ";
}

/*
	Make a main menu selection.
*/
bool Menu::mainMenuSelect() {
	char input;
	cin >> input;

	// Binary Search
	if(input == '1') {
		BinarySearchAlgo Algo;
		int sortedlist[10] = {2,4,6,8,10,12,14,16,18,20};
		int size = 10;
		int target = 18;

		cout << "----------------------------------------\n";
		cout << "Observe the following sorted array.\n";
		Algo.printList(sortedlist, size);
		cout << "We want to see if our target, ";
		edit(red, "16", " is in the sorted list by using\n");
		cout << "the Binary Search Algorithm.\n";

		// Call functions to demonstrate the binary search algorithm.
		Algo.BinarySearchDescription();
		Algo.BinarySearchExplained(sortedlist, size, target);
	}
	// Merge Sort
	else if(input == '2') {
		MergeSortAlgo Algo;
		int list[7] = {24,30,11,7,0,23,21};
		int copylist[7] = {24,30,11,7,0,23,21};
		int size = 7;
		int low = 0, high = size-1;

		cout << "----------------------------------------\n";
		cout << "Observe the folowing unsorted array.\n";
		Algo.printList(list, size);
		cout << "We want to sort it using the Merge Sort Algorithm.\n";

		// Call functions to demonstrate the merge sort algorithm.
		Algo.MergeSortDescription();
		Algo.MergeSortExplained(list, copylist, low, high);
	}
	// Quick Sort
	else if(input == '3') {
		QuickSortAlgo Algo;
		int list[7] = {24,30,11,7,0,23,21};
		int size = 7;
		int low = 0, high = size-1;

		cout << "----------------------------------------\n";
		cout << "Observe the following unsorted array.\n";
		Algo.printList(list, size);
		cout << "We want to sort it using the Quick Sort Algorithm.\n";

		// Call functions to demonstrate the quick sort algorithm.
		Algo.QuickSortDescription();
		Algo.QuickSortExplained(list, low, high);
	}
	// Quit program.
	else if (input == 'Q' || input == 'q') {
		cout << "\nThank you for using the Algorithm Demonstrator!\n";
		return false;
	}
	else
		edit(red, "ERROR: ", "Invalid input, please retry.\n");

	return true;	// In all other cases, loop the menu.
}
