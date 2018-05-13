#include <iostream>
#include <string>
#include <cstddef>

#include "Archivo.h"

using namespace std;

Archivo::Archivo() {

}

void crearDirectorio(std::string nombreDirectorio) {
#ifdef linux
	mkdir(nombreDirectorio.c_str(), S_IRWXU);
#elif _WIN32
	if (CreateDirectory(nombreDirectorio.c_str(), NULL)) {
		//Accion a realizar si el directorio se creo exitosamente.
	} else if (ERROR_ALREADY_EXISTS == GetLastError()) {
		//Accion a realizar si el directorio ya existia.
	} else {
		//Accion a realizar si ocurre un error.
	}
#endif
}

char Archivo::obtenerSeparadorDirectorio() {
	return SEPARADOR_DIRECTORIO;
}

string Archivo::obtenerRutaEjecucion() {
	string rutaEjecucion = "";
#ifdef linux
	char result[PATH_MAX];
	ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
	rutaEjecucion = string(result, (count > 0) ? count : 0);
#elif _WIN32
	char result[MAX_PATH];
	rutaEjecucion = string(result, GetModuleFileName(NULL, result, MAX_PATH));
#endif
	size_t found = rutaEjecucion.find_last_of(
			this->obtenerSeparadorDirectorio());
	rutaEjecucion = rutaEjecucion.substr(0, found);
	return rutaEjecucion;
}

string Archivo::concatenarRutas(string directorioPrimero,
		string directorioSegundo) {
	string rutaConcatenada = directorioPrimero;
	if (rutaConcatenada.size() > 0
			&& rutaConcatenada[rutaConcatenada.size() - 1]
					!= this->obtenerSeparadorDirectorio())
		rutaConcatenada += this->obtenerSeparadorDirectorio();
	rutaConcatenada += directorioSegundo;
	return rutaConcatenada;
}

string Archivo::obtenerRutaRecursos() {
	return concatenarRutas(obtenerRutaEjecucion(), DIRECTORIO_RECURSOS);
}

string Archivo::obtenerRutaCapturasPantalla() {
	return concatenarRutas(obtenerRutaEjecucion(), DIRECTORIO_CAPTURAS_PANTALLA);
}
