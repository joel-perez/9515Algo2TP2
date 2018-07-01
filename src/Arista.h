#ifndef ARISTA_H
#define ARISTA_H_

#include <iostream>

class Vertice;

class Arista{
private:
	unsigned int peso;
	Vertice* destino;

public:
	/*
	 * post: Arista con un peso determinado, sin un destino fijo
	 */
	Arista(unsigned int peso);
	/*
	 *post: Arista con peso determinado y con un destino fijado.
	 */
	Arista(Vertice* destino, unsigned int peso);
	/*
	 *post: devuelve el valor peso de la arista.
	 */
	unsigned int obtenerPeso();
	/*
	 *post: devuelve el destino asociado a la arista
	 */
	Vertice* obtenerDestino();
	/*
	 *post: -
	 */
	~Arista();
};


#endif /* ARISTA_H_ */
