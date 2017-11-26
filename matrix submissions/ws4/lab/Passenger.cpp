/**
 * Workshop 4: Constructors
 * Student: Murawiecki, Damian (121531164)
 * Passenger.cpp
 * 2017/10/4
 * Comments: This class stores data of a passenger and 
 * the destination if it's a valid information.
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
	}
    Passenger::Passenger(const char* paxp, const char* destp) {
        if ((paxp == nullptr || destp == nullptr) || (destp[0] == '\0' || paxp[0] == '\0')) {
            *this = Passenger();
        }
        else {
            strncpy(pax, paxp, (SIZE-1));
            pax[SIZE-1] = '\0';
            strncpy(dest, destp, (SIZE-1));
            dest[SIZE-1] = '\0';
        }
	}
    bool Passenger::isEmpty() const {
		bool valid = (pax[0] == '\0') ? true : false ;
        return valid;
    }
    void Passenger::display() const {
        if (!isEmpty())
            cout << pax << " - " << dest << endl;
        else
            cout << "No passenger!" << endl;
    }
}
