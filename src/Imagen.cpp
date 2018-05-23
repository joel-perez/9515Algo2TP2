#include "Imagen.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Imagen::Imagen() {
	fondoTerreno.ReadFromFile("terreno.bmp");
	imagenDelTerreno.SetSize(fondoTerreno.TellWidth(),
			fondoTerreno.TellHeight());
	imagenDelTerreno.SetBitDepth(24);
	cultivo.ReadFromFile("cultivodefault.bmp");
	cultivoVacio.ReadFromFile("cultivovacio.bmp");
	cultivoSeco.ReadFromFile("cultivoseco.bmp");
	cultivoRecienSembrado.ReadFromFile("cultivobebe.bmp");
	cultivoPodrido.ReadFromFile("cultivopodrdio.bmp");

	color.Red = 225;
	color.Blue = 225;
	color.Green = 225;
}

void Imagen::mostrarTerrenos(Jugador* jugador, unsigned int columnas,
		unsigned int filas, unsigned int turno) {
	//	archivo.abrirConAplicacionPredeterminada("C:\\Cloud\\MEGA\\UBA\\FIUBA\\95 Computacion\\95.15 Algoritmos y Programaci�n II\\Trabajos Practicos\\2018 a\\GitHub\\EasyBMPTest\\res\\frutilla.bmp");
	int numeroTerreno = 1;
	Lista<Terreno*>* terrenos = jugador->obtenerTerrenos();
	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		Terreno* terrenoParaGraficar = terrenos->obtenerCursor();
		cout << "Generando imagen, espere un momento..." << endl;
		this->obtenerImagenDelTerreno(terrenoParaGraficar, jugador, columnas,
				filas, turno, numeroTerreno);
		numeroTerreno++;
	}
}
string Imagen::casquearNumeroAString(unsigned int numero) {
	//   int to string en c++
	std::ostringstream convert;
	convert << numero;
	return convert.str();
}

void Imagen::obtenerImagenDelTerreno(Terreno* terreno, Jugador* jugador,
		unsigned int columnas, unsigned int filas, unsigned int turno,
		int numeroTerreno) {
	string nombreImagen = jugador->obtenerNombre() + "-turno-"
			+ this->casquearNumeroAString(turno) + "-terreno-"
			+ this->casquearNumeroAString(numeroTerreno) + ".bmp";

	this->pegarEstadoDelTerreno(terreno, columnas, filas);
	archivo.crearDirectorio(archivo.obtenerRutaCapturasPantalla().c_str());
	string rutaCompleta = archivo.concatenarRutas(
			archivo.obtenerRutaCapturasPantalla(), nombreImagen);
	imagenDelTerreno.WriteToFile(rutaCompleta.c_str());
}

void Imagen::rescalarImagenes(unsigned int columnas) {

}

void Imagen::pegarEstadoDelTerreno(Terreno* terreno, unsigned int columnas,
		unsigned int filas) {
	RangedPixelToPixelCopy(fondoTerreno, 0, fondoTerreno.TellWidth(),
			fondoTerreno.TellHeight(), 0, imagenDelTerreno, 0, 0);
	this->rescalarImagenes(columnas);
	Lista<Parcela*>* parcelas = terreno->obtenerParcelas();
	parcelas->iniciarCursor();
	unsigned int fila = 1;
	unsigned int columna = 1;

	while (fila <= filas) {
		while (columna <= columnas && parcelas->avanzarCursor()) {
			Parcela* parcela = parcelas->obtenerCursor();

			if (!parcela->estaOcupada()) {
				RangedPixelToPixelCopyTransparent(cultivoVacio, 0,
						cultivo.TellWidth(), cultivo.TellHeight(), 0,
						imagenDelTerreno, (columna * cultivo.TellWidth()),
						(fila * cultivo.TellHeight()), *cultivo(0, 49));
			} else if (!parcela->yaEstaRegada()) {
				RangedPixelToPixelCopyTransparent(cultivoSeco, 0,
						cultivo.TellWidth(), cultivo.TellHeight(), 0,
						imagenDelTerreno, (columna * cultivo.TellWidth()),
						(fila * cultivo.TellHeight()), *cultivo(0, 49));
			} else {
				this->obtenerCultivo(
						parcela->obtenerCultivo()->obtenerNombre());
				RangedPixelToPixelCopyTransparent(cultivo, 0,
						cultivo.TellWidth(), cultivo.TellHeight(), 0,
						imagenDelTerreno, (columna * cultivo.TellWidth()),
						(fila * cultivo.TellHeight()), *cultivo(0, 49));
			}
			columna++;
		}
		fila++;
		columna = 1;
	}
}
void Imagen::obtenerCultivo(string nombreCultivo) {

	if (nombreCultivo == "trigo") {
		cultivo.ReadFromFile("trigo.bmp");
	} else if (nombreCultivo == "frutilla") {
		cultivo.ReadFromFile("frutilla.bmp");
	} else if (nombreCultivo == "banana") {
		cultivo.ReadFromFile("cultivodefault.bmp");
	} else if (nombreCultivo == "cannabis") {
		cultivo.ReadFromFile("cannabis.bmp");
	} else if (nombreCultivo == "maiz") {
		cultivo.ReadFromFile("maiz.bmp");
	} else if (nombreCultivo == "girasol") {
		cultivo.ReadFromFile("girasol.bmp");
	} else {
		cultivo.ReadFromFile("cultivodefault.bmp");
	}
}

Imagen::~Imagen() {

}
