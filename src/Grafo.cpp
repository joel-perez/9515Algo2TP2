#include "Grafo.h"
using namespace std;

Grafo::Grafo() {
	this->vertices = new Lista<Vertice*>();
	this->tam = 0;
}
Lista<Vertice*>* Grafo::obtenerVertices() {
	return this->vertices;
}
unsigned int Grafo::obtenerTam() {
	return this->tam;
}

void Grafo::insertarNodo(string nombreVertice) {
	if (this->existeNodo(nombreVertice) == NULL) {
		Vertice* nuevoVertice = new Vertice(nombreVertice, this->obtenerTam());
		this->vertices->agregar(nuevoVertice);
		this->tam++;
	}
}

Vertice* Grafo::existeNodo(string nombre) {
	Vertice* vertice = NULL;
	bool encontrado = false;
	this->vertices->iniciarCursor();
	while (this->vertices->avanzarCursor() && !encontrado) {
		encontrado =
				(this->vertices->obtenerCursor()->obtenerNombre() == nombre);
		if (encontrado) {
			vertice = vertices->obtenerCursor();
		}
	}
	return vertice;
}

void Grafo::insertarArista(string nombreOrigen, string nombreDestino,
		unsigned int peso) {
	Vertice* origen = this->existeNodo(nombreOrigen);
	Vertice* destino = this->existeNodo(nombreDestino);

	if (origen != NULL && destino != NULL) {
		Arista* nuevaArista = new Arista(destino, peso);
		origen->agregarArista(nuevaArista);
	}
}

void Grafo::eliminarNodo(string nombre) {
	Vertice* eliminar = this->existeNodo(nombre);
	if (eliminar != NULL) {
		delete eliminar;
	}
}

void Grafo::mostrarListaAdyacencia() {
	this->vertices->iniciarCursor();
	while (this->vertices->avanzarCursor()) {
		Vertice* verticeActual = this->vertices->obtenerCursor();
		cout << verticeActual->obtenerNombre() << " -> ";
		verticeActual->obtenerAdyacentes()->iniciarCursor();
		while (verticeActual->obtenerAdyacentes()->avanzarCursor()) {
			Arista* aristaActual =
					verticeActual->obtenerAdyacentes()->obtenerCursor();
			cout << "(" << aristaActual->obtenerPeso() << ") "
					<< aristaActual->obtenerDestino()->obtenerNombre()
					<< " -> ";
		}
		cout << endl;
	}
}

unsigned int Grafo::buscarElCaminoMinimo(Vertice* origen, Vertice* destino) {
	if (origen != NULL && destino != NULL) {
		ColaPrioridad<Vertice*> cola;
		unsigned int costos[this->obtenerTam()];

		for (unsigned int i = 0; i < this->obtenerTam(); i++) {
			costos[i] = 9999999;
		}
		costos[origen->obtenerIndice()] = 0;

		// actualizar valores en el arreglo
		origen->obtenerAdyacentes()->iniciarCursor();
		while (origen->obtenerAdyacentes()->avanzarCursor()) {
			Arista* analizada = origen->obtenerAdyacentes()->obtenerCursor();
			unsigned int costo = analizada->obtenerPeso();
			costos[analizada->obtenerDestino()->obtenerIndice()] = costo;
		}

		//Colocar vectores en la cola
		this->vertices->iniciarCursor();
		while (this->vertices->avanzarCursor()) {
			Vertice* actual = this->vertices->obtenerCursor();
			if (actual->obtenerNombre() != origen->obtenerNombre()) {
				cola.acolar(actual, costos[actual->obtenerIndice()]);
			}
		}

		while (!cola.estaVacia()) {
			Vertice* actual = cola.desacolar();
			actual->obtenerAdyacentes()->iniciarCursor();
			while (actual->obtenerAdyacentes()->avanzarCursor()) {
				Arista* analizada =
						actual->obtenerAdyacentes()->obtenerCursor();
				unsigned int temporal = costos[actual->obtenerIndice()]
						+ analizada->obtenerPeso();
				Vertice* actualiza = analizada->obtenerDestino();
				if (costos[analizada->obtenerDestino()->obtenerIndice()]
						> temporal) {
					costos[analizada->obtenerDestino()->obtenerIndice()] =
							temporal;
					cola.actualizarValor(actualiza, temporal);
				}
			}
		}

		cout << "VALOR FINAL: " << costos[destino->obtenerIndice()] << endl;
		return costos[destino->obtenerIndice()];
	}
	return -1;
}

Grafo::~Grafo() {
	this->vertices->iniciarCursor();
	while (vertices->avanzarCursor()) {
		delete this->vertices->obtenerCursor();
	}
	delete vertices;
}

