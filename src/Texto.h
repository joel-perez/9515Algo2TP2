#ifndef TEXTO_H_
#define TEXTO_H_

#include <string>
#include "Lista.h"
#include "Cultivo.h"

class Texto {
public:
	/*
	 *
	 *
	 */
	std::string pedirRuta();

	/*
	 *
	 *
	 */
	void leerCultivo(Lista<Cultivo*>* cultivos);
};

#endif

