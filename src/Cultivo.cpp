#include <iostream>
#include "Cultivo.h"

Cultivo::Cultivo(){
	this->nombre ="";
	this->costo = 0;
	this->tiempoDeCrecimiento = 0;
	this->rentabilidad = 0;
	this->tiempoDeRecuperacion = 0;
	this->consumoDeAgua = 0;

}

Cultivo::Cultivo(std::string nombreCultivo, int costo,  int tiempoDeCrecimiento, int rentabilidad, int tiempoDeRecuperacion, int consumoDeAgua){
	this->nombre =nombreCultivo;
	this->costo = costo;
	this->tiempoDeCrecimiento = tiempoDeCrecimiento;
	this->rentabilidad = rentabilidad;
	this->tiempoDeRecuperacion = tiempoDeRecuperacion;
	this->consumoDeAgua = consumoDeAgua;
}

int Cultivo::obtenerTiempoHastaCosecha() {

}

int Cultivo::obtenerTiempoRecuperacion() {

}

