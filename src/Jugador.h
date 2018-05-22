#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Tanque.h"
#include "Lista.h"
#include "Terreno.h"
#include "Tanque.h"
#include "Almacen.h"
#include "Constantes.h"
#include "Dificultad.h"

class Jugador {
private:
	Lista<Terreno*>* terrenos;
	Lista<Almacen*>* almacenes;
	Tanque* tanque;
	unsigned int creditos;
	std::string nombre;
	unsigned int aguaPorTurno;
	Terreno* terrenoActual;
	bool sigueJugando;

public:
	/*
	 * PRE:
	 * POST: Jugador listo para jugar.
	 */
	Jugador(std::string nombre, Dificultad dificultad, unsigned int altoTerreno,
			unsigned int anchoTerreno);

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
	 * POST: devuelve los almacenes del jugador
	 */
	Lista<Almacen*>* obtenerAlmacenes();
	/*
	 * POST: Agrega un terreno a la lista de terrenos del jugador.
	 */
	void agregarTerreno(Terreno* terreno);
	/*
	 * POST: Agrega un almacen a la lista de Almacenes del jugador.
	 */
	void agregarAlmacen(Almacen* almacen);
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
	 * POST: el creditoActual le resta al creditoUtilizado y devuelve el nuevo saldo.
	 */
	unsigned int restarCredito(unsigned int creditoUtilizado);

	/*////////////////////////////////////////////////////////////quitar despues
	 *
	 * POST: el creditoActual le suma la gananciaPorLlegarADestino y devuelve el nuevo saldo.
	 */

	unsigned int incrementoDeGananciaPorHaberLLegadoADestino(
			unsigned int gananciaPorLlegarADestino);
	/*
	 *
	 * POST: devuelve los tanques de agua del jugadorActual.
	 */
	Tanque* obtenerTanque();

	/*
	 * POST: Devuelve el terreno actual con que esta jugando.
	 */
	Terreno* obtenerTerrenoActual();

	/*
	 * POST: Establece al jugador como que no va a seguir jugando.
	 */
	void abandonarJuego();

	/*
	 *
	 */
	void cambiarTerrenoActual(unsigned int indiceTerreno);

	/*
	 * POST: Indica si el jugador sigue jugando o no.
	 */
	bool abandono();
};

#endif
