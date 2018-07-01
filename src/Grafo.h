#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <string>
#include "ColaPrioridad.h"
#include "Lista.h"
#include "Vertice.h"

class Grafo {

private:
	Lista<Vertice*>* vertices;
	unsigned int tam;

public:
	/*
	 * PRE: ---
	 * POST: grafo generado y vacio.
	 */
	Grafo();
	/*
	 *
	 */
	unsigned int obtenerTam();
	/*
	 *
	 */
	Lista<Vertice*>* obtenerVertices();
	/*
	 * PRE: que el grafo exista  y que el nodo no este previamente.
	 * POST: el grafo queda modificado por el agregado del nuevo nodo.
	 */
	void insertarNodo(std::string nombre);

	/*
	 * PRE: que el grafo exista , que la arista no este previamente y que existan en el grafo los
	 * nodos origen y destino de la arista.
	 * POST: el grafo queda modificado por el agregado de la nueva arista.
	 */
	void insertarArista(std::string origen, std::string destino,
			unsigned int peso, unsigned int precio, std::string cultivo);

	/*
	 * PRE: que el grafo exista  y que el nodo a eliminar este en el y no tenga aristas incidentes en el.
	 * POST: el grafo queda modificado por la eliminacion del nodo.
	 */
	void eliminarNodo(std::string nombre);

	/*
	 * PRE: que el grafo exista  y la arista esten el.
	 * POST: el grafo queda modificado por la eliminacion de la arista.
	 */
	void EliminarArista(Vertice* origen, Vertice* destino);

	/*
	 * PRE: que el grafo exista.
	 * POST: ---�
	 */
	bool existeArista(Vertice* origen, Vertice* destino);

	/*
	 * PRE: que el grafo exista.
	 * POST: devuelve el nodo con el nombre que se paso por referencia. Si no existe devuelve NULL
	 */
	Vertice* existeNodo(std::string nombre);
	/*
	 * pre: el origen y destino deben existir en el grafo, no ser null.
	 * post: si no cumple la pre condicion devuelve -1. En caso contrario calcula el minimo valor hasta llegar
	 * al destino
	 */
	unsigned int buscarElCaminoMinimo(Vertice* origen, Vertice* destino);
	/*
	 * post: imprime por pantalla la lista de adyacencia del grafo.
	 */
	void mostrarListaAdyacencia();

	/*
	 * PRE: que el grafo exista.
	 * POST: libera los recursos utilizados por el grafo
	 */
	~Grafo();

};
#endif /* GRAFOS_H_ */

