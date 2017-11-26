/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File tools.cpp
// Date	9/13/2017
// Student: Murawiecki, Damian
// Course: OOP244SEE
***********************************************************************/
#include <iostream>
using namespace std;
#include "tools.h"

// Performs a fool-proof integer entry
int getInt(int min, int max) {
	int val;
	bool done = false;
	while (!done) {
		cin >> val;
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid Integer, try again: ";
		}
		else {
			if (val < min || val > max) {
				cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
			}
			else {
				done = true;
			}
		}
		cin.ignore(1000, '\n');
	}
	return val;
}

// interface of the SeneGraph program
int menu() {
	cout << "1- Number of Samples" << endl;
	cout << "2- Sample Entry" << endl;
	cout << "3- Draw Graph" << endl;
	cout << "0- Exit" << endl;
	cout << "> ";
	return getInt(0, 3);
}
