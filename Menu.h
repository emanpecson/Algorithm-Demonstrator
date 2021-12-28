#ifndef MENU_H
#define MENU_H

#include "Algorithms.h"
#include "BinarySearchAlgo.h"
#include "MergeSortAlgo.h"
#include "QuickSortAlgo.h"

/*
	Menu struct type with basic functions.
*/
struct Menu {
	void mainMenuPrompt();
	bool mainMenuSelect();
};

#endif
