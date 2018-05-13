#ifndef CONSOLA_H_
#define CONSOLA_H_

#include "Lista.h"
#include "Jugador.h"
#include "Archivo.h"

class Consola {
public:
	/*
	 * PRE:
	 * POST:
	 */
	unsigned int solicitarIngresoNumerico(unsigned int minValor,
			unsigned int maxValor);

	/*
	 * PRE:
	 * POST:
	 */
	void mostrarBienvenida();

	/*
	 * PRE:
	 * POST:
	 */
	void mostrarDatosDelTurno(Jugador* jugadorActual);

	/*
	 * PRE:
	 * POST:
	 */
	void mostrarFin(Lista<Jugador*>* jugadores);

	/*
	 * PRE:
	 * POST:
	 */
	void mostrarTerreno(Jugador* jugadorActual);

	/*
	 * PRE:
	 * POST:
	 */
	void solicitarEnterParaSalir();

	/*
	 * PRE:
	 * POST:
	 */
	std::string SolicitarIngresoLineaTexto();
};

#endif
