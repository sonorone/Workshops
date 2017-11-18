/*
 * Workshop:    Class with resource.
 * Student:     Damian Murawiecki
 * File:        Contact.h
 * Comments:    This class holds information about a person and his/her phone numbers.
 * Date:        October 18, 2017
 */

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
    const int size = 20;

    class Contact {
        char name[size];
        long long* phone;
        int np;
        bool isValid(const long long*) const;
        void copyShallow(const Contact&);
        void copyDynamic(const Contact&);
    public:
        Contact();
        Contact(const char*, const long long*, int);
        Contact(const Contact&);
        Contact& operator=(const Contact&);
        Contact& operator+=(const long long);
        ~Contact();
        bool isEmpty() const;
        void display() const;
    };
}
#endif // SICT_CONTACT_H








