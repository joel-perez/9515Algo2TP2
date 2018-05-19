#ifndef COSECHA_H_
#define COSECHA_H_
#include "Lista.h"
#include "Cultivo.h"

class Cosecha {
private:
	Lista<Cultivo*>* cosechas;


public:
	/*
	 * PRE:
	 * POST:cosecha lista para usar.
	 */
	Cosecha();
	/*
	 * PRE:
	 * POST:Devuelve los las cosechas del jugadorActual.
	 */
	Lista<Cultivo*>* obtenerCosechas();
};



#endif
