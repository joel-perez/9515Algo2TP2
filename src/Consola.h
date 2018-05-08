#ifndef CONSOLA_H_
#define CONSOLA_H_

#include "Lista.h"
#include "Jugador.h"

class Consola {
public:
	void MostrarBienvenida();
	void mostrarDatosDelTurno(Jugador* jugadorActual);
	void mostrarTerreno(Jugador* jugadorActual);
	void mostrarFin(Lista<Jugador*>* jugadores);
};

#endif
