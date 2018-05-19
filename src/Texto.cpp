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
