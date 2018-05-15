#ifndef JUEGO_H_
#define JUEGO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Cultivo.h"
#include "Dificultad.h"
#include "Consola.h"
#include "Constantes.h"
#include "Archivo.h"

#include "Terreno.h"

class Juego {
private:
	Lista<Jugador*>* jugadores;
	Lista<Cultivo*>* cultivos;
	Dificultad dificultad;
	Terreno* terreno;
	unsigned int turnos;
	unsigned int turnoActual;
	Consola consola;
	Archivo archivo;
	unsigned int  numeroDeJugadores;

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
	 * PRE:~
	 * POST:se obtiene los jugadores de la partida.
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
	 * PRE:~
	 * POST:el Juego tiene una cantidad de TURNOS definidos
	 */
	unsigned int solicitarCantidadTurnos();

	/*
	 * PRE: Se ingresa al menos un jugador.
	 * POST: Jugadore listos para jugar.
	 */
	void solicitarJugadores();

	/*
	 * PRE:~
	 * POST:Crea un Terreno dinamico de 'N' filas x 'M' columnas.
	 *     el usuario ingresa por teclado las FILAS y las COLUMNAS.
	 */
	void solicitarTamanioTerreno();

	/*
	 *PRE :
	 * 		 'FACIL' asigna los valores predeterminados a Dificultad;
	 * 		 'MEDIO' idem.
	 * 		 'DIFICIL' indem.
	 *POST: El juego tiene una Dificultad definida
	 * 		 EL USUARIO YA PUEDE COMENZAR A JUGAR.
	 */
	Dificultad solicitarDificultad();

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...

};

#endif
