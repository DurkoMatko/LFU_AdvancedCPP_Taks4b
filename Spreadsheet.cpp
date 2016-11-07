#include "Spreadsheet.hpp"
#include <iostream>
#include <cstring>

Spreadsheet::Spreadsheet(int inWidth, int inHeight) : mWidth(inWidth), mHeight(inHeight){

	std::cout <<"Spreadsheet(" << inWidth <<","<<inHeight<<")" << std::endl;

	mCells = new SpreadsheetCell*[inWidth];
	mCells[0] = new SpreadsheetCell[inWidth * inHeight];
	for (int i = 1; i < inWidth; i++)
	    mCells[i] = mCells[i-1] + inHeight;
}

//copy constructor
Spreadsheet::Spreadsheet(const Spreadsheet& s): mWidth(s.getWidth()), mHeight(s.getHeight()){
	std::cout <<"copy constructor" << std::endl;

	//allocate continuous block of memory 
	mCells = new SpreadsheetCell*[mWidth];
	mCells[0] = new SpreadsheetCell[mWidth * mHeight];
	for (int i = 1; i < mWidth; i++)
	    mCells[i] = mCells[i-1] + mHeight;

	//copy memory being pointed to (continuous block) - can't make pointer to same memory cuz changing 1st object would change 2nd one
    memcpy(mCells[0], s.mCells[0], mHeight * mWidth * sizeof mCells[0][0]);
}

//copy assign operator - always have to deallocate previous data (because object already exists)
Spreadsheet &Spreadsheet::operator=(const Spreadsheet& rhs){		
	std::cout <<"copy assign operator" << std::endl;

	//deallocate previous
 	delete[] mCells[0];
 	delete[] mCells;
 	
 	//set new bounds
	mWidth = rhs.getWidth();
	mHeight = rhs.getHeight();

	//allocate continuous block of memory within new bounds
	mCells = new SpreadsheetCell*[mWidth];
	mCells[0] = new SpreadsheetCell[mWidth * mHeight];
	for (int i = 1; i < mWidth; i++)
	    mCells[i] = mCells[i-1] + mHeight;

	//copy continuous block of memory
    memcpy(mCells[0], rhs.mCells[0], mHeight * mWidth * sizeof mCells[0][0]);
	return *this;
}

//move constructor 
Spreadsheet::Spreadsheet(Spreadsheet&& s) noexcept: mWidth(s.getWidth()), mHeight(s.getHeight()){
	std::cout <<"move constructor" << std::endl;

	//allocate continuous block of memory within new bounds
	mCells = new SpreadsheetCell*[mWidth];
	mCells[0] = new SpreadsheetCell[mWidth * mHeight];
	for (int i = 1; i < mWidth; i++)
	    mCells[i] = mCells[i-1] + mHeight;

	//move memory being pointed to
    memmove(mCells[0], s.mCells[0], mHeight * mWidth * sizeof mCells[0][0]);

    //"destroy" previous object
    s.mWidth = 0;
    s.mHeight = 0;
    delete[] s.mCells[0];
 	delete[] s.mCells;
    s.mCells[0] = nullptr;
    s.mCells = nullptr;
}


//move assign operator
Spreadsheet &Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {	
	//delete old memory block of Cells on heap
 	delete[] mCells[0];
 	delete[] mCells;

 	//set new bounds
	mWidth = rhs.getWidth();
	mHeight = rhs.getHeight();

	//allocate new continuous block of memory within new bounds
	mCells = new SpreadsheetCell*[mWidth];
	mCells[0] = new SpreadsheetCell[mWidth * mHeight];
	for (int i = 1; i < mWidth; i++)
	    mCells[i] = mCells[i-1] + mHeight;

	//move memory being pointed to
    memmove(mCells[0], rhs.mCells[0], mHeight * mWidth * sizeof mCells[0][0]);

	//"destroy" previous object
    rhs.mWidth = 0;
    rhs.mHeight = 0;
    delete[] rhs.mCells[0];
 	delete[] rhs.mCells;
    rhs.mCells[0]=nullptr;    
	rhs.mCells = nullptr;

	return *this;
}
Spreadsheet::~Spreadsheet(){
	std::cout <<"destructing " <<mWidth << " "<< mHeight  <<std::endl;

	//if objects wasn't moved before - therefore also freed, free it now(deallocate memory)
 	if(mWidth!=0 && mHeight!=0){
 		delete[] mCells[0];
 		delete[] mCells;
 	}
}

int Spreadsheet::getWidth() const{
	return mWidth;
}

int Spreadsheet::getHeight() const{
	return mHeight;
}



/* OLD ALLOCATION
mCells = new SpreadsheetCell*[s.getWidth()];
	for(int i = 0; i<s.getHeight(); i++){
			mCells[i] = new SpreadsheetCell[s.getWidth()];
	}
	*/