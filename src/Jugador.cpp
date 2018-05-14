#include "Jugador.h"

Jugador::Jugador(std::string nombre) {
	this->terrenos= new Lista<Terreno*>;
	this->almacenes=new Lista<Almacen*>;
	this->tanquesAgua=new Lista<Tanque*>;
	this->creditos=0;
	this->nombre=nombre;
}

Jugador::Jugador(const Jugador& jugador){

}

void Jugador::comprarTerreno() {
}
void Jugador::venderTerreno() {
}
