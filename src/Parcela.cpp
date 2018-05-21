#include <iostream>
#include "Parcela.h"

using namespace std;

Parcela::Parcela() {
	cout << "Soy una nueva parcela!!" << endl;
	this->estado = PARCELA_LIBRE;
	this->estaRegada = false;
	this->cultivo = new Cultivo(); //lo puse asi para que compile, hay que cambiarlo...
	this->tiempoHastaCosecha = cultivo->obtenerTiempoHastaCosecha();
	this->tiempoHastaRecuperacion = this->cultivo->obtenerTiempoRecuperacion();
	this->rentabilidad = RENTABILIDAD_CULTIVO_VACIO;
}
bool Parcela::estaOcupada() {
	return (this->estado != PARCELA_LIBRE);
}
Cultivo* Parcela::obtenerCultivo() {
	return this->cultivo;
}

string Parcela::obtenerEstado() {
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
