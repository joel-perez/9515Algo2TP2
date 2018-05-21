#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Jugador.h"
#include "Constantes.h"

Jugador::Jugador(std::string nombre, Dificultad dificultad,
		unsigned int altoTerreno, unsigned int anchoTerreno) {
	this->terrenos = new Lista<Terreno*>;
	this->almacenes = new Lista<Almacen*>;
	this->tanque = new Tanque(altoTerreno, anchoTerreno,
			dificultad.obtenerCoeficienteTamanioTanque());
	this->creditos = dificultad.obtenerCoeficienteCreditosAsignados()
			* altoTerreno * anchoTerreno;
	this->nombre = nombre;
	this->aguaPorTurno = 0;
	this->sigueJugando = true;
	srand(time(NULL));
}

Jugador::Jugador(const Jugador& jugador) {
	this->sigueJugando = true;
}

void Jugador::comprarTerreno() {
}

void Jugador::venderTerreno() {
}

Lista<Terreno*>* Jugador::obtenerTerrenos() {
	return this->terrenos;
}
Lista<Almacen*>* Jugador::obtenerAlmacenes(){
	return this->almacenes;
}
Terreno* Jugador::obtenerTerrenoActual() {
	return this->terrenoActual;
}

void Jugador::agregarTerreno(Terreno* terreno) {
	this->terrenos->agregar(terreno);
	this->terrenoActual = terreno;
}
void Jugador::agregarAlmacen(Almacen* almacen) {
	this->almacenes->agregar(almacen);
}
std::string Jugador::obtenerNombre() {
	return this->nombre;
}

unsigned int Jugador::obtenerCreditos() {
	return this->creditos;
}

unsigned int Jugador::restarCredito(unsigned int creditoUtilizado) {
	return (this->creditos - creditoUtilizado);
}

Tanque* Jugador::obtenerTanque() {
	return this->tanque;

}

void Jugador::abandonarJuego() {
	this->sigueJugando = false;
}

bool Jugador::abandono() {
	return !this->sigueJugando;
}
