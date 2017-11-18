#include <iostream>
using namespace std;
#include "Fraction.h"

namespace sict {
	Fraction::Fraction() {
		numerator = -1;
		denominator = -1;
	}
	Fraction::Fraction(int num, int den) {
		if (num >= 0 && den > 0) {
			numerator = num;
			denominator = den;
		}
		else {
			*this = Fraction();
		}
	}
	int Fraction::max() const { return numerator > denominator ? numerator : denominator; }
	int Fraction::min() const { return numerator < denominator ? numerator : denominator; }
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
	void Fraction::reduce() {
		int g = gcd();
		numerator /= g;
		denominator /= g;
	}
	void Fraction::display() const {
		if (numerator >= 0 && denominator > 1)
			cout << numerator << "/" << denominator << endl;
		else if (numerator >= 0 && denominator == 1)
			cout << numerator << endl;
		else if (numerator == -1)
			cout << "no fraction stored" << endl;
	}
	bool Fraction::isEmpty() const { return (numerator == -1) ? true : false; }

	Fraction Fraction::operator+(const Fraction& rhs) const {
		int num = -1, den = 0;
		if (!isEmpty() && !rhs.isEmpty()) {
			num = ((numerator + rhs.denominator) + (denominator + rhs.numerator));
			den = (denominator + rhs.denominator);
		}
		Fraction temp(num, den);
		temp.reduce();
		return temp;
	}
	
}