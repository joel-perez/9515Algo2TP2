#ifndef DESTINO_H_
#define DESTINO_H_

#include <string>
#include "Cultivo.h"

class Destino {
private:
	std::string nombre;
	unsigned int distanciaEnKm;
	unsigned int costoPorKm;
	Cultivo cultivo;

public:
	/*
	 * PRE:
	 * POST:Destino listo para usar:
	 */
	Destino();

	/*
	 * PRE:~
	 * POST:Destino  lista para usar;
	 */
	Destino(std::string nombreDestino, unsigned int km, unsigned int precio,
			std::string cultivoAceptado);

	/*
	 * PRE:
	 * POST: Devuelve el nombre de este Destino.
	 */
	std::string obtenerNombre();

	/*
	 *PRE:~
	 *POST:
	 */
	Cultivo obtenerCultivoQueAcepta();
	/*
	 *PRE:
	 *POST: Devuelve el costo del  envio de una
	 *      cosecha (un cultivo) a destino.
	 *
	 */
	unsigned int obtenerCostoDeEnvio();
	/*
	 *PRE:~
	 *POST: Devuelve la dista [km] del envio de la cosecha (Un cultivo).
	 */
	unsigned int obtenerDistancia();

	/*
	 * POST: devuelve el costo final del envio de la cosecha.
	 */
	unsigned int obtenerCostoDeEnvioFinal();
};

#endif
