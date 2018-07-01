#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {

private:
	T dato;
	Nodo<T>* siguiente;
	unsigned int prioridad;

public:
	/*
	 * post: el Nodo resulta inicializado con el dato dado
	 *        sin un Nodo siguiente ni prioridad
	 */
	Nodo(T dato) {
		this->dato = dato;
		this->siguiente = NULL;
		this->prioridad = 0;
	}
	Nodo(T dato, unsigned int prioridad) {
		this->dato = dato;
		this->siguiente = NULL;
		this->prioridad = prioridad;
	}
	/*
	 * post: devuelve el valor del dato.
	 */
	T obtenerDato() {
		return this->dato;
	}

	/*
	 * post: cambia el valor del dato.
	 */
	void cambiarDato(T nuevoDato) {
		this->dato = nuevoDato;
	}

	/*
	 * post: devuelve el siguiente Nodo.
	 */
	Nodo<T>* obtenerSiguiente() {
		return this->siguiente;
	}

	/*
	 * post: cambia el siguiente Nodo por nuevoSiguiente.
	 */
	void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {
		this->siguiente = nuevoSiguiente;
	}
	/*
	 * pre: la prioridad nueva deberia ser mayor o igual a cero
	 * post: asigna un nuevo valor a la prioridad.
	 */
	void cambiarPrioridad(unsigned int prioridadNueva) {
		this->prioridad = prioridadNueva;
	}
	/*
	 *pre; devuelve la prioridad del nodo.
	 */
	unsigned int obtenerPrioridad() {
		return this->prioridad;
	}
};

#endif /* NODO_H_ */
