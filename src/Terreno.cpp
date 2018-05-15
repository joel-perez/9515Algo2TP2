#include "Terreno.h"

Terreno::Terreno() {
	this->parcelas= new Lista<Lista<Parcela*>*>;
	this->tamanioFilas=0;
	this->tamanioColumnas=0;

}

void Terreno::crearTerreno(unsigned int filas, unsigned int columnas){

	if ((filas < TERRENO_MIN_FILA_COLUMNA) || (columnas < TERRENO_MIN_FILA_COLUMNA))

		throw std::string ("Error filas/columnas");


	for(unsigned int i=0; i < columnas; i++){

		Lista<Parcela*>* nuevaColumna = new Lista<Parcela*>;

		for(unsigned int j=0; j<filas; j++){

			Parcela* nuevaParcela = new Parcela;
			nuevaColumna->agregar(nuevaParcela);
		}
		this->parcelas->agregar(nuevaColumna);
	}



	this->tamanioFilas = filas;
	this->tamanioColumnas = columnas;
}



//TODO: Implementar los metodos que sean necesarios...
