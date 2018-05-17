#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Cultivo.h"
#include "Destino.h"
#include "Constantes.h"

#ifdef linux
#include <string>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
const char SEPARADOR_DIRECTORIO = SEPARADOR_DIRECTORIO_LINUX;
#elif _WIN32
#include <string>
#include <windows.h>
const char SEPARADOR_DIRECTORIO = SEPARADOR_DIRECTORIO_WINDOWS;
#endif

/*
 * Administra el manejo de archivos, directorios, rutas, etc.
 * Dado que depende de rutinas internas del Sistema Operativo
 * en el cual se ejecuta la aplicacion, se acoto las posibilidades
 * a sistemas Linux y Windows.
 */
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
	 * PRE:  El parametro nombreDirectorio debe ser un nombre de directorio valido.
	 * POST: Crea el directorio.
	 */
	void crearDirectorio(std::string nombreDirectorio);

	/*
	 * PRE:
	 * POST: Devuelve el caracter que representa la separacion de directorios
	 *       en una ruta dada para el sistema operativo actual.
	 */
	char obtenerSeparadorDirectorio();

	/*
	 * PRE:
	 * POST: Devuelve la ruta desde donde se esta ejecutando esta aplicacion.
	 */
	std::string obtenerRutaEjecucion();

	/*
	 * PRE:
	 * POST: Devuelve una ruta a un archivo compuesta por directorioPrimero,
	 *       al cual se le concatena el separador de directorios de ser necesario,
	 *       y luego se le concatena el segundo directorio.
	 */
	std::string concatenarRutas(std::string directorioPrimero,
			std::string directorioSegundo);

	/*
	 * PRE:
	 * POST: Devuelve la ruta completa donde se almacenan los archivos de Recursos (Imagenes)
	 */
	std::string obtenerRutaRecursos();

	/*
	 * PRE:
	 * POST: Devuelve la ruta completa donde se almacenan las Capturas de Pantalla de cada turno.
	 */
	std::string obtenerRutaCapturasPantalla();

	/* PRE: La obteneRuta del archito txt debe de exitir .
	 * POST:Obtien la determinada ruta;
	 */
	std::string pedirRuta(std::string obteneRuta);

	/* PRE:~
	 * POST:Devuelve una nueva Lista con todos los Cultivos.
	 */
	Lista<Cultivo*>* leerCultivo();

	/* PRE:~
	 * POST:Devuelve una nueva Lista con todos los Destinos.
	 */
	Lista<Destino*>* leerDestino();
};

#endif
