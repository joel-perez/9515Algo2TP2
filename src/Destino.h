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
	Destino();

	//TODO: Implementar los metodos necesarios...
};

#endif
