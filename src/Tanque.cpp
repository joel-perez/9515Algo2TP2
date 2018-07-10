#include<ctime>
#include <cstdlib>
#include <iostream>
#include "Tanque.h"
#include "Constantes.h"

using namespace std;

Tanque::Tanque() {
	this->capacidadMaxima = 10;
	this->aguaDisponible = 10;
}
Tanque::Tanque(unsigned int alto, unsigned int ancho,
		unsigned int multiplicador) {
	this->capacidadMaxima = alto * ancho * multiplicador;
	this->aguaDisponible = 0;
	srand(time(NULL));
}
unsigned int Tanque::obtenerCapacidadMaxima() {
	return this->capacidadMaxima;
}

unsigned int Tanque::obtenerAguaDisponible() {
	return this->aguaDisponible;
}
void Tanque::aumentarCapacidad() {
	int capacidadAnterior = this->obtenerCapacidadMaxima();
	this->capacidadMaxima += capacidadAnterior;
}
void Tanque::usarAguaDisponible(unsigned int cantidadUsada) {
	if (this->obtenerAguaDisponible() >= cantidadUsada) {
		this->aguaDisponible -= cantidadUsada;
	}
}
void Tanque::asignarAguaDisponible() {
	unsigned int aguaDelTurno = this->tirarDado() * POTENCIADOR_AGUA;
	this->cambiarAguaDisponible(aguaDelTurno);
}
void Tanque::cambiarAguaDisponible(unsigned int aguaDelTurno) {
	this->aguaDisponible += aguaDelTurno;

	if (this->superoCapacidadMaxima()) {
		this->aguaDisponible = this->obtenerCapacidadMaxima();
	}
}

unsigned int Tanque::tirarDado() {
	unsigned int potenciador = (rand() % CARAS_DADO) + 1;
	cout<<""<<endl;
	cout << ">Potenciado de aguar: "<< potenciador <<endl; //todo: pasar esto a otro lado, al juego cpp
	return potenciador;
}
bool Tanque::superoCapacidadMaxima() {
	return (this->aguaDisponible >= this->capacidadMaxima);
}
