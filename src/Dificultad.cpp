#include "Dificultad.h"

Dificultad::Dificultad(){
	this->turnos=0;
	this->tamanioInicial=0;
	this->dificultad =SIN_DIFICULTAD;

}

Dificultad::Dificultad(unsigned int dificultadSeleccionada) {
	this->turnos=0;
	this->tamanioInicial=0;
	this->dificultad =dificultadSeleccionada;
	this->multiplicadorAgua=elegirMultiplicador();
}

unsigned int Dificultad::obtenerTurnos() {
	//return this->turnos;
	return 0;
}

unsigned int Dificultad::obtenerDificultad(){
	return this->dificultad;
}

unsigned int Dificultad::elegirMultiplicador(){
	unsigned int valor;
	switch (this->obtenerDificultad()){
		case FACIL:
			valor=8;
		break;
		case INTERMEDIO:
			valor=5;
		break;
		case DIFICIL:
			valor=3;
		break;
	}
	return valor;
}
unsigned int Dificultad::obtenerMultiplicadorAgua(){
	return this->multiplicadorAgua;
}

//TODO: Terminar de implementar lo que falta...
