#ifndef SPREADSHEET_H_INCLUDED
#define SPREADSHEET_H_INCLUDED

class SpreadsheetCell {
	public:
	double value;
};


class Spreadsheet {
	public:
		Spreadsheet(int inWidth, int inHeight);
		Spreadsheet(const Spreadsheet &src);
		Spreadsheet& operator=(const Spreadsheet & rhs);
		Spreadsheet(Spreadsheet &&src) noexcept;
		Spreadsheet & operator=(Spreadsheet &&rhs) noexcept;
		virtual ~Spreadsheet();
		int getWidth() const;
		int getHeight() const;
	private:
		int mWidth, mHeight;
		SpreadsheetCell** mCells;
};

#endif // SPREADSHEET_H_INCLUDED