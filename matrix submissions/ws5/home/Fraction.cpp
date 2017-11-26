/**
 * Workshop 5: operator overloading
 * Student: Murawiecki, Damian (121531164)
 * File: Fraction.cpp
 * 2017/10/11
 * Comments:    This class reperesents fractions.
 */

#include <iostream>
using namespace std;
#include "Fraction.h"

namespace sict {
    // default constructor: ensures the object is in a safe empty state
    Fraction::Fraction() {
        numerator = -1;
        denominator = 0;
    }
    // two arg constructor: validates the data...
    Fraction::Fraction(int num, int den) {
        if (num >= 0 && den > 0) {
            numerator = num;
            denominator = den;
            reduce();
        }
        else {
            *this = Fraction();
        }
    }
    // returns one of the two instance variables (higher)
    int Fraction::max() const { return numerator > denominator ? numerator : denominator; }
    // returns one of the two instance variables (lower)
    int Fraction::min() const { return numerator < denominator ? numerator : denominator; }
    // returns greater common dividor from within the Fraction type object
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }
    // reduces Fraction object to the minimal representation
    void Fraction::reduce() {
        int g = gcd();
        numerator /= g;
        denominator /= g;
    }
    // displays fraction
    void Fraction::display() const {
        Fraction temp(numerator,denominator);
        if (temp.numerator >= 0 && temp.denominator > 1)
            cout << temp.numerator << "/" << temp.denominator;
        else if (temp.numerator >= 0 && temp.denominator == 1)
            cout << temp.numerator;
        else if (temp.numerator == -1)
            cout << "no fraction stored";
    }
    // checks if object is not empty
    bool Fraction::isEmpty() const { return (numerator == -1) ? true : false; }
    // check if objects are not empty
    bool Fraction::areEmpty(const Fraction& lhs, const Fraction& rhs) const {
        return (!lhs.isEmpty() && !rhs.isEmpty());
    }
    // allows two objects of type Fraction to be added by using '+' operator
    Fraction Fraction::operator+(const Fraction& rhs) const {
        bool valid = areEmpty(*this, rhs);
        Fraction tmp;
        if (valid) {
            tmp.numerator = ((this->numerator * rhs.denominator) + (this->denominator * rhs.numerator));
            tmp.denominator = (this->denominator * rhs.denominator);
        }
        return tmp;
    }
    // result of the multiplication operation in reduced form
    Fraction Fraction::operator*(const Fraction& rhs) const {
        Fraction tmp;
        if (areEmpty(*this, rhs)) {
            tmp.numerator = ( numerator * rhs.numerator );
            tmp.denominator = ( denominator * rhs.denominator );
            tmp.reduce();
        }
        return tmp;
    }
    // returns true if fractions are equal value
    bool Fraction::operator==(const Fraction& rhs) {
        bool areEqual;
        if (areEmpty(*this, rhs)) {
            Fraction tmp = *this;
            Fraction tmp_rhs = rhs;
            tmp.reduce();
            tmp_rhs.reduce();
            if (tmp.numerator == tmp_rhs.numerator && tmp.denominator == tmp_rhs.denominator)
                areEqual = true;
            else
                areEqual = false;
        }
        else {
            areEqual = false;
        }
        return areEqual;
    }
    // returns true if fraction are NOT equal value
    bool Fraction::operator!=(const Fraction& rhs) {
        bool areNotEqual;
        if (areEmpty(*this, rhs))
            areNotEqual = !(*this == rhs) ? true : false ;
        else
            areNotEqual = false;
        return areNotEqual;
    }
    // if valid, the current obj stores the result of the addition in reduced form -> returns a ref
    Fraction& Fraction::operator+=(const Fraction& rhs) {
        Fraction tmp;
        if (areEmpty(*this, rhs))
            tmp = (*this + rhs);
        tmp.reduce();
        *this = tmp;
        return *this;
    }
}
