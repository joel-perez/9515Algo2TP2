#include "Jugador.h"

Jugador::Jugador() {
	this->terrenos= new Lista<Terreno*>;
	this->almacenes=new Lista<Almacen*>;
	this->tanquesAgua=new Lista<Tanque*>;
	this->creditos=0;
}

Jugador::Jugador(const Jugador& jugador){

}

void Jugador::comprarTerreno() {
}
void Jugador::venderTerreno() {
}
