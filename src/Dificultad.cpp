#include "Dificultad.h"

Dificultad::Dificultad(){
	this->turnos=0;
	this->tamanioInicial=0;
	this->dificultad =SIN_DIFICULTAD;

}

Dificultad::Dificultad(unsigned int dificultadSeleccionada) {
}

unsigned int Dificultad::obtenerTurnos() {
	return 0;
}

unsigned int Dificultad::obtenerDificultad(){
	return this->dificultad;
}
//TODO: Terminar de implementar lo que falta...
