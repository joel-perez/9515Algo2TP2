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
	 * POST:
	 */
	Cultivo(std::string nombreCultivo, int costo,  int tiempoDeCrecimiento, int rentabilidad, int tiempoDeRecuperacion, int consumoDeAgua);

	/*
	 *
	 *
	 */
	Cultivo();


};

#endif
