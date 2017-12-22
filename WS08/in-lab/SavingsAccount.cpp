// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the SavingsAccount class
///////////////////////////////////////////////////

#include "SavingsAccount.h"

namespace sict {

	SavingsAccount::SavingsAccount(double b, double i) {

		this.balance = b;

		if (i > 0)
			interest = i;
		else
			interest = 0.0;
	}

	void SavingsAccount::monthEnd() {
		balance += (balance * interest);
	}

	void SavingsAccount::display(std::ostream& os) {
		os << "Account type: Savings" << endl;
		os << "Balance: $";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << balance << endl
		<< "Intereste Rate (%): " << interest << endl;
	}
}