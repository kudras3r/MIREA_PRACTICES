#include <iostream>
#include <vector>
#include "Record.hpp"

#define SIZE 3

Record InputRecord() 
{
	Record r;
	std::cout << "Enter record as : cpu freq ram type rel_date" << std::endl;
	std::cin >> r.cpu >> r.frequency >> r.ram >> r.type >> r.release_date;
	
	return r;
}

std::string RemoveStrInput() {
	std::string s;
	std::cout << "Enter the cpu u want to del : " << std::endl;
	std::cin >> s;

	return s;
}


int main() {
	std::vector<Record> Table;

	for (int i = 0; i < 2; i++) {
		Record r = InputRecord();
		Table.push_back(r);
	}

	std::string rem_str;
	rem_str = RemoveStrInput();

	for (int i = 0; i < 2; i++) {
		
		if (Table[i].cpu == rem_str) {
			Table.erase(Table.begin() + i);
		}
	}

	for (int i = 0; i < Table.size(); i++) {
		std::cout << Table[i];
	}
	
	
	return 0;
}