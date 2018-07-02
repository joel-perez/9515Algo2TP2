#include <iostream>
#include "Parcela.h"

using namespace std;

Parcela::Parcela() {
	this->estadoParcela = VACIA;
	this->estaRegada = false;
	this->cultivo = NULL;
	this->tiempoHastaCosecha = 0;
	this->tiempoHastaRecuperacion = 0;
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
		estadoParaMostrar = PARCELA_VACIA;
		break;
	case SEMBRADA:
		estadoParaMostrar = this->obtenerNombre().substr(0, 10);
		break;
	case SECA:
		estadoParaMostrar = PARCELA_SECA;
		break;
	case PODRIDA:
		estadoParaMostrar = PARCELA_PODRIDA;
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

void Parcela::cosechar(Almacen* almacen) {
	almacen->agregarCultivo(this->cultivo);
	unsigned int tiempoRecuperacionActual =
			cultivo->obtenerTiempoRecuperacion();
	this->cultivo = NULL;
	this->estadoParcela = RECUPERACION;
	this->estaRegada = false;
	this->tiempoHastaRecuperacion = tiempoRecuperacionActual;
	this->tiempoHastaCosecha = TIEMPO_COSECHA_CULTIVO_COSECHADO;
}

void Parcela::procesarTurno() {
	if (this->estaOcupada()) {
		switch (this->obtenerEstado()) {
		case SEMBRADA:
			this->procesarTurnoCultivoNormal();
			break;
		case SECA:
			this->procesarTurnoCultivoSeco();
			break;
		case PODRIDA:
			this->procesarTurnoCultivoPodrido();
			break;
		case RECUPERACION:
			this->procesarTurnoCultivoEnRecuperacion();
			break;
		default:
			break;
		}
	}
}

void Parcela::procesarTurnoCultivoNormal() {
	if (this->yaEstaRegada()) {
		this->estaRegada = false;
		if (this->tiempoHastaCosecha >= 0) {
			this->tiempoHastaCosecha--;
		} else {
			this->estadoParcela = PODRIDA;
			this->tiempoHastaRecuperacion = this->tiempoHastaRecuperacion
					* TIEMPO_RECUPERACION_PROPORCIONAL_CULTIVO_PODRIDO;
		}
	} else {
		this->estadoParcela = SECA;
		this->estaRegada = false;
		this->tiempoHastaCosecha = TIEMPO_COSECHA_CULTIVO_SECO;
		this->tiempoHastaRecuperacion = TIEMPO_RECUPERACION_CULTIVO_SECO;
		this->rentabilidad = RENTABILIDAD_CULTIVO_SECO;
	}
}

void Parcela::procesarTurnoCultivoSeco() {
	this->cultivo = NULL;
	this->estadoParcela = VACIA;
	this->estaRegada = false;
	this->tiempoHastaCosecha = TIEMPO_COSECHA_CULTIVO_SECO;
	this->tiempoHastaRecuperacion = TIEMPO_RECUPERACION_CULTIVO_SECO;
	this->rentabilidad = RENTABILIDAD_CULTIVO_SECO;
}

void Parcela::procesarTurnoCultivoPodrido() {
	if (this->tiempoHastaRecuperacion > 0) {
		this->tiempoHastaRecuperacion--;
	} else {
		this->cultivo = NULL;
		this->estadoParcela = VACIA;
		this->estaRegada = false;
		this->tiempoHastaCosecha = TIEMPO_COSECHA_CULTIVO_PODRIDO;
		this->tiempoHastaRecuperacion = TIEMPO_RECUPERACION_CULTIVO_PODRIDO;
		this->rentabilidad = RENTABILIDAD_CULTIVO_PODRIDO;

	}
}

void Parcela::procesarTurnoCultivoEnRecuperacion() {
	if (this->tiempoHastaRecuperacion > 0) {
		this->tiempoHastaRecuperacion--;
	} else {
		this->cultivo = NULL;
		this->estadoParcela = VACIA;
		this->estaRegada = false;
		this->tiempoHastaCosecha = TIEMPO_COSECHA_CULTIVO_RECUPERACION;
		this->tiempoHastaRecuperacion =
				TIEMPO_RECUPERACION_CULTIVO_RECUPERACION;
		this->rentabilidad = RENTABILIDAD_CULTIVO_RECUPERACION;
	}
}

Parcela::~Parcela() {

}
