#ifndef CULTIVO_H_
#define CULTIVO_H_

#include "Lista.h"
#include <string>

class Cultivo {
private:
	std::string nombre;
	unsigned int costo;
	unsigned int tiempoDeCrecimiento;
	unsigned int rentabilidad;
	unsigned int tiempoDeRecuperacion;
	unsigned int consumoDeAgua;

public:
	/*
	 * PRE:
	 * POST:Incializa Cultivo con el nombreCultico, costo, tiempoDeCrecimiento,
	 * 		rentabilidad,tiempoDeRecuperacion y consumoDeAgua, asociados.
	 */
	Cultivo(std::string nombreCultivo, int costo, int tiempoDeCrecimiento,
			int rentabilidad, int tiempoDeRecuperacion, int consumoDeAgua);

	/*PRE:~
	 *
	 *POST: Crea un cultivo vacio.
	 */
	Cultivo();
	/*
	 *
	 *
	 */
	Cultivo(std::string nombreCultivo);

	/*
	 * POST:Devuelve la cantidad de turnos necesarios desde que se siembra las semillas
	 *     hasta que se puede cosechar una parcela del cultivo.
	 */
	int obtenerTiempoHastaCosecha();

	/*
	 * POST: Devuelve la cantidad de turnos que se necesitan para volver a utilizar una
	 * 		parcela despues de haber cosechado el cultivo.
	 */
	int obtenerTiempoRecuperacion();

	/*
	 * POST:Devuelve el nombre del cultivo.
	 */
	std::string obtenerNombre();
	/*
	 * POST: Devuelve el consto del cultivo.
	 *
	 */
	unsigned int obtenerCosto();
	/*
	 * POST: Devuelve la Rentabilidad  del cultivo.
	 *
	 */
	unsigned int obtenerRentabilidad();

	/*
	 * POST: Devuelve la cantidad de agua que requiere el cultivo en un turno.
	 */
	unsigned int obtenerConsumoDeAgua();

};

#endif
