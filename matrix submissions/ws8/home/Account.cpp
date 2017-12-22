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
    // credit (add) an amount to the account balance and charge fee
    // returns bool indicating whether money was credited
    //
    bool Account::credit(double c) {
        double preCredit = balance();
        acctBalance += c;
        return preCredit < balance();
    }
    // debit (subtract) an amount from the account balance
    // returns bool indicating whether money was debited
    //
    bool Account::debit(double d) {
        double preDebit = balance();
        acctBalance -= d;
        return preDebit > balance();
    }
	double Account::balance() const { return acctBalance; }
    // display inserts account information into ostream os
    //
	void Account::display(std::ostream& os) const {}
}
