#ifndef TERRENO_H_
#define TERRENO_H_

#include "Lista.h"
#include "Parcela.h"
#include "Dificultad.h"
#include "Constantes.h"

class Terreno {
private:
	//Parcela* parcelas[1][1];
	Lista<Parcela*>* parcelas;
	unsigned int tamanioFilas;
	unsigned int tamanioColumnas;

public:
	/*
	 * PRE:
	 * POST: Crea un Terreno con 0 tamanioFilas y 0 tamanioColumnas.
	 */
	Terreno();

	/*
	 * PRE: filas y columnas estas en el intervalos de [TERRENO_MIN_FILA_COLUMNA,
	 * TERRENO_MAX_FILA_COLUMNA].
	 * POST: Terreno de 'filas'x'columnas' con 'filas'*'columas' Parcelas
	 * 		 vacias y sin cultivo.
	 */
	Terreno(unsigned int filas, unsigned int columnas);

	unsigned int obtenerFilas();
	unsigned int obtenerColumnas();
	Parcela* obtenerParcela(unsigned int fila, unsigned int columna);
	void inicializarTerreno(unsigned int filas, unsigned int columnas);
};

#endif
