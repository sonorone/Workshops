/**
 * Workshop 4: Constructors
 * Student: Murawiecki, Damian (121531164)
 * Passenger.cpp
 * 2017/10/4
 * Comments:    This class stores data of a passenger, a destination and travel date, if all information is valid.
 */

#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;
using namespace sict;

namespace sict {
	Passenger::Passenger() {
		pax[0] = '\0';
		dest[0] = '\0';
        setDate(0, 0, 0);
	}
    Passenger::Passenger(const char* paxp, const char* destp) {
        set(paxp, destp);
        if (!isEmpty()) {
            setDate(2017,7,1);
        }
	}
    Passenger::Passenger(const char* paxp, const char* destp, int y, int m, int d) {
        set(paxp, destp);
        if (!isEmpty())
            setDate(y, m, d);
        // if date was valid, year isn't zero
        if (year == 0)
            *this = Passenger();
    }
    bool Passenger::isEmpty() const {
        bool valid = (pax[0] == '\0') ? true : false ;
        return valid;
    }
    void Passenger::display() const {
        if (!isEmpty()) {
            cout << pax << " - " << dest << " on " << year << "/";
            cout.fill('0');
            cout.width(2);
            cout << month << "/";
            cout.width(2);
            cout << day << endl;
            cout.fill(' ');
        }
        else {
            cout << "No passenger!" << endl;
        }
    }
    void Passenger::set(const char* paxp, const char* destp) {
        if ((paxp == nullptr || destp == nullptr) || (destp[0] == '\0' || paxp[0] == '\0')) {
            // set to an empty state
            *this = Passenger();
        }
        else {
            // data is valid therefore copy two parameters into the object, and set remaining / date to 0, since unknown
            strncpy(pax, paxp, (SIZE-1));
            pax[SIZE-1] = '\0';
            strncpy(dest, destp, (SIZE-1));
            dest[SIZE-1] = '\0';
            setDate(0, 0, 0);
        }
    }
    void Passenger::setDate(int y, int m, int d) {
        if (y >= 2017 && y <= 2020 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
            year = y;
            month = m;
            day = d;
        }
        else {
            year = 0;
            month = 0;
            day = 0;
        }
    }
    const char* Passenger::name() const {
        return pax;
    }
    bool Passenger::canTravelWith(const Passenger& pax) const {
        return ((pax.year == year && pax.month == month && pax.day == day) ? true : false);
    }
}
