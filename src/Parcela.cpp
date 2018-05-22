#include <iostream>
#include "Parcela.h"

using namespace std;

Parcela::Parcela() {
	this->estadoParcela = VACIA;
	this->estaRegada = false;
	this->cultivo = new Cultivo(); //lo puse asi para que compile, hay que cambiarlo...
	this->tiempoHastaCosecha = cultivo->obtenerTiempoHastaCosecha();
	this->tiempoHastaRecuperacion = this->cultivo->obtenerTiempoRecuperacion();
	this->rentabilidad = RENTABILIDAD_CULTIVO_VACIO;
}

bool Parcela::estaOcupada() {
	return (this->estadoParcela == VACIA);
}

Cultivo* Parcela::obtenerCultivo() {
	return this->cultivo;
}

EstadoParcela Parcela::obtenerEstado() {
	return this->estadoParcela;
}

string Parcela::obtenerEstadoParaMostrarEnPantalla() {
	string estadoParaMostrar = "sarasa";
	switch (this->estadoParcela) {
	case VACIA:
		estadoParaMostrar = "#"; //TODO: Pasar a constante...
		break;
	case SEMBRADA:
		estadoParaMostrar = this->obtenerNombre().substr(0, 10); //TODO: Pasar el 10 a constante...
		break;
	case SECA:
		estadoParaMostrar = "S"; //TODO: Pasar a constante...
		break;
	case PODRIDA:
		estadoParaMostrar = "P"; //TODO: Pasar a constante...
		break;
	case RECUPERACION:
		estadoParaMostrar = "R"; //TODO: Pasar a constante...
		break;
	}
	return estadoParaMostrar;
}

string Parcela::obtenerNombre() {
	return this->cultivo->obtenerNombre();
}

void Parcela::establecerCultivo(Cultivo* tipoCultivo) {
	this->cultivo = tipoCultivo;
}

void Parcela::regar() {
	this->estaRegada = true;
}

bool Parcela::yaEstaRegada() {
	return this->estaRegada;
}
unsigned int Parcela::obtenerRentabilidad() {
	return this->rentabilidad;
}

unsigned int Parcela::obtenerTiempoHastaCosecha() {
	return this->tiempoHastaCosecha;
}

unsigned int Parcela::sembrar(Cultivo* cultivo) {
	if (!this->estaOcupada()) {
		this->cultivo = cultivo;
		this->rentabilidad = cultivo->obtenerRentabilidad();
		this->tiempoHastaCosecha = cultivo->obtenerTiempoHastaCosecha();
		this->tiempoHastaRecuperacion = cultivo->obtenerTiempoRecuperacion();
		this->estaRegada = false;
	}
	return cultivo->obtenerCosto();
}
