#ifndef VERTICE_H_
#define VERTICE_H_

#ifndef NULL
#define NULL 0
#endif

class Vertice {

private:
	std::string dato;
	Vertice* siguiente;

public:

	/*
	 * post: el Nodo resulta inicializado con el dato dado
	 *       y sin un Nodo siguiente.
	 */
	Vertice(std::string dato) {
		this->dato = dato;
		this->siguiente = NULL;
	}

	/*
	 * post: devuelve el valor del dato.
	 */
	std::string obtenerDato() {
		return this->dato;
	}

	/*
	 * post: cambia el valor del dato.
	 */
	void cambiarDato(std::string nuevoDato) {
		this->dato = nuevoDato;
	}

	/*
	 * post: devuelve el siguiente Nodo.
	 */
	Vertice* obtenerSiguiente() {
		return this->siguiente;
	}

	/*
	 * post: cambia el siguiente Nodo por nuevoSiguiente.
	 */
	void cambiarSiguiente(Vertice* nuevoSiguiente) {
		this->siguiente = nuevoSiguiente;
	}
};

#endif
