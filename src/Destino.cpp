#include <iostream>
#include "Destino.h"

using namespace std;

Destino::Destino() {
	this->nombre = " ";
	this->costoPorKm = 0;
	this->cultivo = Cultivo();
	this->distanciaEnKm = 0;
}

Destino::Destino(std::string nombreDestino, unsigned int km,
		unsigned int precio, std::string cultivoAceptado) {
	this->nombre = nombreDestino;
	this->distanciaEnKm = km;
	this->costoPorKm = precio;
	this->cultivo = Cultivo(cultivoAceptado);
}

string Destino::obtenerNombre() {
	return this->nombre;
}
Cultivo Destino::obtenerCultivoQueAcepta() {
	return this->cultivo;
}
unsigned int Destino::obtenerCostoDeEnvio() {
	return this->costoPorKm;
}
unsigned int Destino::obtenerDistancia() {
	return this->distanciaEnKm;
}
unsigned int Destino::obtenerCostoDeEnvioFinal() {
	return (this->obtenerCostoDeEnvio() * this->obtenerDistancia());
}
