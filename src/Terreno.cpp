#include <iostream>

#include "Terreno.h"

using namespace std;

Terreno::Terreno() {
	this->parcelas = NULL;
	this->tamanioColumnas = 0;
	this->tamanioFilas = 0;
}

Terreno::Terreno(unsigned int filas, unsigned int columnas) {
	if ((filas < TERRENO_MIN_FILAS) || (columnas < TERRENO_MIN_COLUMNAS))
		throw std::string(
				"El terreno como minimo debe ser de "
						+ texto.intToString(TERRENO_MIN_FILAS) + " filas por "
						+ texto.intToString(TERRENO_MIN_COLUMNAS)
						+ " columnas.");
	unsigned int tamanioTotal = filas * columnas;
	this->parcelas = new Lista<Parcela*>;
	for (unsigned int i = 0; i < tamanioTotal; i++) {
		Parcela* nuevaParcela = new Parcela();
		this->parcelas->agregar(nuevaParcela);
	}
	this->tamanioColumnas = columnas;
	this->tamanioFilas = filas;
}

unsigned int Terreno::obtenerColumnas() {
	return this->tamanioColumnas;
}

unsigned int Terreno::obtenerFilas() {
	return this->tamanioFilas;
}

Parcela* Terreno::obtenerParcela(unsigned int fila, unsigned int columna) {
	if (fila > this->tamanioFilas || columna > this->tamanioColumnas)
		throw string(
				"Fila debe ser menor o igual a " + texto.intToString(fila)
						+ " y Columna debe ser menor o igual a "
						+ texto.intToString(columna));
	unsigned int indice = (fila - 1) * this->tamanioColumnas + columna;
	return this->parcelas->obtener(indice);
}

Lista<Parcela*>* Terreno::seleccionarTerreno(
		Lista<Terreno*>* terrenosJugadorActual) {
	return 0;
}
Lista<Parcela*>* Terreno::obtenerParcelas() {
	return this->parcelas;
}
Terreno::~Terreno() {
	std::cout << "Terreno::~Terreno()" << std::endl;
	this->parcelas->iniciarCursor();
	while (parcelas->avanzarCursor()) {
		delete this->parcelas->obtenerCursor();
	}
	delete parcelas;
}
