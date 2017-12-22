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

namespace sict {

	// define interest rate
	//
	const double interest = 0.05%;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* acct, double b) {

		/*
 			iAccount* CreateAccount (const char*, double) – 
 			this function receives the address of a C-style string 
 			that identifies the type of account to be created and 
 			the initial balance in the account and returns its address 
 			to the calling function. If the initial character of the 
 			string is ‘S’, this function creates a savings account 
 			in dynamic memory. If the string does not identify a type 
 			that is available, this function returns nullptr. 
		*/

		iAccount* p = nullptr;

		switch acct:
			case 'S':
				// TODO: Open Saving account in dynamic memory
				p = new SavingsAccount;
				break;

			case default;
				p = nullptr;
				break;

		return p;
	}
}
