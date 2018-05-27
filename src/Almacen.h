#ifndef ALMACEN_H_
#define ALMACEN_H_

#include "Lista.h"
#include "Destino.h"

class Almacen {
private:
	Lista<Cultivo*>* cultivos;
	unsigned int capacidadMaximaAlmacen;

public:
	/*
	 * PRE:
	 * POST:Almacen listo para usar.
	 */
	Almacen();

	/*
	 * PRE:
	 * POST:
	 */
	Almacen(unsigned int coeficienteCapacidadAlmacen, unsigned int filas,
			unsigned int columnas);
	/*
	 *
	 *
	 */
	unsigned int obtenerCapacidadMaxima();

	/*
	 *
	 *
	 */
	void enviarCultivos(unsigned int posicion);

	/*
	 * POST: Agrega el cultivo indicado al almacen actual.
	 */
	void agregarCultivo(Cultivo* cultivo);

	/*
	 * POST: devuelve true si es esta lleno el almacen
	 */
	bool estaLleno();

	/*
	 * PRE: ~
	 * POST: devuelve las cosechas de ese almacen.
	 */
	Lista<Cultivo*>* obtenerCultivos();

	/*
	 * PRE:~
	 * POST:devuelve la cantidad de cosechas de ese almacen.
	 */
	unsigned int obtenerCantidadDeCultivosEnUnAlmacen();

	/*
	 * PRE:~
	 * POST:devuelve la cosecha indicada por cosechaElegida.
	 */
	Cultivo* obtenerUnCultivo(unsigned int cultivoElegido);

	~Almacen();

};

#endif
