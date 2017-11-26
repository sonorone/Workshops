/**
 * Workshop 4: Constructors
 * Student: Murawiecki, Damian (121531164)
 * Passenger.h
 * 2017/10/4
 * Comments:	declaration of class Passenger, which
 *				stores info about passenger + destination, if valid.
 */

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define SIZE 32

namespace sict {
    class Passenger {
		char pax[SIZE];
		char dest[SIZE];
        int year;
        int month;
        int day;
        
	public:
		Passenger();
		Passenger(const char*, const char*);
        Passenger(const char*, const char*, int,int,int);
        bool isEmpty() const;
        void display() const;
        void set(const char*, const char*);
        void setDate(int,int,int);
        const char* name() const;
        bool canTravelWith(const Passenger&) const;
	};
}
#endif // !SICT_PASSENGER_H
