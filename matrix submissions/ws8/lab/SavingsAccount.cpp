// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the SavingsAccount class
///////////////////////////////////////////////////

#include <iostream>
#include "SavingsAccount.h"

namespace sict {
    // default constructor
	SavingsAccount::SavingsAccount() {
		setBalance(0.0, true);
        interestRate = 0.0;
	};
    // 2 param constructor, sets balance and interest rate
	SavingsAccount::SavingsAccount(double b, double i) : Account(b) {
        (i > 0) ? interestRate = i : interestRate = 0;
	}
    // this modifier calculates the interest earned on the current balance and credits the account with that interest.
	void SavingsAccount::monthEnd() { setBalance(balance() * interestRate, true); }
    // display account details to the console
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os << "Balance: $";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << balance() << std::endl
		<< "Interest Rate (%): " << interestRate*100 << std::endl;
	}
}
