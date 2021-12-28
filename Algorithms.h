#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::to_string;

/*
	Algorithms class type which serves as a base class
	for various algorithms so that its functions inherited.
*/
class Algorithms {
protected:
	void pause();
	string space(int);
public:
	void printList(int[], int);
};

// Function for applying text edits.
void edit(const char *, string, string="", string="");
// Variables for colors coding.
static const char *red = "\033[1;31m";
static const char *green = "\033[1;32m";
static const char *yellow = "\033[1;33m";
static const char *orange = "\033[1;34m";
static const char *cyan = "\033[1;36m";
static const char *purple = "\033[1;35m";
static const char *reset = "\033[0m";

#endif
