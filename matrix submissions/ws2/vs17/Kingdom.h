/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 9/20/2017
// Author Murawiecki, Damian (ID# 121531164)
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef KINGDOM_H
#define SIZE 32

// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {

		char m_name[SIZE];
		int m_population;
	};

	// TODO: declare the function display(...),
	//       also in the sict namespace
	void display(const Kingdom& kingdom);
}

#endif // !KINGDOM_H
