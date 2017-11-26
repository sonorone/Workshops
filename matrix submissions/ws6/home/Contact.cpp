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
    // sets object to an empty state
    Contact::Contact() {
        name[0] = '\0';
        phone = nullptr;
        np = 0;
    }
    // This constructor allocates enough memory dynamically to hold only the valid phone numbers
    Contact::Contact(const char* cName, const long long* cNum, int noOfP) {
        bool validName = (cName == nullptr || cName[0] == '\0') ? false : true;
        if (validName) {
            int copy = 0, ref[noOfP];
            np = 0;
            copyShallow(cName, size, np);
            if (cNum != nullptr) {
                for (int i = 0; i < noOfP; ++i) {
                    bool valid = isValid(&cNum[i]);
                    if (valid) {
                        ref[i] = i;
                        ++np;
                    }
                    else
                        ref[i]= -1;
                }
                if (np > 0) {
                    phone = new long long[np];
                    for (int i = 0; i < noOfP; ++i) {
                        if (ref[i] > -1 && copy <= np)
                            phone[copy++] = cNum[i];
                    }
                }
            }
            else {
                phone = nullptr;
            }
        }
        else {
            phone = nullptr;
            *this = Contact();
        }
    }
    // cleans after itself
    Contact::~Contact() {
        delete [] phone;
    }
    // check if in empty state
    bool Contact::isEmpty() const { return (name[0] == '\0') ? true : false ; }
    // display contact content
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
    // phone # validation
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
    // copy constructor
    Contact::Contact(const Contact& src) {
        phone = nullptr;
        *this = src;
    }
    // copy assignment operator
    Contact& Contact::operator=(const Contact& src) {
        if (this != &src) {
            delete [] phone;
            assign(src);
        }
        return *this;
    }
    // copy shallow members
    void Contact::copyShallow(const char* fullName, int cap, int noOfP) {
        strncpy(name, fullName, cap-1);
        name[cap-1] = '\0';
        np = noOfP;
    }
    // copy shallow and dynamic memory if any
    void Contact::assign(const Contact& src) {
        copyShallow(src.name, size, src.np);
        if (src.phone != nullptr) {
            phone = new long long[np];
            for (int i = 0; i < src.np; ++i)
                phone[i] = src.phone[i];
        }
        else {
            phone = nullptr;
        }
    }
    // overloaded +=, copies LL into the object as a new phone
    Contact& Contact::operator+=(const long long newNo) {
        bool valid = isValid(&newNo);
        if (valid) {
            np++;
            long long* tmpPhone = nullptr;
            tmpPhone = new long long[np];
            for (int i = 0; i < np-1; ++i) {
                tmpPhone[i] = phone[i];
            }
            tmpPhone[np-1] = newNo;
            delete [] phone;
            phone = tmpPhone;
        }
        return *this;
    }
}
