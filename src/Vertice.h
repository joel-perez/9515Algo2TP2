#ifndef VERTICE_H_
#define VERTICE_H_
#include <iostream>
#include <string>
#include "Lista.h"
#include "Envio.h"
#include "Arista.h"
#include "Texto.h"

class Vertice {
private:
	std::string nombre;
	Lista<Arista*>* adyacentes;
	unsigned int indice;
	Lista<Envio*>* envios;
	Texto texto;

public:
	/*
	 * pre: Indice debe ser mayor que cero y el nombre no debe estar vacio
	 * post: Vertice listo para utilizar con un nombre y un indice dado. Si no cumple las precondiciones
	 * no hace nada.
	 */
	Vertice(std::string nombre, unsigned int indice);
	/*
	 * post: devuelve el nombre del vertice
	 */
	std::string obtenerNombre();
	/*
	 * post: devuelve la lista de adyacentes
	 */
	Lista<Arista*>* obtenerAdyacentes();
	/*
	 *post: devuelve el indice
	 */
	unsigned int obtenerIndice();
	/*
	 *pre: La arista no debe ser nula.
	 *post: Agrega una arista a la lista de adyacentes
	 */
	void agregarArista(Arista* nuevaArista);
	/*
	 *
	 */
	void ingresarDatosEnvio(unsigned int precio, std::string nombre);
	/*
	 *
	 */
	void mostrarPosiblesEnvios();
	bool aceptaCultivo(std::string analizado);
	unsigned int obtenerCostoDelCultivo(std::string nombre);
	/*
	 * post: libera los recursos utilizados en vertice.
	 */
	~Vertice();
};

#endif /* VERTICE_H_ */
