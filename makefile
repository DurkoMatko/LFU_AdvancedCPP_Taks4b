all : SpreadsheetImplementation

SpreadsheetImplementation: Spreadsheet.o MyMain.o
	g++ -o SpreadsheetImplementation MyMain.o 

MyMain.o: main.cpp
	g++ -c main.cpp -o MyMain.o -std=c++11

Spreadsheet.o: Spreadsheet.cpp
	g++ -c -o Spreadsheet.o Spreadsheet.cpp -std=c++11


clean:
	rm SpreadsheetImplementation Spreadsheet.o MyMain.o



