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

	Account::Account() { acctBalance = 0; }
	Account::Account(double b) { (b > 0) ? acctBalance = b : acctBalance = 0; }
    bool Account::credit(double c) { return (c>0) ? acctBalance += c : false; }
    bool Account::debit(double d) { return (d>0) ? acctBalance -= d : false; }
	double Account::balance() const { return acctBalance; }
	void Account::setBalance(double b, bool isCredit) {
		if (isCredit)
			acctBalance += b;
		else
			acctBalance -= b;
    }
	void Account::display(std::ostream& os) const {}
}
