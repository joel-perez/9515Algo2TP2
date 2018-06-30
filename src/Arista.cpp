#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* destino,unsigned int peso) {
	this->peso = peso;
	this->destino = destino;
}
Arista::Arista(unsigned int peso) {
	this->peso = peso;
	this->destino=NULL;
}
Vertice* Arista::obtenerDestino(){
	return this->destino;
}
unsigned int Arista::obtenerPeso(){
	return this->peso;
}
Arista::~Arista(){

}
