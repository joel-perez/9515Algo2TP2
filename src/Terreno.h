#ifndef TERRENO_H_
#define TERRENO_H_

#include "Lista.h"
#include "Parcela.h"
#include "Dificultad.h"
#include "Constantes.h"
#include "Texto.h"

class Terreno {
private:
	Lista<Parcela*>* parcelas;
	Texto texto;
	unsigned int tamanioColumnas;
	unsigned int tamanioFilas;
	unsigned int precio;

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
	 * POST: Devuelve la lista de parcelas que componen este terreno.
	 */
	Lista<Parcela*>* obtenerParcelas();

	/*
	 * PRE:
	 * POST: devuelve el ancho del terreno.
	 */
	unsigned int obtenerColumnas();

	/*
	 * PRE: fila y columna deben estar en el rango permitido.
	 * POST: devuelve la parcela dada una fila y una columna.
	 */
	Parcela* obtenerParcela(unsigned int fila, unsigned int columna);

	/*
	 * PRE:Solicita al usuario que ingrese uno de los terrenos disponibles
	 * POST:
	 * y devuelve una referencia a ese terreno, si solo tiene un terreno
	 * devolvera ese terreno.
	 */
	Lista<Parcela*>* seleccionarTerreno(Lista<Terreno*>* terrenosJugadorActual);

	/*
	 * POST: Devuelve el precio de este terreno.
	 */
	unsigned int obtenerPrecio();

	/*
	 * POST: Deja asignado el precio de este terreno en base a la dificultad actual.
	 */
	void asignarPrecio(Dificultad dificultad);

	~Terreno();
};

#endif
