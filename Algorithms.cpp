#include "Algorithms.h"

/*
	Non-member function that applies an edit to a string. The first argument
	is the edit to apply, the second argument is the text to apply it too,
	the optional third argument is a following text which the edit doesn't
	get applied to. 
*/
void edit(const char *edit, string str_edited, string str_default, string end) {
	const char *reset = "\033[0m";
	cout << edit << str_edited << reset << str_default << end;
}

/*
	Outputs a string of spaces for the length of the item passed. This
	function is used to help showcase certain elements in a list.
*/
string Algorithms::space(int elem) {
	string space;
	for(int i = 0; i < int(to_string(elem).size()); i++)
		space += " ";
	return space;
}

/*
	Practical function to print a list between brackets.
*/
void Algorithms::printList(int list[], int size) {
	cout << "[ ";
	for(int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << "]\n";
}

/*
	Used to force user to input something before continuing.
*/
void Algorithms::pause() {
	string key;
	cout << "...";
	cin >> key;
}
