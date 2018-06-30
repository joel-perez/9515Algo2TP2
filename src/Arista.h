#ifndef ARISTA_H
#define ARISTA_H_

#include <iostream>
#include "Vertice.h"

class Vertice;

class Arista{
private:
	unsigned int peso;
	Vertice* destino;

public:
	/*
	 *
	 *
	 */
	Arista(unsigned int peso);
	/*
	 *
	 *
	 */
	Arista(Vertice* destino, unsigned int peso);
	/*
	 *
	 *
	 */
	unsigned int obtenerPeso();
	/*
	 *
	 *
	 */
	Vertice* obtenerDestino();
	/*
	 *
	 *
	 */
	~Arista();
};



#endif /* ARISTA_H_ */
