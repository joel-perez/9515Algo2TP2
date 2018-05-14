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
	 * POST:
	 */
	void comprarTerreno();

	/*
	 * PRE:
	 * POST:
	 */
	void venderTerreno();

	//TODO: Implementar todo lo que sea necesario...
};

#endif
