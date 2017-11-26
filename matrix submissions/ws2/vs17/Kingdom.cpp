/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
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


// TODO: include the necessary headers
#include <iostream>
using namespace std;
#include "Kingdom.h"

// TODO: the sict namespace
namespace sict {

	// TODO:definition for display(...) 
	void display(const Kingdom& kingdom) {

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}

}