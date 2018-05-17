#include <iostream>
#include "Destino.h"

Destino::Destino() {
	this->nombre = " ";
	this->costoPorKm = 0;
	this->cultivo = Cultivo();
	this->distanciaEnKm = 0;
}

Destino::Destino(std::string nombreDestino, int km, int precio, std::string  cultivoAceptado){
	this->nombre = nombreDestino;
	this->distanciaEnKm = km;
	this->costoPorKm = precio;
	this->cultivo = Cultivo(cultivoAceptado);

}

//TODO: Implementar los metodos que sean necesarios...
