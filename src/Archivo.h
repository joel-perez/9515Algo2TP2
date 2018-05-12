#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>
#include <iostream>
#include <sstream>

#ifdef linux
#define const char SEPARADOR_DIRECTORIO = SEPARADOR_DIRECTORIO_LINUX;
#elif _WIN32
#define const char SEPARADOR_DIRECTORIO = SEPARADOR_DIRECTORIO_WINDOWS;
#endif

class Archivo {
private:

public:
	/*
	 * PRE:
	 * POST:
	 */
	Archivo();

	/*
	 * Crea el directorio especificado.
	 * Pre: El parametro nombreDirectorio debe ser un nombre de directorio valido.
	 * Post: Crea el directorio.
	 */
	void crearDirectorio(std::string nombreDirectorio);

	/*
	 * PRE:
	 * POST:
	 */
	char obtenerSeparadorDirectorio();

	/*
	 * PRE:
	 * POST: Devuelve la ruta desde donde se esta ejecutando esta aplicacion.
	 */
	std::string obtenerRutaEjecutable();
};

#endif
