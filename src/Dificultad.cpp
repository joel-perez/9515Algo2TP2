#include <iostream>

#include "Dificultad.h"

Dificultad::Dificultad() {
	this->coeficienteTamanioTanque = 0;
	this->coeficienteCreditosAsignados = 0;
	this->coeficientePrecioCultivo = 0;
	this->coeficienteCantidadTurnos = 0;
	this->coeficienteMultiplicadorAgua = 0;
	this->coeficientePrecioTerreno = 0;
	this->coeficienteTamanioAlmacen = 0;
	this->coeficienteTamanioTerreno = 0;
	this->dificultad = FACIL;
}

Dificultad::Dificultad(unsigned int dificultadSeleccionada) {
	this->dificultad = (TipoDificultad) dificultadSeleccionada;
	switch (dificultadSeleccionada) {
	case FACIL:
		this->coeficienteTamanioTanque = 1;
		this->coeficienteCreditosAsignados = 1;
		this->coeficientePrecioCultivo = 1;
		this->coeficienteCantidadTurnos = 1;
		this->coeficienteMultiplicadorAgua = 1;
		this->coeficientePrecioTerreno = 1;
		this->coeficienteTamanioAlmacen = 1;
		this->coeficienteTamanioTerreno = 1;
		break;
	case INTERMEDIO:
		this->coeficienteTamanioTanque = 2;
		this->coeficienteCreditosAsignados = 2;
		this->coeficientePrecioCultivo = 2;
		this->coeficienteCantidadTurnos = 2;
		this->coeficienteMultiplicadorAgua = 2;
		this->coeficientePrecioTerreno = 2;
		this->coeficienteTamanioAlmacen = 2;
		this->coeficienteTamanioTerreno = 2;
		break;
	case DIFICIL:
		this->coeficienteTamanioTanque = 3;
		this->coeficienteCreditosAsignados = 3;
		this->coeficientePrecioCultivo = 3;
		this->coeficienteCantidadTurnos = 3;
		this->coeficienteMultiplicadorAgua = 3;
		this->coeficientePrecioTerreno = 3;
		this->coeficienteTamanioAlmacen = 3;
		this->coeficienteTamanioTerreno = 3;
		break;
	}
}

unsigned int Dificultad::obtenerCoeficienteCreditosAsignados() {
	return this->coeficienteCreditosAsignados;
}
unsigned int Dificultad::obtenerCoeficienteTamanioTanque() {
	return this->coeficienteTamanioTanque;
}
unsigned int Dificultad::obtenerCoeficienteTamanioAlmacen() {
	return this->coeficienteTamanioAlmacen;
}
unsigned int Dificultad::obtenerCoeficienteCantidadTurnos() {
	return this->coeficienteCantidadTurnos;
}
unsigned int Dificultad::obtenerCoeficienteTamanioTerreno() {
	return this->coeficienteTamanioTerreno;
}
unsigned int Dificultad::obtenerCoeficientePrecioCultivo() {
	return this->coeficientePrecioCultivo;
}
unsigned int Dificultad::obtenerCoeficientePrecioTerreno() {
	return this->coeficientePrecioTerreno;
}

TipoDificultad Dificultad::obtenerDificultad() {
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
