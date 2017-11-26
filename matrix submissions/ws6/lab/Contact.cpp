/*
 * Workshop:    Class with resource.
 * Student:     Damian Murawiecki
 * File:        Contact.cpp
 * Comments:    This class holds information about a person and his/her phone numbers.
 * Date:        October 18, 2017
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "Contact.h"

namespace sict {
    
    Contact::Contact() {
        name[0] = '\0';
        phone = nullptr;
        np = 0;
    }
    // This constructor allocates enough memory dynamically to hold only the valid phone numbers
    Contact::Contact(const char* cName, const long long* cNum, int noOfP) {
        bool validName = (cName == nullptr || cName[0] == '\0') ? false : true;
        if (validName) {
            int copy = 0;
            int ref[noOfP];
            np = 0;
            // copy name
            strncpy(name, cName, size-1);
            name[size-1] = '\0';
            // validate each phone number in an array and copy into dynamic memory if valid
            if (cNum != nullptr) {
                for (int i = 0; i < noOfP; ++i) {   // 1: access the const array and check each element if valid
                    bool valid = isValid(&cNum[i]);
                    if (valid) {                    // if valid... copy index (i), if not, assign -1
                        ref[i] = i;
                        ++np;
                    }
                    else {
                        ref[i]= -1;
                    }
                }
                if (np > 0) {
                    phone = new long long[np];
                    for (int i = 0; i < noOfP; ++i) {
                        if (ref[i] > -1 && copy <= np)
                            phone[copy++] = cNum[i];
                    }
                }
                else {
                    phone = nullptr;
                }
            }
            else {
                phone = nullptr;
            }
        }
        else {
            *this = Contact();
        }
    }
    Contact::~Contact() {
        delete [] phone;
    }
    bool Contact::isEmpty() const { return (name[0] == '\0') ? true : false ; }
    void Contact::display() const {
        bool isEmptyCon = isEmpty();
        if (isEmptyCon) { cout << "Empty contact!" << endl; }
        else {
            cout << name << endl;
            for (int i = 0; i < np; ++i) {
                cout << "(+" << int(phone[i] / 10000000000LL) << ") "
                << int(phone[i]/10000000%1000) << " "
                << int(phone[i]/10000%1000) << "-" << flush;
                cout.setf(ios::fixed);
                cout.fill('0');
                cout.width(4);
                cout << int(phone[i]%10000) << endl;
                cout.fill(' ');
                cout.unsetf(ios::fixed);
            }
        }
    }
    bool Contact::isValid(const long long* num) const {
        bool valid = false;
        if (*num > 10000000000LL && *num < 999999999999LL) {
            int cc = int(*num / 10000000000LL);
            int ac = int(*num / 10000000 % 1000);
            int n = int(*num % 10000000);
            if (cc > 0 && cc <= 99 && ac >= 100 && ac <= 999 && n >= 1000000 && n <= 9999999)
                valid = true;
        }
        return valid;
    }
}
