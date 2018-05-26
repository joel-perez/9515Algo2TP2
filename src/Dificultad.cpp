#include <iostream>

#include "Dificultad.h"

Dificultad::Dificultad() {
	inicializarDificultadFacil();
}

Dificultad::Dificultad(unsigned int dificultadSeleccionada) {
	this->dificultad = (TipoDificultad) dificultadSeleccionada;
	switch (dificultadSeleccionada) {
	case FACIL:
		inicializarDificultadFacil();
		break;
	case INTERMEDIO:
		inicializarDificultadIntermedio();
		break;
	case DIFICIL:
		inicializarDificultadDificil();
		break;
	}
}

Dificultad::Dificultad(TipoDificultad dificultadSeleccionada) {
	switch (dificultadSeleccionada) {
	case FACIL:
		inicializarDificultadFacil();
		break;
	case INTERMEDIO:
		inicializarDificultadIntermedio();
		break;
	case DIFICIL:
		inicializarDificultadDificil();
		break;
	}
}

void Dificultad::inicializarDificultadFacil() {
	this->coeficienteTamanioTanque = 3;
	this->coeficienteCreditosAsignados = 3;
	this->coeficientePrecioCultivo = 1;
	this->coeficienteCantidadTurnos = 1;
	this->coeficienteMultiplicadorAgua = 3;
	this->coeficientePrecioTerreno = 1;
	this->coeficienteTamanioAlmacen = 3;
	this->coeficienteTamanioTerreno = 1;
	this->coeficienteTamanioTanque = 3;
}

void Dificultad::inicializarDificultadIntermedio() {
	this->coeficienteTamanioTanque = 2;
	this->coeficienteCreditosAsignados = 2;
	this->coeficientePrecioCultivo = 2;
	this->coeficienteCantidadTurnos = 1;
	this->coeficienteMultiplicadorAgua = 2;
	this->coeficientePrecioTerreno = 2;
	this->coeficienteTamanioAlmacen = 2;
	this->coeficienteTamanioTerreno = 1;
	this->coeficienteTamanioTanque = 2;
}

void Dificultad::inicializarDificultadDificil() {
	this->coeficienteTamanioTanque = 1;
	this->coeficienteCreditosAsignados = 1;
	this->coeficientePrecioCultivo = 3;
	this->coeficienteCantidadTurnos = 1;
	this->coeficienteMultiplicadorAgua = 1;
	this->coeficientePrecioTerreno = 3;
	this->coeficienteTamanioAlmacen = 1;
	this->coeficienteTamanioTerreno = 1;
	this->coeficienteTamanioTanque = 1;
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

unsigned int Dificultad::obtenerCoeficienteMultiplicadorAgua() {
	return this->coeficienteMultiplicadorAgua;
}

unsigned int Dificultad::obtenerCoeficientePrecioTanque() {
	return this->coeficientePrecioTanque;
}
