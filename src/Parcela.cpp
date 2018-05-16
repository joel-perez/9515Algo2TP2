#include <iostream>
#include "Parcela.h"

Parcela::Parcela() {
	this->estado=PARCELA_LIBRE;
	this->estaRegada=false;
	this->cultivo= Cultivo();
	this->tiempoHastaCosecha=cultivo.obtenerTiempoHastaCosecha();
	this->tiempoHastaRecuperacion = this->cultivo.obtenerTiempoRecuperacion();
	this->rentabilidad = RENTABILIDAD_CULTIVO_VACIO;
}

Cultivo Parcela::obtenerCultivo() {
	return this->cultivo;
}
