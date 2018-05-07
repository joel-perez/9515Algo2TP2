#ifndef ALMACEN_H_
#define ALMACEN_H_

#include "Lista.h"
#include "Destino.h"
#include "Cosecha.h"

class Almacen {
private:
	Lista<Cosecha> cosechas;
	Lista<Destino> destinos;

public:
	Almacen();
	Almacen(const Almacen& almacen);

	//TODO: Implementar metodos necesarios...

};

#endif
