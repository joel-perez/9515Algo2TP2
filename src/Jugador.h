#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Tanque.h"
#include "Lista.h"
#include "Terreno.h"
#include "Tanque.h"
#include "Almacen.h"
#include "Constantes.h"

class Jugador {
private:
	Lista<Terreno*>* terrenos;
	Lista<Almacen*>* almacenes;
	Tanque* tanque;
	unsigned int creditos;
	std::string nombre;
	unsigned int aguaPorTurno;
	Terreno* terrenoActual;

public:
	/*
	 * PRE:
	 * POST: Jugador listo para jugar.
	 */
	Jugador(std::string nombre);

	/*
	 * PRE:
	 * POST:
	 */
	Jugador(const Jugador& jugador);

	/*
	 * PRE:
	 * POST:compra un terreno durantes el turnoActual;
	 */
	void comprarTerreno();

	/*
	 * PRE:~
	 * POST: vende un terreno durantes el turnoActual;
	 */
	void venderTerreno();

	/*
	 * PRE:~
	 * POST:devuelve los terrenos de jugadorActual.
	 */
	Lista<Terreno*>* obtenerTerrenos();

	/*
	 * POST: Agrega un terreno a la lista de terrenos del jugador.
	 */
	void agregarTerreno(Terreno* terreno);

	/*
	 *
	 * POST: devuelve el nombre del jugador.
	 */
	std::string obtenerNombre();

	/*
	 *
	 * POST: devuelve la cantidad de credito del jugador.
	 */
	unsigned int obtenerCreditos();
	/*
	 *
	 * POST: devuelve los tanques de agua del jugadorActual.
	 */
	Tanque* obtenerTanque();

	/*
	 * POST: Devuelve el terreno actual con que esta jugando.
	 */
	Terreno* obtenerTerrenoActual();
};

#endif
