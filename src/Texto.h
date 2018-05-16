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
	Lista<Cultivo*>* leerCultivo();
};

#endif

