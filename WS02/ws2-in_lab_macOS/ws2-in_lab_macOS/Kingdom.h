/***********************************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File:    kingdom.h
 // Date:	 9/19/2017
 // Student: Murawiecki, Damian
 // Course:  OOP244SEE
 ***********************************************************************/

#ifndef kingdom_h
#define kingdom_h

#define SIZE 32

struct Kingdom {
    
    char m_name[SIZE];
    unsigned int m_population;
};

void display(const Kingdom& kingdom);

#endif /* kingdom_h */
