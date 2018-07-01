#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino, unsigned int peso) {
	if (peso >= 0 && destino != NULL) {
		this->peso = peso;
		this->destino = destino;
	}
}
Arista::Arista(unsigned int peso) {
	if (peso >= 0) {
		this->peso = peso;
		this->destino = NULL;
	}
}
Vertice* Arista::obtenerDestino() {
	return this->destino;
}
unsigned int Arista::obtenerPeso() {
	return this->peso;
}
Arista::~Arista() {

}
