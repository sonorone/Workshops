// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
// Student: Damian Murawiecki 121531164
///////////////////////////////////////////////////
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    
    const double interest = 0.05;
    const double trx = 0.50;
    const double monthly = 2.00;

    iAccount* CreateAccount(const char* acct, double b) {
		iAccount* p = nullptr;
        
		switch (acct[0]) {
            case 'S':
                p = new SavingsAccount(b, interest);
                break;
            case 'C':
                p = new ChequingAccount(b, trx, monthly);
                break;
            default:
                break;
		}
		return p;
	}
}
