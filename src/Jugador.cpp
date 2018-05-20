#include <ctime>
#include <cstdlib>

#include "Jugador.h"
#include "Constantes.h"

Jugador::Jugador(std::string nombre) {
	this->terrenos = new Lista<Terreno*>;
	this->almacenes = new Lista<Almacen*>;
	this->tanque = new Tanque();
	this->creditos = 0;
	this->nombre = nombre;
	this->aguaPorTurno = 0;
	srand(time(NULL));
}

Jugador::Jugador(const Jugador& jugador) {

}

void Jugador::comprarTerreno() {
}

void Jugador::venderTerreno() {
}

Lista<Terreno*>* Jugador::obtenerTerrenos() {
	return this->terrenos;
}

Terreno* Jugador::obtenerTerrenoActual() {
	return this->terrenoActual;
}

void Jugador::agregarTerreno(Terreno* terreno) {
	this->terrenos->agregar(terreno);
}

std::string Jugador::obtenerNombre() {
	return this->nombre;
}

unsigned int Jugador::obtenerCreditos() {
	return this->creditos;
}

Tanque* Jugador::obtenerTanque() {
	return this->tanque;

}

