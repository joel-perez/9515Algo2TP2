#include <ctime>
#include <cstdlib>

#include "Jugador.h"
#include "Constantes.h"

Jugador::Jugador(std::string nombre) {
	this->terrenos = new Lista<Terreno*>;
	this->almacenes = new Lista<Almacen*>;
	this->tanquesAgua = new Lista<Tanque*>;
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
std::string Jugador::obtenerNombre(){
	return this->nombre;
}
unsigned int Jugador::obtenerCreditos(){
	return this->creditos;
}
unsigned int Jugador::tirarDado(){
	unsigned int potenciador =(rand()%CARAS_DADO)+1;
	return potenciador;
}

void Jugador::asignarAguaDelTurno(){
	this->aguaPorTurno = this->tirarDado() * MULTIPLICADOR_DADO;
}
