// Final Project Milestone 1
//
// Version 1.0
// Date: November 24, 2017
// Author: MURAWIECKI, Damian
// Description:
//
// A Date class to be used to hold the expiry date of the perishable items.
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H
#define SICT_DATE_H

#include <iostream>
#define NO_ERROR   0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR  3
#define DAY_ERROR  4

namespace sict {
	const int min_year = 2000;
	const int max_year = 2030;
    
    class Date {
        int year;
        int month;
        int day;
        int compare;
        int state;
        /* this query returns the number of days in month of year */
        int mdays(int, int)const;
        /* this function sets the error state variable to one of the values listed above [18-22] */
        void errCode(int);
        /* initilizies year, month, day to 0s */
        void init();
    public:
        /* default constructor that initilizes data members to 0s */
        Date();
        /* sets year month and day data memebrs */
        Date(int ,int ,int);
        /* overloaded operators /start */
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        /* overloaded operators /end  */

        /* returns error code value */
        int errCode() const;
        /* returns true if there is NO error */
        bool bad() const;
        /* checks if initilized values are validated and 
         * overwrites to 0s (init func) if not valid.
         * Appends error code depending on the type of error encountered */
        bool validate();
        /* validates data members to check for errors and assigns error code */
        std::istream& read(std::istream& istr);
        /* writes formatted expiry date to the screen */
        std::ostream& write(std::ostream& ostr) const;
        /* 3 queries for helper functions */
        int getDateYear() const;
        int getDateMonth() const;
        int getDateDay() const;
    };
    /* reads Date class object to input stream */
    std::istream& operator>>(std::istream&, Date&);
    /* writes Date class object to output stream */
    std::ostream& operator<<(std::ostream&, const Date&);
}

#endif