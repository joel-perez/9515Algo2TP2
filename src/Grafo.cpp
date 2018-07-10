#include "Grafo.h"
#include "Constantes.h"
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
		encontrado = (texto.mayusculas(
				this->vertices->obtenerCursor()->obtenerNombre())
				== texto.mayusculas(nombre));
		if (encontrado) {
			vertice = vertices->obtenerCursor();
		}
	}
	return vertice;
}

void Grafo::insertarArista(string nombreOrigen, string nombreDestino,
		unsigned int peso, unsigned int precio, string cultivo) {
	Vertice* origen = this->existeNodo(nombreOrigen);
	Vertice* destino = this->existeNodo(nombreDestino);

	if (origen != NULL && destino != NULL) {
		Arista* nuevaArista = new Arista(destino, peso, cultivo);
		origen->agregarArista(nuevaArista);
		destino->ingresarDatosEnvio(precio, cultivo);
	}
}

void Grafo::eliminarNodo(string nombre) {
	Vertice* eliminar = this->existeNodo(nombre);
	if (eliminar != NULL) {
		delete eliminar;
	}
}
void Grafo::mostrarCultivoyDestinos() {
	this->vertices->iniciarCursor();
	while (this->vertices->avanzarCursor()) {
		Vertice* actual = this->vertices->obtenerCursor();
		cout << "Destino: " << actual->obtenerNombre()
				<< " || Cultivos Aceptados: ";
		actual->mostrarPosiblesEnvios();
		cout << endl;
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
unsigned int* Grafo::inicializarVector(Vertice* origen,string nombreCultivo) {
	unsigned int* costos = new unsigned int[this->obtenerTam()];
	for (unsigned int i = 0; i < this->obtenerTam(); i++) {
		costos[i] = VALOR_GRANDE;
	}
	origen->obtenerAdyacentes()->iniciarCursor();
	while (origen->obtenerAdyacentes()->avanzarCursor()) {
		Arista* analizada = origen->obtenerAdyacentes()->obtenerCursor();
		if (analizada->obtenerCultivo() == texto.mayusculas(nombreCultivo)) {
			unsigned int costo = analizada->obtenerPeso();
			costos[analizada->obtenerDestino()->obtenerIndice()] = costo;
		}
	}
	costos[origen->obtenerIndice()] = 0;
	return costos;
}
ColaPrioridad<Vertice*>* Grafo::inicializarCola(Vertice* origen,
		unsigned int* costos) {
	ColaPrioridad<Vertice*>* cola = new ColaPrioridad<Vertice*>();

	this->vertices->iniciarCursor();
	while (this->vertices->avanzarCursor()) {
		Vertice* actual = this->vertices->obtenerCursor();
		if (actual->obtenerNombre() != origen->obtenerNombre()) {
			cola->acolar(actual, costos[actual->obtenerIndice()]);
		}
	}
	return cola;
}

unsigned int Grafo::buscarElCaminoMinimo(Vertice* origen, Vertice* destino,
		string nombreCultivo) {
	unsigned int resultado = -1;
	unsigned int* costos = this->inicializarVector(origen,nombreCultivo);
	ColaPrioridad<Vertice*>* cola = this->inicializarCola(origen, costos);

	while (!cola->estaVacia()) {
		Vertice* actual = cola->desacolar();
		actual->obtenerAdyacentes()->iniciarCursor();
		while (actual->obtenerAdyacentes()->avanzarCursor()) {
			Arista* analizada = actual->obtenerAdyacentes()->obtenerCursor();
			if (analizada->obtenerCultivo() == texto.mayusculas(nombreCultivo)) {
				unsigned int temporal = costos[actual->obtenerIndice()]
						+ analizada->obtenerPeso();
				Vertice* actualiza = analizada->obtenerDestino();
				if (costos[analizada->obtenerDestino()->obtenerIndice()]
						> temporal) {
					costos[analizada->obtenerDestino()->obtenerIndice()] =
							temporal;
					cola->actualizarValor(actualiza, temporal);
				}
			}
		}
	}
	resultado = costos[destino->obtenerIndice()];

	delete[] costos;
	delete cola;
	return resultado;
}

unsigned int Grafo::costoDeEnvio(Vertice* destino, string nombreCultivo) {
	unsigned int costoPrecioDelCultivo = destino->obtenerCostoDelCultivo(
			nombreCultivo);
	unsigned int kilometros = this->buscarElCaminoMinimo(
			this->existeNodo("ALMACEN"), destino, nombreCultivo);
	if(kilometros == VALOR_GRANDE){
		cout<<"No se encontro camino hacia el destino seleccionado."<<endl;
		return 0;
	}
	cout << "Costo: " << costoPrecioDelCultivo * kilometros << endl;
	return (costoPrecioDelCultivo * kilometros);
}

Grafo::~Grafo() {
	this->vertices->iniciarCursor();
	while (vertices->avanzarCursor()) {
		delete this->vertices->obtenerCursor();
	}
	delete vertices;
}

