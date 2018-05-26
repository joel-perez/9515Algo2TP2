#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "Archivo.h"

using namespace std;

Archivo::Archivo() {

}

void Archivo::crearDirectorio(std::string nombreDirectorio) {
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

void Archivo::abrirConAplicacionPredeterminada(string nombreArchivo) {
	string lineaDeComandos = "";
#ifdef _WIN32
	lineaDeComandos = (char) 34 + nombreArchivo + (char) 34;
#endif
#ifdef __unix__
	//    play       (requiere: sudo apt install sox)
	//    xdg-open   (requiere: sudo apt install xdg-utils)
	//    gnome-open (requiere: sudo apt install libgnome2-bin)
	lineaDeComandos = "xdg-open ";
	lineaDeComandos += (char) 34 + nombreArchivo + (char) 34;
#endif
	system(lineaDeComandos.c_str());
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

string Archivo::obtenerRutaArchivosDatos(string nombreArchivoDatos) {
	return concatenarRutas(
			concatenarRutas(obtenerRutaEjecucion(), DIRECTORIO_ARCHIVOS_DATOS),
			nombreArchivoDatos);
}

Lista<Cultivo*>* Archivo::leerCultivos() {

	std::ifstream entrada;
	std::string rutaDeterminada = this->obtenerRutaArchivosDatos(
			ARCHIVO_CULTIVOS);
	entrada.open(rutaDeterminada.c_str());

	std::string linea;
	if (entrada.fail()) {
		std::cout << "Error al abrir el archivo" << std::endl;
	}
	Lista<Cultivo*>* cultivosDisponibles = new Lista<Cultivo*>;

	while (getline(entrada, linea)) {
		std::stringstream ss(linea);

		std::string nombreCultivo;
		getline(ss, nombreCultivo, ',');

		int costo = 0, tiempoDeCrecimiento = 0, rentabilidad = 0,
				tiempoDeRecuperacion = 0, consumoDeAgua = 0;
		char separador;

		ss >> costo >> separador;
		ss >> tiempoDeCrecimiento >> separador;
		ss >> rentabilidad >> separador;
		ss >> tiempoDeRecuperacion >> separador;
		ss >> consumoDeAgua >> separador;

		Cultivo* nuevoCultivo = new Cultivo(nombreCultivo, costo,
				tiempoDeCrecimiento, rentabilidad, tiempoDeRecuperacion,
				consumoDeAgua);
		cultivosDisponibles->agregar(nuevoCultivo);
	}

	entrada.close();
	return cultivosDisponibles;
}

Lista<Destino*>* Archivo::leerDestinos() {
	std::ifstream entrada;
	std::string rutaDeterminada = this->obtenerRutaArchivosDatos(
			ARCHIVO_DESTINOS);

	entrada.open(rutaDeterminada.c_str());
	if (entrada.fail()) {
		std::cout << "Ha ocurrido un error al abrir el archivo." << std::endl; //TODO: ver si conviene lanzar Excepcion...
	}
	Lista<Destino*>* destinosDisponibles = new Lista<Destino*>;

	std::string linea;
	while (getline(entrada, linea)) {
		std::stringstream ss(linea);

		std::string nombreDestino;
		getline(ss, nombreDestino, ',');

		int km = 0, precio = 0;
		std::string cultivoAceptado;

		Destino* nuevoDestino = new Destino(nombreDestino, km, precio,
				cultivoAceptado);
		destinosDisponibles->agregar(nuevoDestino);

	}

	entrada.close();
	return destinosDisponibles;
}

bool Archivo::existe(const string& nombreArchivo) {
#ifdef linux
	struct stat buffer;
	return (stat(nombreArchivo.c_str(), &buffer) == 0);
#elif _WIN32
	unsigned long dwAttrib = GetFileAttributes(nombreArchivo.c_str());
	return (dwAttrib != INVALID_FILE_ATTRIBUTES
			&& !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
#endif
}

Archivo::~Archivo() {
	std::cout << "Archivo::~Archivo()" << std::endl;
}
