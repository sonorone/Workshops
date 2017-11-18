/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_Kingdom.cpp
// Version 2.0
// Date 9/20
// Author Murawiecki, Damian
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

#include <iostream>
using namespace std;
#include "Kingdom.h"

namespace sict {
    
    void display(const Kingdom& kingdom) {
        
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }
    void display(const Kingdom kArr[], int arSize) {
        
        int totalPopulation = 0;
        
        cout
        << "------------------------------" << endl
        << "Kingdoms of SICT"               << endl
        << "------------------------------" << endl;
        for (int i = 0; i < arSize; ++i) {
            cout << i + 1 << ". ";
            cout.flush();
            display(kArr[i]);
            totalPopulation += kArr[i].m_population;
        }
        cout
        << "------------------------------"<< endl
        << "Total population of SICT: " << totalPopulation << endl
        << "------------------------------"<< endl;
    }
}
