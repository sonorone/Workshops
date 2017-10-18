/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_Kingdom.h
// Version 2.0
// Date 9/20
// Author Murawiecki, Damian
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

#define SIZE 32

namespace sict {
	struct Kingdom {
		char m_name[SIZE];
		int m_population;
	};
	void display(const Kingdom& kingdom);
	void display(const Kingdom kArr[], int arSize);
}
#endif /* SICT_KINGDOM_H */
