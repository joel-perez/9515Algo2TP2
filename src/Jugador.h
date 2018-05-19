#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Tanque.h"
#include "Lista.h"
#include "Terreno.h"
#include "Almacen.h"
#include "Constantes.h"

class Jugador {
private:
	Lista<Terreno*>* terrenos;
	Lista<Almacen*>* almacenes;
	Lista<Tanque*>* tanquesAgua;
	unsigned int creditos;
	std::string  nombre;
	unsigned int aguaPorTurno;

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
	 *
	 * POST: devuelve el nombre del jugador.
	 */
	std::string obtenerNombre();
	/*
	 *
	 * POST: asigna la cantidad de agua al azar que tendra en el turno.
	 */
	void asignarAguaDelTurno(unsigned int multiplicador);

	/*
	 *
	 * POST: devuelve la cantidad de credito del jugador.
	 */
	unsigned int obtenerCreditos();
	/*
	 *
	 * POST: devuelve los tanques de agua del jugadorActual.
	 */
	Lista<Tanque*>* obtenerTanques();

private:
	/*
	 *
	 * POST: devuelve un numero al azar.
	 */
	unsigned int tirarDado();

	//TODO: Implementar todo lo que sea necesario...
};

#endif
