#include "Spreadsheet.cpp"
#include <vector>
#include <iostream>
#include <cstring>

Spreadsheet CreateObject() {
	return Spreadsheet(3, 2);
}

int main(){
	std::vector<Spreadsheet> vec;
	for (auto i = 0; i < 2; ++i) {
		vec.push_back(Spreadsheet(100, 100));		//pushback requires Spreadsheet to be MoveConstructible
	}
	
	Spreadsheet s(2, 3);
	
	s = CreateObject();
	
	Spreadsheet s2(5, 6);
	
	s2 = s;
	
	Spreadsheet s3 = s;
}
