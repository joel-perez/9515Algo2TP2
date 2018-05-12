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
	Dificultad dificultad;
	unsigned int turnos;
	unsigned int turnoActual;
	Consola consola;
	Archivo archivo;

public:
	/*
	 * post: Juego listo para jugar una partida.
	 */
	Juego();

	/*
	 * PRE:
	 * POST:
	 */
	void iniciarJuego();

	/*
	 * PRE:
	 * POST:
	 */
	Lista<Jugador*>* obtenerJugadores();

	/*
	 * PRE:
	 * POST:
	 */
	void administrarAguaDelTurno(Jugador* jugador);

	/*
	 * PRE:
	 * POST:
	 */
	void solicitarAcciones(Jugador* jugador);

	/*
	 * PRE:
	 * POST:
	 */
	void procesarTurno(Jugador* jugador);

	/*
	 * PRE:
	 * POST: Solicita al usuario los datos con los cuales se va a iniciar el juego.
	 */
	void solicitarDatosIniciales();

	/*
	 * PRE:
	 * POST:
	 */
	void cargarArchivos();

	/*
	 * PRE:
	 * POST:
	 */
	unsigned int solicitarCantidadTurnos();

	/*
	 * PRE:
	 * POST:
	 */
	Lista<Jugador*>* solicitarJugadores();

	/*
	 * PRE:
	 * POST:
	 */
	void solicitarTamanioTerreno();

	/*
	 * PRE:
	 * POST:
	 */
	Dificultad solicitarDificultad();

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...

};

#endif
