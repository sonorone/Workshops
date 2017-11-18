// TODO: add file header comments here

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
	};
}

#endif // !SICT_PASSENGER_H