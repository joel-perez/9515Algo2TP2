#ifndef DESTINO_H_
#define DESTINO_H_

#include <string>
#include "Cultivo.h"

class Destino {
private:
	std::string nombre;
	unsigned int distanciaEnKm;
	float costoPorKm;
	Cultivo cultivo;

public:
	/*
	 * PRE:
	 * POST:
	 */
	Destino();

	/*
	 * PRE:
	 * POST:
	 */
	Destino(std::string nombreDestino, int km, int precio,
			std::string cultivoAceptado);

	/*
	 * PRE:
	 * POST: Devuelve el nombre de este Destino.
	 */
	std::string obtenerNombre();
};

#endif
