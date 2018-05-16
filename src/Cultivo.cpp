#include <iostream>
#include "Cultivo.h"

Cultivo::Cultivo(){

}

Cultivo::Cultivo(std::string nombreCultivo, int costo,  int tiempoDeCrecimiento, int rentabilidad, int tiempoDeRecuperacion, int consumoDeAgua){
	this->nombre =nombreCultivo;
	this->costo = costo;
	this->tiempoDeCrecimiento = tiempoDeCrecimiento;
	this->rentabilidad = rentabilidad;
	this->tiempoDeRecuperacion = tiempoDeRecuperacion;
	this->consumoDeAgua = consumoDeAgua;
}



