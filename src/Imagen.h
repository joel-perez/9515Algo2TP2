#ifndef IMAGEN_H_
#define IMAGEN_H_

#include "Jugador.h"
#include "Archivo.h"
#include "lib/EasyBMP.h"
#include "lib/EasyBMP_Geometry.h"
#include "lib/EasyBMP_Font.h"

class Imagen {
private:
	BMP fondoTerreno;
	BMP imagenDelTerreno;
	BMP cultivo;
	Archivo archivo;
	RGBApixel color;

	/*
	 * PRE
	 * POST adecua las medidas del cultivo.
	 */
	void rescalarImagenes(unsigned int columnas);

	/*
	 * PRE
	 * POST coloca los fondos del disenio en la imagen final.
	 */
	void pegarFondos();

	/*
	 *
	 */
	void pegarEstadoDelTerreno(Terreno* terreno, unsigned int columnas,
			unsigned int filas);

	/*
	 *
	 */
	void pegarEstadoDeLosDatos();

public:
	/*
	 * PRE:
	 * POST: dimensiones de la imagen final creada.
	 */
	Imagen();

	/*
	 * POST: Muestra los terrenos del jugador indicado en una o varias imagenes BMP.
	 */
	void mostrarTerrenos(Jugador* jugador, unsigned int columnas,
			unsigned int filas);

	/*
	 * PRE
	 * POST imagen del estado del terreno en cada turno creado.
	 */
	void obtenerImagenDelTerreno(Terreno* terreno, Jugador* jugador,
			unsigned int columnas, unsigned int filas);

	/*
	 * POST: Libera los recursos utilizados.
	 */
	~Imagen();
};

#endif
