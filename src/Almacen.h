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
	void enviarCosechas();

	/*////////////////////////////////////
	 *
	 *
	 */
	void agregarCosechaAmiAlmacen(Cultivo* cultivo);

	/* esta lleno el almacen?
	 *
	 *
	 * POST: devuelve true si es asi y false si no
	 */
	bool estaLleno();

	/*
	 * PRE:~
	 * POST:devuelve las cosechas de ese almacen.
	 */

	Lista<Cosecha*>* obtenerCosechas();
	//TODO: Implementar metodos necesarios...




	/*///////////////////////////////////////////////
	 * PRE:~
	 * POST:devuelve la cantidad de cosechas de ese almacen.
	 */
	unsigned int obtenerCantidadDeCosechasEnUnAlmacen(){
		return(this->cosechas->contarElementos());
	}

	/*
	 * PRE:~
	 * POST:devuelve la cosecha indicada por cosechaElegida.
	 */
	Cosecha* obtenerUnaCosecha(unsigned int cosechaElegida) {

		return (this->cosechas->obtener(cosechaElegida));
	}



};

#endif
