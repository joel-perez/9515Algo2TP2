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
	return (this->estadoParcela != VACIA);
}

Cultivo* Parcela::obtenerCultivo() {
	return this->cultivo;
}

EstadoParcela Parcela::obtenerEstado() {
	return this->estadoParcela;
}

string Parcela::obtenerEstadoParaMostrarEnPantalla() {
	string estadoParaMostrar = "";
	switch (this->estadoParcela) {
	case VACIA:
		estadoParaMostrar = PARCEL_VACIA;
		break;
	case SEMBRADA:
		estadoParaMostrar = this->obtenerNombre().substr(0, 10);
		break;
	case SECA:
		estadoParaMostrar = CULTIVO_SECO;
		break;
	case PODRIDA:
		estadoParaMostrar = CULTIVO_PODRIDO;
		break;
	case RECUPERACION:
		estadoParaMostrar = PARCELA_EN_RECUPERACION;
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

unsigned int Parcela::sembrar(Cultivo* &cultivo) {
	if (!this->estaOcupada()) {
		this->estadoParcela = SEMBRADA;
		this->cultivo = cultivo;
		this->rentabilidad = cultivo->obtenerRentabilidad();
		this->tiempoHastaCosecha = cultivo->obtenerTiempoHastaCosecha();
		this->tiempoHastaRecuperacion = cultivo->obtenerTiempoRecuperacion();
		this->estaRegada = false;
	}
	return cultivo->obtenerCosto();
}

void Parcela::cosechar(Cultivo* &cultivo){
	unsigned int tiempoRecuperacionActual = cultivo->obtenerTiempoRecuperacion();
	if(!this->estaOcupada()){
		//this->cultivo = ....
		this->estadoParcela = RECUPERACION;
		this->estaRegada=false;
		this->tiempoHastaRecuperacion= tiempoRecuperacionActual;
		this->tiempoHastaCosecha=TIEMPO_COSECHA_CULTIVO_COSECHADO;

	}
}
