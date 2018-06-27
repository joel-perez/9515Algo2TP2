#ifndef GRAFO_H_
#define GRAFO_H_

#include "Nodo.h"

/*
 * Es un TDA contenedor de un conjunto de datos llamados nodos y de un conjunto
 * de aristas cada una de las cuales se determina mediante un par de nodos.
 */
template<class T> class Grafo {

private:

public:
	/* Genera un grafo vacío.
	 * PRE: ---
	 * POST: grafo generado vacío.
	 */
	Grafo();

	/* Inserta un nodo nuevo, recibido como argumento, en el grafo.
	 * PRE: que el grafo exista  y que el nodo no esté previamente.
	 * POST: el grafo queda modificado por el agregado del nuevo nodo.
	 */
	void InsertarNodo(std::string nombre);

	/* Inserta una arista nueva, recibida como argumento, en el grafo.
	 * PRE: que el grafo exista , que la arista no esté previamente y que existan en el grafo los nodos origen y destino de la arista.
	 * POST: el grafo queda modificado por el agregado de la nueva arista.
	 */
	void InsertarArista(Nodo<T>* origen, Nodo<T>* destino, int peso);

	/* Elimina un nodo, recibido como argumento,  del grafo.
	 * PRE: que el grafo exista  y que el nodo a eliminar esté en él y no tenga aristas incidentes en él.
	 * POST: el grafo queda modificado por la eliminación del nodo.
	 */
	void EliminarNodo(Nodo<T>* nodo);

	/* Elimina una arista, recibida como argumento,  del grafo.
	 * PRE: que el grafo exista  y la arista estén él.
	 * POST: el grafo queda modificado por la eliminación de la arista.
	 */
	void EliminarArista(Nodo<T>* origen, Nodo<T>* destino);

	/* Recibe una arista y retorna un valor logico indicando si la arista existe en el grafo.
	 * PRE: que el grafo exista.
	 * POST: --- 
	 */
	bool ExisteArista(Nodo<T>* origen, Nodo<T>* destino);

	/* Recibe una arista y retorna un valor logico indicando si el nodo existe en el grafo.
	 * PRE: que el grafo exista.
	 * POST: ---
	 */
	bool ExisteNodo(std::string nombre);

	/* Destruye el grafo.
	 * PRE: que el grafo exista.
	 * POST: ---
	 */
	~Grafo();

};

template<class T> Grafo<T>::Grafo() {
	//TODO: Implementar...
}

template<class T> void Grafo<T>::InsertarNodo(std::string nombre) {
	//TODO: Implementar...
}

template<class T> void Grafo<T>::InsertarArista(Nodo<T>* origen,
		Nodo<T>* destino, int peso) {
	//TODO: Implementar...
}

template<class T> void Grafo<T>::EliminarNodo(Nodo<T>* nodo) {
	//TODO: Implementar...
}

template<class T> void Grafo<T>::EliminarArista(Nodo<T>* origen,
		Nodo<T>* destino) {
	//TODO: Implementar...
}

template<class T> bool Grafo<T>::ExisteArista(Nodo<T>* origen,
		Nodo<T>* destino) {
	//TODO: Implementar...
	return false;
}

template<class T> bool Grafo<T>::ExisteNodo(std::string nombre) {
	//TODO: Implementar...
	return false;
}

template<class T> Grafo<T>::~Grafo() {
	//TODO: Implementar...
}

#endif
