/**********************************************************
// Workshop 3: Classes and Privacy
// Student: Murawiecki, Damian (121531164)
// CRA_Account.h
// 2017/10/1
**********************************************************/

#include <iostream>
using namespace std;
#ifndef SCIT_CRA_ACCOUNT_H
#define SCIT_CRA_ACCOUNT_H
namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;	// smallest SIN#
	const int max_sin = 999999999;	// highest SIN#
    const int max_yrs = 4;          // max number of tax years

	class CRA_Account {
		char famName[max_name_length + 1];
		char givnName[max_name_length + 1];
		long int sinNo;
        int tax_yrs[max_yrs];
        double balance_yrs[max_yrs];
        int counter;
	public:
		void set(const char*, const char*, int);
        void set(int year, double balance);
        bool isEmpty() const;
		void display() const;
        
	};
}

#endif // !SCIT_CRA_ACCOUNT_H
