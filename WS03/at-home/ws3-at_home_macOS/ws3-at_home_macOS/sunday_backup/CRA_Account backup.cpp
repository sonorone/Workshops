/**********************************************************
// Workshop 3: Classes and Privacy
// Student: Murawiecki, Damian (121531164)
// CRA_Account.cpp
// 2017/10/1
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		bool isValid = sin >= min_sin && sin <= max_sin ? true : false;
        if (isValid) {
            int d1,d2,d3,d4,d5,d6,d7,d8,cd,s1,s2,s3,s4,s1d1,s1d2,s2d1,s2d2,s3d1,s3d2,s4d1,s4d2,t1,t2,tt,ttr0;
            d1 = sin/100000000%10;
            d2 = sin/10000000%10;
            d3 = sin/1000000%10;
            d4 = sin/100000%10;
            d5 = sin/10000%10;
            d6 = sin/1000%10;
            d7 = sin/100%10;
            d8 = sin/10%10;
            cd = sin/1%10;
            s1 = d2*d2;
            s2 = d4*d4;
            s3 = d6*d6;
            s4 = d8*d8;
            if (s1 > 9) {
                s1d1 = s1/10;
                s1d2 = s1%10;
            } else {
                s1d1 = s1;
                s1d2 = 0;
            }
            if (s2 > 9) {
                s2d1 = s1/10;
                s2d2 = s1%10;
            } else {
                s2d1 = s1;
                s2d2 = 0;
            }
            if (s3 > 9) {
                s3d1 = s1/10;
                s3d2 = s1%10;
            } else {
                s3d1 = s1;
                s3d2 = 0;
            }
            if (s4 > 9) {
                s4d1 = s1/10;
                s4d2 = s1%10;
            } else {
                s4d1 = s1;
                s4d2 = 0;
            }
            t1 = s1d1 + s1d2 + s2d1 + s2d2 + s3d1 + s3d2 + s4d1 + s4d2;
            t2 = d1 + d3 + d5 + d7;
            tt = t1 + t2;
            ttr0 = (int)(tt/10) * 10 + 10;
            if ((ttr0 - tt) == cd)
                isValid = true;
            else
                isValid = false;
        }
        
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
            count_yrs = 0;
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
            for (int i = 0; i < count_yrs; ++i) {
                
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}
