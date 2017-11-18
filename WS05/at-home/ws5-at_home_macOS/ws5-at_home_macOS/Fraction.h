/**
 * Workshop 5: operator overloading
 * Student: Murawiecki, Damian (121531164)
 * File: Fraction.h
 * 2017/10/11
 * Comments:    This class reperesents fractions.
 */

#ifndef SICT_FRACTION_H

namespace sict {
    class Fraction {
        int numerator;
        int denominator;
        // returns one of the two instance variables (higher)
        int max() const;
        // returns one of the two instance variables (lower)
        int min() const;
        // returns greater common dividor from within the Fraction type object
        int gcd() const;
        // reduces Fraction object to the minimal representation
        void reduce();
    public:
        // default constructor: ensures the object is in a safe empty state
        Fraction();
        // two arg constructor: validates the data...
        Fraction(int, int);
        // displays fraction
        void display() const;
        // checks if object is not empty
        bool isEmpty() const;
        // check if objects are not empty
        bool areEmpty(const Fraction& lhs, const Fraction& rhs) const;
        // allows two objects of type Fraction to be added by using '+' operator
        Fraction operator+(const Fraction&) const;
        // result of the multiplication operation in reduced form
        Fraction operator*(const Fraction&) const;
        // returns true if fractions are equal value
        bool operator==(const Fraction& rhs);
        // returns true if fraction are NOT equal value
        bool operator!=(const Fraction& rhs);
        // if valid, the current obj stores the result of the addition in reduced form -> returns a ref
        Fraction& operator+=(const Fraction& rhs);
	};
}

#endif // !SICT_FRACTION_H

