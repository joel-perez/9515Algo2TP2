#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Jugador.h"
#include "Constantes.h"

Jugador::Jugador(std::string nombre, Dificultad dificultad,
		unsigned int altoTerreno, unsigned int anchoTerreno) {
	this->terrenos = new Lista<Terreno*>; //TODO: Ver si aca es mejor opcion para inicializar el primer terreno vacio para el jugador...
	this->almacenes = new Lista<Almacen*>;
	this->tanque = new Tanque(altoTerreno, anchoTerreno,
			dificultad.obtenerCoeficienteTamanioTanque());
	this->creditos = dificultad.obtenerCoeficienteCreditosAsignados()
	//*altoTerreno * anchoTerreno;
	this->nombre = nombre;
	this->aguaPorTurno = 0;
	this->sigueJugando = true;
	this->terrenoActual = NULL;
}

void Jugador::comprarTerreno() {
}

void Jugador::venderTerreno() {
}

Lista<Terreno*>* Jugador::obtenerTerrenos() {
	return this->terrenos;
}
Lista<Almacen*>* Jugador::obtenerAlmacenes() {
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
	return (this->creditos -= creditoUtilizado);
}

void Jugador::agregarCredito(unsigned int creditoUtilizado) {
	this->creditos += creditoUtilizado;
}

unsigned int Jugador::incrementoDeGananciaPorHaberLLegadoADestino(
		unsigned int gananciaPorLlegarADestino) {
	return (this->creditos += gananciaPorLlegarADestino);
}

Tanque* Jugador::obtenerTanque() {
	return this->tanque;
}

void Jugador::abandonarJuego() {
	this->sigueJugando = false;
}

void Jugador::cambiarTerrenoActual(unsigned int indiceTerreno) {
	this->terrenoActual = this->terrenos->obtener(indiceTerreno);
}

bool Jugador::abandono() {
	return !this->sigueJugando;
}

Jugador::~Jugador() {
	this->terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		delete this->terrenos->obtenerCursor();
	}
	this->almacenes->iniciarCursor();
	while (almacenes->avanzarCursor()) {
		delete this->almacenes->obtenerCursor();
	}

	delete terrenos;
	delete almacenes;
	delete tanque;
}
