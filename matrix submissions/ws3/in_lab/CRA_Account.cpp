/**********************************************************
// Workshop 3: Classes and Privacy
// Student: Murawiecki, Damian (121531164)
// CRA_Account.cpp
// 2017/09/27
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		bool isValid = sin >= min_sin && sin <= max_sin ? true : false;
		if (isValid) {
			sinNo = sin;
			if (familyName[0] != '\0') {
				strncpy(famName, familyName, max_name_length);
				famName[max_name_length] = '\0';
			}
			if (givenName[0] != '\0') {
				strncpy(givnName, givenName, max_name_length);
				givnName[max_name_length] = '\0';
			}
		}
		else {
			sinNo = 0;
		}
	}
	bool CRA_Account::isEmpty() const { return (sinNo >= min_sin && sinNo <= max_sin) ? false : true; }
	void CRA_Account::display() const {
		if (sinNo != 0) {
			cout << "Family Name: " << famName << endl;
			cout << "Given Name : " << givnName << endl;
			cout << "CRA Account: " << sinNo << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}