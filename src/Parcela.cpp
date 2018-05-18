#include <iostream>
#include "Parcela.h"

using namespace std;

Parcela::Parcela() {
	cout << "Soy una nueva parcela!!" << endl;
	this->estado = PARCELA_LIBRE;
	this->estaRegada = false;
	this->cultivo = Cultivo();
	this->tiempoHastaCosecha = cultivo.obtenerTiempoHastaCosecha();
	this->tiempoHastaRecuperacion = this->cultivo.obtenerTiempoRecuperacion();
	this->rentabilidad = RENTABILIDAD_CULTIVO_VACIO;
}

Cultivo Parcela::obtenerCultivo() {
	return this->cultivo;
}

string Parcela::obtenerEstado() {
	return "Completar!!!"; //TODO: Completar...
}
