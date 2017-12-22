// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingAccount.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the SavingsAccount class
///////////////////////////////////////////////////

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
    
	class SavingsAccount : public Account {
		double interestRate;

	protected:
		void setIRate(double);
		double getIRate() const;

	public:
		SavingsAccount();
		SavingsAccount(double, double i = 0);
        void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
