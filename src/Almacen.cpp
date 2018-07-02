#include <iostream>
#include "Almacen.h"

Almacen::Almacen() {
	this->cultivos = new Lista<Cultivo*>;
	this->capacidadMaximaAlmacen = 1;
}

Almacen::Almacen(unsigned int coeficienteCapacidadAlmacen, unsigned int filas,
		unsigned int columnas) {
	this->cultivos = new Lista<Cultivo*>;
	this->capacidadMaximaAlmacen = coeficienteCapacidadAlmacen
			* (filas + columnas);
}

unsigned int Almacen::obtenerCapacidadMaxima() {
	return this->capacidadMaximaAlmacen;
}

void Almacen::agregarCultivo(Cultivo* cultivo) {
	this->cultivos->agregar(cultivo);
}

void Almacen::enviarCultivos(unsigned int posicion) {
	this->obtenerCultivos()->remover(posicion);
}

Lista<Cultivo*>* Almacen::obtenerCultivos() {
	return this->cultivos;
}

bool Almacen::estaLleno() {
	return (this->obtenerCultivos()->contarElementos()
			== this->obtenerCapacidadMaxima());
}

unsigned int Almacen::obtenerCantidadDeCultivosEnUnAlmacen() {
	return (this->cultivos->contarElementos());
}

Cultivo* Almacen::obtenerUnCultivo(unsigned int cultivoElegido) {
	return (this->cultivos->obtener(cultivoElegido));
}

Almacen::~Almacen() {

	delete cultivos;
}

