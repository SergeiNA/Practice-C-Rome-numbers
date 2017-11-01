#pragma once
#include <iostream>
#include <string>
class CRoman_int
{
public:
					CRoman_int	(const int&);			//input int
					CRoman_int	(const std::string&);	//input roman
					~CRoman_int	();

	int&			asInt		();		// show int value
	std::string&	asString	();		// shoe roman value
	
private:
	int				int_number;			
	std::string		roman_number;

	int 			Str2Int		(const std::string&);
	std::string 	Int2String	(const int&);
};

