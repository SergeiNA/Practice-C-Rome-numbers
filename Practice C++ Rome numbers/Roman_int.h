#pragma once
#include <iostream>
#include <string>
#include <fstream>
class CRoman_int
{														// service function
	int 			Str2Int		(const std::string&);
	std::string 	Int2String	(const int&);
	bool			isRoman		(const std::string&);					// solve with regular expression
public:
					CRoman_int	();
					CRoman_int	(const int&);			//input int
					CRoman_int	(const std::string&);	//input roman
					~CRoman_int	();

	int&			asInt		();		// show int value
	std::string&	asString	();		// shoe roman value
	
	friend std::ostream& operator << (std::ostream&, const CRoman_int&);
	friend std::istream& operator >> (std::istream&, CRoman_int&);
																		
	CRoman_int& operator = (const CRoman_int&);
	CRoman_int& operator + (const CRoman_int&);
	CRoman_int& operator - (const CRoman_int&);
	CRoman_int& operator * (const CRoman_int&);
	CRoman_int& operator / (const CRoman_int&);
																
	bool operator >		(const CRoman_int&);
	bool operator <		(const CRoman_int&);
	bool operator ==	(const CRoman_int&);
	bool operator !=	(const CRoman_int&);

private:
	int				int_number;			
	std::string		roman_number;
};


