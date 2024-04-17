#ifndef DATE
#define DATE

#include <iostream>

struct Date 
{

	unsigned day;
	unsigned month;
	unsigned year;

};

std::istream& operator>> (std::istream& is, Date& dt)
{
	is >> dt.day >> dt.month >> dt.year;
	return is;
}

std::ostream& operator<< (std::ostream& os, const Date& dt)
{
	os << dt.day << '.' << dt.month << '.' << dt.year;
	return os;
}

#endif  // !DATE
