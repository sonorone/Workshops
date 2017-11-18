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
            int tmp = 0, sum = 0, sumCheck = 0;
            int even = 0, odd = 0, checkd = sin%10, shorted = sin;
            
            for (int i = 0; i < 9; ++i) {
                shorted /= 10;
                tmp = shorted%10;
                if (tmp%2 == 0)
                    even += int(tmp*2/10) + int(tmp*2%10);
                else
                    odd += tmp;
            }
            sum = even + odd;
            sumCheck = int(sum/10) * 10 + 10;
            ((sumCheck - sum) == checkd) ? isValid = true : isValid = false;
            counter = 0;
        
        if (isValid && familyName != nullptr && familyName[0] != '\0' && givenName != nullptr && givenName[0] != '\0') {
            strncpy(famName, familyName, max_name_length);
                famName[max_name_length] = '\0';
            strncpy(givnName, givenName, max_name_length);
                givnName[max_name_length] = '\0';
				sinNo = sin;
				// ++counter;
            }
        }
        else {
            sinNo = 0;
			counter = 0;
        }
    }
    void CRA_Account::set(int year, double balance) {
        if (sinNo != 0 && counter < max_yrs) {
            tax_yrs[counter] = year;
            balance_yrs[counter] = balance;
            counter++;
        }
    }
    bool CRA_Account::isEmpty() const { return (sinNo >= min_sin && sinNo <= max_sin) ? false : true; }
    void CRA_Account::display() const {
        if (sinNo != 0) {
            cout << "Family Name: " << famName << endl;
            cout << "Given Name : " << givnName << endl;
            cout << "CRA Account: " << sinNo << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
            for (int i = 0; i < counter; ++i) {
                if (balance_yrs[i] > 2)
                    cout << "Year (" << tax_yrs[i] << ") balance owing: " << balance_yrs[i] <<  endl;
                else if (balance_yrs[i] < (-2))
                    cout << "Year (" << tax_yrs[i] << ") refund due: " << balance_yrs[i] * (-1) << endl;
                else
                    cout << "Year (" << tax_yrs[i] << ") No balance owing or refund due!" << endl;
            }
			cout.unsetf(ios::fixed);
			cout.precision(6);
        }
        else
            cout << "Account object is empty!" << endl;
    }
}
