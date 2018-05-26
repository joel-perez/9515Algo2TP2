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
	Cultivo* miCultivo = new Cultivo();
	miCultivo->asignarConsumoDeAgua(cultivo->obtenerConsumoDeAgua());
	miCultivo->asignarCosto(cultivo->obtenerCosto());
	miCultivo->asignarNombre(cultivo->obtenerNombre());
	miCultivo->asignarRentabilidad(cultivo->obtenerRentabilidad());
	miCultivo->asignarTiempoDeCrecimiento(cultivo->obtenerTiempoHastaCosecha());
	miCultivo->asignarTiempoDeRecuperacion(
			cultivo->obtenerTiempoRecuperacion());
	this->cultivos->agregar(miCultivo);
}

void Almacen::enviarCultivos() {
//TODO: Implementar...
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
	std::cout << "Almacen::~Almacen()" << std::endl;
	this->cultivos->iniciarCursor();
	while (this->cultivos->avanzarCursor()) {
		delete this->cultivos->obtenerCursor();
	}
	delete cultivos;
}

