/*
 * Workshop:    Class with resource.
 * Student:     Damian Murawiecki
 * File:        Contact.cpp
 * Comments:    This class holds information about a person and his/her phone numbers.
 * Date:        October 18, 2017
 */

#include <cstdio>
using namespace std;
#include "Contact.h"

namespace sict {
    
    Contact::Contact() {
        name[0] = '\0';
        phone = nullptr;
        np = 0;
    }
    // This constructor allocates enough memory dynamically to hold only the valid phone numbers from the array received and copies the valid numbers into the allocated array;
    Contact::Contact(const char* cName, const long long* cNum, int noOfP) {
        bool validName = (cName[0] != '\0') ? true : false;
        if (validName) {
            int count = 0, ;
            int ref[noOfP];
            // 1: access the const array and check each element if valid
            for (int i = 0; i < noOfP; ++i) {
                bool valid;
                // is valid?
                valid = isValid(&cNum[i]);
                // if valid... copy index (i), if not, assign -1
                if (valid) {
                    ref[i] = i;
                    ++count;
                }
                else {
                    ref[i]= -1;
                }
            }
            // allocate dynamic memory and copy valid elements of const cNum array;
            phone = new long long[count];
            for (int i = 0; i < noOfP; ++i) {
                
                if (ref[i] > -1)
                    phone[i] = cNum[i];
            }
        }
        
    }
    Contact::~Contact() {
        delete [] phone;
        phone = nullptr;
    }
    bool Contact::isEmpty() const { return (name[0] == '\0') ? true : false ; }
    void Contact::display() const {
        
    }
    bool Contact::isValid(const long long* num) const {
        bool valid = false;
        if (*num < 10000000000LL && *num > 999999999999LL) {
            int cc = int(*num / 10000000000LL);
            int ac = int(*num / 10000000 % 1000);
            int n = int(*num % 10000000);
            if (cc > 0 && cc <= 99 && ac >= 100 && ac <= 999 && n >= 1000000 & n <= 9999999)
                valid = true;
        }
        return valid;
    }
    
    
}
