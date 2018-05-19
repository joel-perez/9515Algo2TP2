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
	Lista<Destino*>* destinos;
	Dificultad dificultad;
	unsigned int altoTerreno;
	unsigned int anchoTerreno;
	unsigned int turnos;
	unsigned int turnoActual;
	Consola consola;
	Archivo archivo;
	unsigned int numeroDeJugadores;

public:
	/*
	 * post: Juego listo para jugar una partida.
	 */
	Juego();

	/*
	 * PRE:
	 * POST:carga los datos asociados para el arranque de Juego
	 */
	void iniciarJuego();

	/*
	 * PRE:~
	 * POST:se obtiene los jugadores de la partida.
	 */
	Lista<Jugador*>* obtenerJugadores();

	/*
	 *
	 * POST: se obtiene los cultivos de la partida.
	 */
	Lista<Cultivo*>* obtenerCultivos();

	/*
	 * POST: Devuelve la lista de destinos que se cargo desde un archivo.
	 */
	Lista<Destino*>* obtenerDestinos();

	/*
	 * PRE:
	 * POST:
	 */
	Cultivo* obtenerCultivoPorNombre(std::string nombreCultivo);

	/*
	 * PRE:~
	 * POST:Acumula el agua recibida con la que hay en el tanque, si
	 * supera un cierto limite, el sobrante se pierde quedando el tanque
	 *  lleno hasta el maximo.
	 */
	void administrarAguaDelTurno(Jugador* jugador);

	/*
	 * PRE:~
	 * POST:Solicita al jugador que realice una o mas acciones
	 * dentro del turnoActual.
	 */
	void solicitarAcciones(Jugador* jugador);

	/*
	 * PRE:~
	 * POST:Realiza las operaciones correspondientes al avance de un turno luego
	 * de que el jugador haya realizado las acciones que considero necesarias.
	 */
	void procesarTurno(Jugador* jugador);

	/*
	 * PRE:
	 * POST: Solicita al usuario los datos con los cuales se va a iniciar el juego.
	 */
	void solicitarDatosIniciales();

	/*
	 * PRE: Los archivos deben de existir.
	 * POST: obtengo a "cultivos" cargado.
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
	Lista<Jugador*>* solicitarJugadores();

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

	/*
	 *
	 * POST: obtiene la dificultad del juego
	 */
	Dificultad obtenerDificultad();

	/*
	 * POST: Libera la memoria que habia sido solicitada en el Heap.
	 */
	~Juego();

};

#endif
