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
#include "Date.h"

namespace sict {
	/* number of days in month mon_ and year year_ */
	int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    /* sets the value of state to an appropriate error code */
    void Date::errCode(int errorCode) {
        state = errorCode;
    }
    /* returns error code value */
    int Date::errCode() const {
        return state;
    }
    /* default constructor that initilizes data members to 0s */
    Date::Date() {
		init();
        state = NO_ERROR;
    }
    /* sets year month and day data memebrs */
    Date::Date(int yyyy, int mm, int dd) {
		year = yyyy;
		month = mm;
		day = dd;
        validate();
        if (state == NO_ERROR)
            compare = year * 372 + month * 13 + day;
        else
            compare = 0;
    }
    /* overloaded operators /start */
    bool Date::operator==(const Date& rhs) const {
        return (year != rhs.year && month != rhs.month && day != rhs.day) ? false : true;
    }
    bool Date::operator!=(const Date& rhs) const {
        return (year != rhs.year || month != rhs.month || day != rhs.day) ? true : false;
    }
    bool Date::operator<(const Date& rhs) const {
        return ((year < rhs.year) || (year == rhs.year && month < rhs.month) || (year == rhs.year && month == rhs.month && day < rhs.day)) ? true : false;
    }
    bool Date::operator>(const Date& rhs) const {
        return ((year > rhs.year) || (year == rhs.year && month > rhs.month) || (year == rhs.year && month == rhs.month && day > rhs.day)) ? true : false;
    }
    bool Date::operator<=(const Date& rhs) const {
        return (year <= rhs.year && month <= rhs.month && day <= rhs.day) ? true : false;
    }
    bool Date::operator>=(const Date& rhs) const {
        return (year >= rhs.year && month >= rhs.month && day >= rhs.day) ? true : false;
    }
    /* overloaded operators /end  */

	/* returns true if there is NO error */
    bool Date::bad() const { return state != NO_ERROR ? true : false; }
    /* validates data members to check for errors and assigns error code */
    std::istream& Date::read(std::istream& istr) {
        istr >> year;
        istr.get();
        if (istr.fail()) { state = CIN_FAILED; }
        istr >> month;
        istr.get();
        if (istr.fail()) { state = CIN_FAILED; }
        istr >> day;
        if (istr.fail()) { state = CIN_FAILED; }
        if (state != CIN_FAILED)
            validate();
        return istr;
    }
    /* writes formatted expiry date to the screen */
    std::ostream& Date::write(std::ostream& ostr) const {
        ostr.setf(std::ios::fixed);
        ostr.fill('0');
        ostr << year;
        ostr << "/";
        ostr.fill('0');
        ostr.width(2);
        ostr << month;
        ostr << "/";
        ostr.width(2);
        ostr << day;
        ostr.fill(' ');
        return ostr;
    }
    /* reads Date class object to input stream */
    std::istream& operator>>(std::istream& is, Date& d) {
        d.read(is);
        return is;
    }
    /* writes Date class object to output stream */
    std::ostream& operator<<(std::ostream& os, const Date& d) {
        d.write(os);
        return os;
    }
    /* used with default constructor and validate() func */
    void Date::init() {
        year = 0;
        month = 0;
        day = 0;
        compare = 0;
    }
    /* validates data members to check for errors and assigns error code */
    bool Date::validate() {
        bool valid = true;
        if (year < min_year || year > max_year) {
            state = YEAR_ERROR;
            valid = false;
        }
        if (valid && (month < 1 || month > 12)) {
            state = MON_ERROR;
            valid = false;
        }
        if (valid && (day > mdays(month, year))) {
            state = DAY_ERROR;
            valid = false;
        }
		if (!valid) init();
        return valid;
    }
    /* data member queries for helper functions */
    int Date::getDateYear() const { return year; }
    int Date::getDateMonth() const { return month; }
    int Date::getDateDay() const { return day; }
}
