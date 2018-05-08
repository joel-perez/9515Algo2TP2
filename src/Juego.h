#ifndef JUEGO_H_
#define JUEGO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Cultivo.h"
#include "Dificultad.h"
#include "Consola.h"

class Juego {
private:
	Lista<Jugador*>* jugadores;
	Lista<Cultivo*>* cultivos;
	Lista<Dificultad*>* dificultades;
	unsigned int turnos;

public:
	Juego();
	void iniciarJuego();

	Lista<Jugador*>* obtenerJugadores();

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...

};

#endif
