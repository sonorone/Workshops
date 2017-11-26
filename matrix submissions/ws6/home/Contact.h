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
        // copy shallow members
        void copyShallow(const char*, int, int);
        // copy shallow and dynamic memory if any
        void assign(const Contact&);
    public:
        // sets object to an empty state
        Contact();
        // This constructor allocates enough memory dynamically to hold only the valid phone numbers
        Contact(const char*, const long long*, int);
        // copy constructor
        Contact(const Contact&);
        // copy assignment operator
        Contact& operator=(const Contact&);
        // overloaded +=, copies LL into the object as a new phone
        Contact& operator+=(const long long);
        // cleans after itself
        ~Contact();
        // check if in empty state
        bool isEmpty() const;
        // phone # validation
        bool isValid(const long long*) const;
        // display contact content
        void display() const;
    };
}
#endif // SICT_CONTACT_H








