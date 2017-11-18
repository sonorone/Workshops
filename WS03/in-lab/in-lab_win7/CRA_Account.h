/**********************************************************
// Workshop 3: Classes and Privacy
// Student: Murawiecki, Damian (121531164)
// CRA_Account.h
// 2017/09/27
**********************************************************/

#include <iostream>
using namespace std;
#ifndef SCIT_CRA_ACCOUNT_H

namespace sict {
#define max_name_length 40
#define min_sin 100000000	// smallest SIN#
#define max_sin 999999999	// highest SIN#

	class CRA_Account {
		char famName[max_name_length];
		char givnName[max_name_length];
		unsigned long int sinNo;
	public:
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !SCIT_CRA_ACCOUNT_H
