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

	Account::Account() {
		setBalance(0, true);
	}

	Account::Account(double b) {
		if (b > 0)
			acctBalance = b;
		else
			acctBalance = 0;
	}

	bool Account::credit(double c) {
		bool success = false;
		if (c > 0) {
			setBalance(c, true);
			success = true;
		}
		return success;
	}

	bool Account::debit(double d) {
		bool success = false;
		if (d > 0) {
			setBalance(d, false);
			success = true;
		}
		return success;
	}

	double Account::balance() const {
		return acctBalance;
	}

	void Account::setBalance(double b, bool isCredit) {
		if (isCredit) {
			acctBalance += b;
		}
		else {
			acctBalance -= b;
		}
	}

	void Account::display(std::ostream& os) const {
		//os << "Account type: Savings" << std::endl;
		os << "Balance: $";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << acctBalance << std::endl;
	}
}
