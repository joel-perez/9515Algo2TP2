#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = new Lista<Jugador*>;
}

Lista<Jugador*>* Juego::obtenerJugadores() {
	return this->jugadores;
}

void Juego::iniciarJuego() {
	MostrarBienvenida();
}

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...
