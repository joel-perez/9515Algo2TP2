#include <iostream>
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

string Archivo::obtenerRutaEjecutable() {
#ifdef linux
	char result[PATH_MAX];
	ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
	return std::string(result, (count > 0) ? count : 0);
#elif _WIN32
	char result[ MAX_PATH];
	return std::string(result, GetModuleFileName( NULL, result, MAX_PATH));
#endif
}
