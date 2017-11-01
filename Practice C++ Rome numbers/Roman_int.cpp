#include "Roman_int.h"
#include <deque>
#include <vector>
#include <algorithm>

// Table of pairs {integer - roman}
const static std::vector<std::pair<int, char> > roman_numerals = {
	{ 1,'I' },{ 10,'X' },{ 100,'C'},{ 1000,'M'},
	{ 5,'V',},{ 50,'L' },{ 500,'D'}
};


CRoman_int::CRoman_int(const int & _num):int_number(_num),roman_number(Int2String(_num))
{
}

CRoman_int::CRoman_int(const std::string &_snum):int_number(Str2Int(_snum)),roman_number(_snum)
{
}

int & CRoman_int::asInt()
{
	return int_number;
}

std::string & CRoman_int::asString()
{
	return roman_number;
	// TODO: insert return statement here
}

CRoman_int::~CRoman_int()
{
}

int  CRoman_int::Str2Int(const std::string & rom_num)
{
	const std::pair<int, char> null_buff = { 0,'N' };   // null buffer/ number
	std::pair<int, char> buff = null_buff;				// init buffer as null
	int result_int_number = 0;							

	for (auto s : rom_num) {													// for every character 
		auto current = find_if(roman_numerals.begin(), roman_numerals.end(),	// find same char in the table
			[&s](const std::pair<int, char>& p)
		{return s == p.second; });

		if (current == roman_numerals.end())			// this char is not belong to roman numbers
			throw std::runtime_error("Wrong int_number!\n" + s + std::string(" is not a Rome int_number!\n"));
		
		if (buff.first < current->first && buff != null_buff) {		// check if its 4, 9, 14, etc...
			result_int_number += current->first- buff.first;		// if number in buffer is smaller than substract
			buff = null_buff;										// and clear buff
		}
		else {														// just add buff to result
			result_int_number += buff.first;						// put current num into bufff
			buff = *current;										
		}
	}
	result_int_number += buff.first;								// get from buff remaing num
	return result_int_number;
}

std::string  CRoman_int::Int2String(const int& _num)
{
	std::deque<int> digits;					// store int number digits
	std::string rom_num;					// result rome number
	int t_int_number = _num;
	while (t_int_number) {					// decompositum the number to digits
		digits.push_front(t_int_number % 10);
		t_int_number /= 10;
	}
	int max_digits = digits.size()-1;		
	for (auto dig : digits) {
		if (dig == 0) {						// there is 10^0 only
			continue;
			max_digits--;
		}
		if (dig < 4) {						// for example I --III
			for (int i = 0; i < dig; i++)
				rom_num.push_back(roman_numerals[max_digits].second);
			max_digits--;
			continue;
		}
		if (dig == 4) {						// for example IV
			rom_num.push_back(roman_numerals[max_digits].second);
			rom_num.push_back(roman_numerals[max_digits + 4].second); 
			max_digits--;
			continue;
		}
		if (dig > 4 && dig < 9) {			// for example V - VII
			rom_num.push_back(roman_numerals[max_digits + 4].second);
			for(int i=0;i<dig-5;i++)
				rom_num.push_back(roman_numerals[max_digits].second);
			max_digits--;
			continue;
		}
		else {								// for example IX
			rom_num.push_back(roman_numerals[max_digits].second);
			rom_num.push_back(roman_numerals[max_digits+1].second);
			max_digits--;
			continue;
		}
	}
	// TODO: insert return statement here
	return rom_num;
}
