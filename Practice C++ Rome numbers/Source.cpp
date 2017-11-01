/*
	01.11.17 Rome int_numbers (from C++ practice)
	Realize transform:
		integer implementation to Roman implementation
		Roman implementation in integer implementation
*/

#include <iostream>
#include "Roman_int.h"
#include <vector>
#include <string>
void main() {
	std::vector<std::string> Roman;
	std::cout << "Integer to Roman\n";
	for (int i= 1; i < 51; i++) {
		CRoman_int Int(i);
		std::cout << "Integer: " << i << " -- Roman: " << Int.asString() << std::endl;
		Roman.push_back(Int.asString());
	}
	std::cout << "Roman to integer\n";
	for (auto s : Roman) {
		CRoman_int Rom(s);
		std::cout << "Integer: " << Rom.asInt() << " -- Roman: " << s << std::endl;
	}
	std::cin.get();
}