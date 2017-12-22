// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the Account class
///////////////////////////////////////////////////

#include "Account.h"

namespace sict {

	Account::Account(double b) {
		if (b > 0) 
			balance = b;
		else
			balance = 0;
	}

	bool Account::credit(double c) {
		bool success = false;
		if (c > 0) {
			balance += c;
			success = true;
		}
		return success;
	}

	bool Account::debit(double d) const {
		bool success = false;
		if (c > 0) {
			balance -= d;
			success = true;
		}
		return success;
	}

	double Account::balance() const {
		return balance;
	}
}
