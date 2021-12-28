#include "Menu.h"

/*
	Main program that allows a user to choose an algorithm
	to walk through.
*/
int main() {
	Menu m;

	cout << "**************************************\n";
	cout << "Welcome to the Algorithm Demonstrator!\n";
	cout << "**************************************\n\n";

	// Loop the main menu.
	do {
		m.mainMenuPrompt();
	} while(m.mainMenuSelect());

	return 0;
}

