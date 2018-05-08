#ifndef JUEGO_H_
#define JUEGO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Cultivo.h"
#include "Dificultad.h"
#include "Consola.h"
#include "Constantes.h"

class Juego {
private:
	Lista<Jugador*>* jugadores;
	Lista<Cultivo*>* cultivos;
	Lista<Dificultad*>* dificultades;
	unsigned int turnos;
	unsigned int turnoActual;
	Consola consola;

public:
	Juego();
	void iniciarJuego();

	Lista<Jugador*>* obtenerJugadores();
	void administrarAguaDelTurno(Jugador* jugador);
	void solicitarAcciones(Jugador* jugador);
	void procesarTurno(Jugador* jugador);
	void solicitarDatosIniciales();

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...

};

#endif
