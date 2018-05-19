#include <iostream>

#include "Terreno.h"

using namespace std;

Terreno::Terreno() {
	this->tamanioFilas = 0;
	this->tamanioColumnas = 0;
}

Terreno::Terreno(unsigned int filas, unsigned int columnas) {
	if ((filas < TERRENO_MIN_FILAS) || (columnas < TERRENO_MIN_COLUMNAS))
		throw std::string(
				"El terreno como minimo debe ser de "
						+ texto.intToString(TERRENO_MIN_FILAS) + " filas por "
						+ texto.intToString(TERRENO_MIN_COLUMNAS)
						+ " columnas.");
	unsigned int tamanioTotal = filas * columnas;
	for (unsigned int i = 0; i < tamanioTotal; i++) {
		Parcela* nuevaParcela = new Parcela();
		this->parcelas->agregar(nuevaParcela);
	}
	this->tamanioFilas = filas;
	this->tamanioColumnas = columnas;
}

unsigned int Terreno::obtenerFilas() {
	return this->tamanioFilas;
}
unsigned int Terreno::obtenerColumnas() {
	return this->tamanioColumnas;
}

Parcela* Terreno::obtenerParcela(unsigned int fila, unsigned int columna) {
	if (fila > this->tamanioFilas || columna > this->tamanioColumnas)
		throw string(
				"Fila debe ser menor o igual a " + texto.intToString(fila)
						+ " y Columna debe ser menor o igual a "
						+ texto.intToString(columna));
	unsigned int indice = fila * this->tamanioColumnas + columna;
	return this->parcelas->obtener(indice);
}
