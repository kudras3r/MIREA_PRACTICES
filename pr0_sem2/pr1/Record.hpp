#ifndef RECORD
#define RECORD

#include "Date.hpp"
#include <string>

struct Record
{

	std::string cpu;
	unsigned frequency;
	unsigned ram;
	char type;
	Date release_date;

};

std::ostream& operator<< (std::ostream& os, const Record& r)
{
	os << r.cpu << " | " << r.frequency << " | " << r.ram << " | " << r.type << " | " << r.release_date << " |" << std::endl;
	return os;
}

#endif // !RECORD
