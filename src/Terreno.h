#ifndef TERRENO_H_
#define TERRENO_H_

#include "Lista.h"
#include "Parcela.h"
#include "Dificultad.h"
#include "Constantes.h"
#include "Texto.h"

class Terreno {
private:
	Texto texto;
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
	/*
	 * PRE:
	 * POST: delvuelve el alto del terreno,
	 */
	unsigned int obtenerFilas();
	/*
	 * PRE:
	 * POST: devuelve el ancho del terreno.
	 */
	unsigned int obtenerColumnas();
	/*
	 * PRE: fila y columna deb de estar en el rango permitido.
	 * POST: devuelve la parcela dada una fila y una columna.
	 */
	Parcela* obtenerParcela(unsigned int fila, unsigned int columna);
};

#endif
