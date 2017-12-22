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

	SavingsAccount::SavingsAccount() {
		setBalance(0.0, true);
		setIRate(0);
	};
	SavingsAccount::SavingsAccount(double b, double i) : Account(b) {
		//setBalance(b, true);

		if (i > 0)
			setIRate(i);
		else
			setIRate(0);
	}

	void SavingsAccount::monthEnd() {
		setBalance(balance() * getIRate(), true);
	}

	void SavingsAccount::display(std::ostream& os) {
		os << "Account type: Savings" << std::endl;
		os << "Balance: $";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << balance() << std::endl
		<< "Intereste Rate (%): " << getIRate() << std::endl;
	}

	void SavingsAccount::setIRate(double r = 0.0) {
		if (r > 0)
			interestRate = r;
	}

	double SavingsAccount::getIRate() const {
		return interestRate;
	}
}
