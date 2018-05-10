#ifndef JUEGO_H_
#define JUEGO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Cultivo.h"
#include "Dificultad.h"
#include "Consola.h"
#include "Constantes.h"
#include "Archivo.h"

class Juego {
private:
	Lista<Jugador*>* jugadores;
	Lista<Cultivo*>* cultivos;
	Lista<Dificultad*>* dificultades;
	unsigned int turnos;
	unsigned int turnoActual;
	Consola consola;
	Archivo archivo;

public:
	Juego();
	void iniciarJuego();

	Lista<Jugador*>* obtenerJugadores();
	void administrarAguaDelTurno(Jugador* jugador);
	void solicitarAcciones(Jugador* jugador);
	void procesarTurno(Jugador* jugador);

	/*
	 * PRE:
	 * POST: Solicita al usuario los datos con los cuales se va a iniciar el juego.
	 */
	void solicitarDatosIniciales();
	void cargarArchivos();

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...

};

#endif
