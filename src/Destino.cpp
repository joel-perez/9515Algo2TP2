#include <iostream>
#include "Destino.h"

using namespace std;

Destino::Destino() {
	this->nombre = " ";
	this->costoPorKm = 0;
	this->cultivo = Cultivo();
	this->distanciaEnKm = 0;
}

Destino::Destino(std::string nombreDestino, int km, int precio,
		std::string cultivoAceptado) {
	this->nombre = nombreDestino;
	this->distanciaEnKm = km;
	this->costoPorKm = precio;
	this->cultivo = Cultivo(cultivoAceptado); //TODO: Creo que aca habria que recibir un cultivo ya existente de los que se cargaron del otro archivo...

}

string Destino::obtenerNombre() {
	return this->nombre;
}
Cultivo Destino::obtenerCultivoQueAcepta() {
	return this->cultivo;
}
float Destino::obtenerCostoDeEnvio() {
	return this->costoPorKm;
}
unsigned int Destino::obtenerDistancia() {
	return this->distanciaEnKm;
}
