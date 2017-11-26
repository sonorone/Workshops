/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File tools.h
// Date	9/13/2017
// Student: Murawiecki, Damian
// Course: OOP244SEE
***********************************************************************/

#ifndef _SICT_TOOLS_H
#define _SICT_TOOLS_H

namespace sict {
    
    // Displays the user interface menu
    int menu();
    // Performs a fool-proof integer entry
    int getInt(int min, int max);
}

#endif
