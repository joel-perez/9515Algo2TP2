#ifndef COLACONPRIORIDAD_H_
#define COLACONPRIORIDAD_H_
#include <string>
#include "Nodo.h"

template<class T> class ColaPrioridad {
private:
	Nodo<T>* frente;
	Nodo<T>* fondo;
public:
	/*
	 * post: instancia de Cola vacía y lista para ser usada.
	 */
	ColaPrioridad();
	/*
	 * pre: el nodo debe existir y el valor de la prioridad debe ser mayor o igual a cero
	 * post: Actualiza el valor de la prioridad del nodo y lo ordena en la cola. Si el valor de la prioridad
	 * no es la indicada no hace nada.
	 */
	//TODO: buscar forma para que sea general la prioridad (Es necesario que sea generico?)
	void actualizarValor(T vertice, unsigned int prioridad);
	/*
	 * post: devuelve true si la cola esta vacia y false si no.
	 */
	bool estaVacia();
	/*
	 * post: agrega elemento en el fondo de la Cola.
	 */
	void acolar(T elemento, unsigned int prioridad);
	/*
	 * pre : la Cola no está vacía.
	 * post: remueve el frente de la Cola y lo devuelve.
	 */
	T desacolar();
	/*
	 * pre : la Cola no está vacía.
	 * post: devuelve el frente de la Cola.
	 */
	T obtenerFrente();
	/*
	 * post: Ordena la cola segun la prioridad de cada nodo
	 */
	void ordenar();
	/*
	 * post: remueve todos los elementos y libera los recursos utilizados.
	 */
	~ColaPrioridad();
};
template<class T>
ColaPrioridad<T>::ColaPrioridad() {
	this->frente = NULL;
	this->fondo = NULL;
}
template<class T>
bool ColaPrioridad<T>::estaVacia() {
	return (this->frente == NULL);
}
template<class T>
void ColaPrioridad<T>::acolar(T elemento, unsigned int prioridad) {
	if (prioridad >= 0) {
		Nodo<T>* nuevoFondo = new Nodo<T>(elemento);
		nuevoFondo->cambiarPrioridad(prioridad);
		if (this->estaVacia()) {
			this->frente = nuevoFondo;
			this->fondo = nuevoFondo;
		} else if (this->frente->obtenerPrioridad() > prioridad) {
			Nodo<T>* nodoSiguiente = this->frente;
			this->frente = nuevoFondo;
			nuevoFondo->cambiarSiguiente(nodoSiguiente);
		} else {
			Nodo<T>* aCambiar = this->frente;
			while (aCambiar->obtenerSiguiente() != NULL
					&& aCambiar->obtenerSiguiente()->obtenerPrioridad()
							< prioridad) {
				aCambiar = aCambiar->obtenerSiguiente();
			}
			Nodo<T>* siguiente = aCambiar->obtenerSiguiente();
			aCambiar->cambiarSiguiente(nuevoFondo);
			nuevoFondo->cambiarSiguiente(siguiente);
			if (siguiente == NULL) {
				this->fondo = nuevoFondo;
			}
		}
	}
}
template<class T>
void ColaPrioridad<T>::actualizarValor(T vertice, unsigned int valor) {
	Nodo<T>* nodoBuscado = this->frente;
	bool encontrado = (this->frente->obtenerDato() == vertice);
	while (nodoBuscado != NULL && !encontrado) {
		nodoBuscado = nodoBuscado->obtenerSiguiente();
		encontrado = (nodoBuscado->obtenerDato() == vertice);
	}
	nodoBuscado->cambiarPrioridad(valor);
	this->ordenar();
}
template<class T>
void ColaPrioridad<T>::ordenar() {
	Nodo<T>* anterior = this->frente;
	unsigned int prioridadAnterior;
	T datoAnterior;

	while (anterior->obtenerSiguiente() != NULL) {
		Nodo<T>* siguiente = anterior->obtenerSiguiente();
		while (siguiente != NULL) {
			if (anterior->obtenerPrioridad() > siguiente->obtenerPrioridad()) {
				prioridadAnterior = anterior->obtenerPrioridad();
				datoAnterior = anterior->obtenerDato();

				anterior->cambiarPrioridad(siguiente->obtenerPrioridad());
				anterior->cambiarDato(siguiente->obtenerDato());

				siguiente->cambiarPrioridad(prioridadAnterior);
				siguiente->cambiarDato(datoAnterior);
			}
			siguiente = siguiente->obtenerSiguiente();
		}
		anterior = anterior->obtenerSiguiente();
	}
}
template<class T>
T ColaPrioridad<T>::desacolar() {
	if (this->estaVacia()) {
		throw std::string("No se puede desacolar, la cola está vacía.");
	}
	Nodo<T>* frenteAnterior = this->frente;
	this->frente = frenteAnterior->obtenerSiguiente();
	if (this->frente == NULL) {
		this->fondo = NULL;
	}
	T elemento = frenteAnterior->obtenerDato();
	delete frenteAnterior;
	return elemento;
}
template<class T>
T ColaPrioridad<T>::obtenerFrente() {
	if (this->estaVacia()) {
		throw std::string("No se puede obtener el frente, la cola está vacía.");
	}
	T elemento = this->frente->obtenerDato();
	return elemento;
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad() {
	while (!this->estaVacia()) {
		this->desacolar();
	}
}
#endif /* COLA_H_ */
