#ifndef SICT_FRACTION_H

namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;

		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+ (const Fraction&) const;
	};
}

#endif // !SICT_FRACTION_H

