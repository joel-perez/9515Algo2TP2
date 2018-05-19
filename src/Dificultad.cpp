#include "Dificultad.h"

Dificultad::Dificultad() {
	this->turnos = 0;
	this->tamanioInicial = 0;
	this->dificultad = SIN_DIFICULTAD;
//this->
//this->d
//this->d
//this->d
}

Dificultad::Dificultad(TipoDificultad dificultadSeleccionada) {
	this->dificultadSeleccionada = (TipoDificultad) dificultadSeleccionada;
	switch (dificultadSeleccionada) {
	case FACIL:
		this->coeficienteCantidadturnos = 1;
		this->tamanioInicial = 0;
		this->multiplicadorAgua = elegirMultiplicador();
		break;
	case INTERMEDIO:
		this->turnos = 0;
		this->tamanioInicial = 0;
		this->dificultad = dificultadSeleccionada;
		this->multiplicadorAgua = elegirMultiplicador();
		break;
	case DIFICIL:
		this->turnos = 0;
		this->tamanioInicial = 0;
		this->dificultad = dificultadSeleccionada;
		this->multiplicadorAgua = elegirMultiplicador();
		break;
	}
}

unsigned int obtenerCoeficienteCreditosAsignados() {

}
unsigned int obtenerCoeficienteTamanioTanque();
unsigned int obtenerCoeficienteTamanioAlmacen();
unsigned int obtenerCoeficienteCantidadTurnos();
unsigned int obtenerCoeficienteTamanioTerreno();
unsigned int obtenerCoeficientePrecioCultivo();
unsigned int obtenerCoeficientePrecioTerreno();

unsigned int Dificultad::obtenerDificultad() {
	return this->dificultad;
}

unsigned int Dificultad::elegirMultiplicador() {
	unsigned int valor;
	switch (this->obtenerDificultad()) {
	case FACIL:
		valor = 8;
		break;
	case INTERMEDIO:
		valor = 5;
		break;
	case DIFICIL:
		valor = 3;
		break;
	}
	return valor;
}
unsigned int Dificultad::obtenerCoeficienteMultiplicadorAgua() {
	return this->coeficienteMultiplicadorAgua;
}

//TODO: Terminar de implementar lo que falta...
