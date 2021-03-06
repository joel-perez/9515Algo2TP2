#include <iostream>
#include "Cultivo.h"

using namespace std;

Cultivo::Cultivo() {
	this->nombre = "#";
	this->costo = 0;
	this->tiempoDeCrecimiento = 0;
	this->rentabilidad = 0;
	this->tiempoDeRecuperacion = 0;
	this->consumoDeAgua = 0;
}

Cultivo::Cultivo(std::string nombreCultivo) {
	this->nombre = nombreCultivo;
	this->costo = 0;
	this->tiempoDeCrecimiento = 0;
	this->rentabilidad = 0;
	this->tiempoDeRecuperacion = 0;
	this->consumoDeAgua = 0;
}

Cultivo::Cultivo(std::string nombreCultivo, int costo, int tiempoDeCrecimiento,
		int rentabilidad, int tiempoDeRecuperacion, int consumoDeAgua) {
	this->nombre = nombreCultivo;
	this->costo = costo;
	this->tiempoDeCrecimiento = tiempoDeCrecimiento;
	this->rentabilidad = rentabilidad;
	this->tiempoDeRecuperacion = tiempoDeRecuperacion;
	this->consumoDeAgua = consumoDeAgua;
}

int Cultivo::obtenerTiempoHastaCosecha() {
	return this->tiempoDeCrecimiento;
}

int Cultivo::obtenerTiempoRecuperacion() {
	return this->tiempoDeRecuperacion;
}

string Cultivo::obtenerNombre() {
	return this->nombre;
}

unsigned int Cultivo::obtenerCosto() {
	return this->costo;

}
unsigned int Cultivo::obtenerRentabilidad() {
	return this->rentabilidad;
}

unsigned int Cultivo::obtenerConsumoDeAgua() {
	return this->consumoDeAgua;
}

void Cultivo::asignarConsumoDeAgua(unsigned int consumoDeAgua) {
	this->consumoDeAgua = consumoDeAgua;
}

void Cultivo::asignarCosto(unsigned int costo) {
	this->costo = costo;
}

void Cultivo::asignarNombre(std::string nombre) {
	this->nombre = nombre;
}

void Cultivo::asignarRentabilidad(unsigned int rentabilidad) {
	this->rentabilidad = rentabilidad;
}

void Cultivo::asignarTiempoDeCrecimiento(unsigned int tiempoDeCrecimiento) {
	this->tiempoDeCrecimiento = tiempoDeCrecimiento;
}

void Cultivo::asignarTiempoDeRecuperacion(unsigned int tiempoDeRecuperacion) {
	this->tiempoDeRecuperacion = tiempoDeRecuperacion;
}

