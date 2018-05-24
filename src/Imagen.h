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
	BMP cultivoVacio;
	BMP cultivoSeco;
	BMP cultivoRecienSembrado;
	BMP cultivoPodrido;

	Archivo archivo;

	/*
	 * PRE
	 * POST adecua las medidas del la imagen final.
	 */
	void determinarMedidaDeLaImagen(unsigned int columnas, unsigned int filas);

	/*
	 *POST: pega en la imagen los cultivos segun su estado
	 */
	void pegarEstadoDelTerreno(Terreno* terreno, unsigned int columnas,
			unsigned int filas);

	/*
	 *POST: convierte un numero a un string
	 */
	std::string castearNumeroComoString(unsigned int numero);
	/*
	 *POST: elige la imagen del cultivo segun el nombre del mismo. Si no esta se coloca una imagen generica.
	 */
	void obtenerCultivo(std::string nombreCultivo);
	/*
	 *POST: pega la imagen de fondo del terreno
	 */
	void pegarFondo(unsigned int columnas, unsigned int filas);

public:
	/*
	 * PRE:
	 * POST: .
	 */
	Imagen();

	/*
	 * POST: Muestra los terrenos del jugador indicado en una o varias imagenes BMP.
	 */
	void mostrarTerrenos(Jugador* jugador, unsigned int columnas,
			unsigned int filas, unsigned int turno);

	/*
	 * PRE
	 * POST imagen del estado del terreno en cada turno creado.
	 */
	void obtenerImagenDelTerreno(Terreno* terreno, Jugador* jugador,
			unsigned int columnas, unsigned int filas, unsigned int turno,
			int numeroTerreno);

	/*
	 * POST: Libera los recursos utilizados.
	 */
	~Imagen();
};

#endif
