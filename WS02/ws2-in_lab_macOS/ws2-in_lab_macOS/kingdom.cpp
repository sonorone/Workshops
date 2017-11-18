/***********************************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File:    kingdom.h
 // Date:	 9/19/2017
 // Student: Murawiecki, Damian
 // Course:  OOP244SEE
 ***********************************************************************/


#include <iostream>
using namespace std;
#include "Kingdom.h"

namespace sict {
    
    void display(const Kingdom& kingdom) {

        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }
}
