#include <iostream>
#include <algorithm>
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

string Texto::rellenarDerecha(string str, unsigned int cant, char pad) {
	if (str.length() < cant)
		str += string(cant - str.length(), pad);
	return str;
}

string Texto::mayusculas(string texto) {
	transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
	return texto;
}
