#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Texto.h"

using namespace std;

string Texto::intToString(int number) {
	std::ostringstream convert;
	convert << number;
	return convert.str();
}

string Texto::padRight(string str, unsigned int cant, char pad) {
	if (str.length() < cant)
		str += string(cant - str.length(), pad);
	return str;
}
