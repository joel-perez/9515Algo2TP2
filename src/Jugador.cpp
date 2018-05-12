#include "Jugador.h"

Jugador::Jugador() {
	this->terrenos= new Lista<Terreno*>;
	this->almacenes=new Lista<Almacen*>;
	this->tanquesAgua=new Lista<Tanque*>;
	this->creditos=0;
	this->nombre = NOMBRE_JUGADOR_DEFAULT;
}

Jugador::Jugador(const Jugador& jugador){

}

void Jugador::comprarTerreno() {
}
void Jugador::venderTerreno() {
}
