#ifndef ALMACEN_H_
#define ALMACEN_H_

#include "Lista.h"
#include "Destino.h"
#include "Cosecha.h"

class Almacen {
private:
	Lista<Cosecha*>* cosechas;
	unsigned int capacidadMaximaAlmacen;
public:
	/*
	 * PRE:
	 * POST:
	 */
	Almacen();

	/*
	 * PRE:
	 * POST:
	 */
	Almacen(unsigned int coeficienteCapacidadAlmacen, unsigned int filas, unsigned int columnas);
	/*
	 *
	 *
	 */
	unsigned int obtenerCapacidadMaxima();

	/*
	 *
	 *
	 */
	void enviarCosechas();

	/*
	 *
	 *
	 */
	void agregarCosechas();

	/* esta lleno el almacen?
	 *
	 *
	 * POST: devuelve true si es asi y false si no
	 */
	bool estaLleno();
	/*
	 *
	 *
	 *
	 */
	Lista<Cosecha*>* obtenerCosechas();
	//TODO: Implementar metodos necesarios...

};

#endif
