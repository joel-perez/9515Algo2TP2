#ifndef CONSOLA_H_
#define CONSOLA_H_

#include "Lista.h"
#include "Jugador.h"

class Consola {
public:
	unsigned int solicitarIngresoNumerico(unsigned int minValor, unsigned int maxValor);
	void mostrarBienvenida();
	void mostrarDatosDelTurno(Jugador* jugadorActual);
	void mostrarFin(Lista<Jugador*>* jugadores);
	void mostrarTerreno(Jugador* jugadorActual);
	void solicitarEnterParaSalir();
};

#endif
