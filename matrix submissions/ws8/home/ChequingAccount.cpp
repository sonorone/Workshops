// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
    ChequingAccount::ChequingAccount(double b, double tFee, double mFee) : Account(b) {
        trxFee = tFee > 0 ? tFee : 0.0;
        monthlyFee = mFee > 0 ? mFee : 0.0;
    }
	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
    bool ChequingAccount::credit(double c) {
        double preCredit = balance();
        Account::credit(c);
        // only charged trx fee if value debited was greater than 0
        if (preCredit < balance())
            Account::debit(trxFee);
        return (balance() - trxFee - c) == preCredit;

    }
	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
    bool ChequingAccount::debit(double d) {
        double preDebit = balance();
        Account::debit(d);
        // only charged trx fee if value debited was greater than 0
        if (preDebit > balance())
            Account::debit(trxFee);
        return (balance() + trxFee + d) == preDebit;
    }
	// monthEnd debits month end fee
	//
    void ChequingAccount::monthEnd() {
        Account::debit(monthlyFee + trxFee);
    }
	// display inserts account information into ostream os
	//
    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << std::endl;
        os << "Balance: $";
        os.setf(std::ios::fixed);
        os.precision(2);
        os << balance() << std::endl
        << "Per Transaction Fee: " << trxFee << std::endl
        << "Monthly Fee: " << monthlyFee << std::endl;
    }
}
