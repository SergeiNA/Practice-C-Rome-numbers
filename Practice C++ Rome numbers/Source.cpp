/*
	01.11.17 Rome int_numbers (from C++ practice)
	Realize transform:
		integer implementation to Roman implementation
		Roman implementation in integer implementation
	02.11.17
	Realize arithmetic and logic
	Add check functions
	Add input/output functions
*/

#include <iostream>
#include "Roman_int.h"
#include <vector>
#include <string>
#include <regex>
void main() {
	try {
		//std::vector<std::string> Roman;
		//std::cout << "Integer to Roman\n";
		//for (int i= 1; i < 51; i++) {
		//	CRoman_int Int(i);
		//	std::cout << "Integer: " << i << " -- Roman: " << Int.asString() << std::endl;
		//	Roman.push_back(Int.asString());
		//}
		//std::cout << "Roman to integer\n";
		//for (auto s : Roman) {
		//	CRoman_int Rom(s);
		//	std::cout << "Integer: " << Rom.asInt() << " -- Roman: " << s << std::endl;
		//}
		//std::cout << Roman[2];
		
		CRoman_int R1;
		std::cin >> R1;
		std::cout << R1 << std::endl;

		CRoman_int R2;
		R2 = R1;
		std::cout << R2 << std::endl;
	}catch(std::runtime_error& e){
		std::cout << e.what();
	}
	std::cin.get();
	std::cin.get();

}