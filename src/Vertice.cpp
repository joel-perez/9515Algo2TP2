#include "Vertice.h"

using namespace std;

Vertice::Vertice(string nombre, unsigned int indice) {
	if (nombre != "" && indice >= 0) {
		this->nombre = nombre;
		this->adyacentes = new Lista<Arista*>();
		this->indice = indice;
		this->envios = NULL;
	}
}
Lista<Arista*>* Vertice::obtenerAdyacentes() {
	return this->adyacentes;
}

string Vertice::obtenerNombre() {
	return this->nombre;
}
unsigned int Vertice::obtenerIndice() {
	return this->indice;
}
void Vertice::agregarArista(Arista* nuevaArista) {
	if (nuevaArista != NULL) {
		this->adyacentes->agregar(nuevaArista);
	}
}
void Vertice::ingresarDatosEnvio(unsigned int precio, std::string nombre) {
	if (precio >= 0 && nombre != "") {
		if (this->envios == NULL) {
			this->envios = new Lista<Envio*>();
		}
		Envio* datos = new Envio(nombre, precio);
		this->envios->agregar(datos);
	}
}
void Vertice::mostrarPosiblesEnvios() {
	if (this->envios != NULL) {
		this->envios->iniciarCursor();
		while (this->envios->avanzarCursor()) {
			Envio* actual = this->envios->obtenerCursor();
			cout << actual->obtenerNombreCultivo()<", ";
		}
	}
}
bool Vertice::aceptaCultivo(string analizado) {
	bool encontrado = false;
	this->envios->iniciarCursor();
	while (this->envios->avanzarCursor() && !encontrado) {
		encontrado = (this->envios->obtenerCursor()->obtenerNombreCultivo()
				== analizado);
	}
	return encontrado;
}
unsigned int Vertice::obtenerCostoDelCultivo(string nombre) {
	bool encontrado = false;
	unsigned int costo = 0;
	this->envios->iniciarCursor();
	while (this->envios->avanzarCursor() && !encontrado) {
		encontrado = (this->envios->obtenerCursor()->obtenerNombreCultivo()
				== nombre);
		if (encontrado) {
			costo = this->envios->obtenerCursor()->obtenerPrecioEnvio();
		}
	}
	return costo;
}
Vertice::~Vertice() {
	if(this->envios != NULL){
		this->envios->iniciarCursor();
		while(this->envios->avanzarCursor()){
			delete this->envios->obtenerCursor();
		}
		delete envios;
	}
	this->adyacentes->iniciarCursor();
	while (this->adyacentes->avanzarCursor()) {
		delete this->adyacentes->obtenerCursor();
	}
	delete adyacentes;
}

