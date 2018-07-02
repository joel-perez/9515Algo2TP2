#include "Envio.h"

using namespace std;

Envio::Envio(string nombre, unsigned int precio) {
	if (nombre != "" && precio >= 0) {
		this->nombreCultivo = nombre;
		this->precioEnvio = precio;
	}
}
void Envio::cambiarNombreCultivo(string nombre) {
	this->nombreCultivo = nombre;
}
void Envio::cambiarPrecio(unsigned int precio) {
	if (precio >= 0) {
		this->precioEnvio = precio;
	}
}

string Envio::obtenerNombreCultivo(){
	return this->nombreCultivo;
}
unsigned int Envio::obtenerPrecioEnvio(){
	return this->precioEnvio;
}
