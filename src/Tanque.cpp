#include "Tanque.h"
#include "Constantes.h"

Tanque::Tanque() {
	this->capacidad = 0;
}

unsigned int Tanque::obtenerCapacidad() {
	return this->capacidad;
}

void Tanque::cambiarCapacidad(unsigned int nuevaCapacidad){
	capacidad += nuevaCapacidad;
	if (capacidad>CAPACIDAD_MAXIMA_DEL_TANQUE){
		capacidad=CAPACIDAD_MAXIMA_DEL_TANQUE;
	}
}
