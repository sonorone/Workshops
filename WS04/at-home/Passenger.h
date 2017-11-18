/**
 * Workshop 4: Constructors
 * Student: Murawiecki, Damian (121531164)
 * Passenger.h
 * 2017/10/4
 * Comments:	declaration of class Passenger, which
 *				stores info about passenger + destination, if valid.
 */

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define SIZE 32

namespace sict {
	// TODO: define the Passenger class here
    class Passenger {
		char pax[SIZE];
		char dest[SIZE];
	public:
		Passenger();
		Passenger(const char*, const char*);
        bool isEmpty() const;
        void display() const;
	};
}
#endif // !SICT_PASSENGER_H
