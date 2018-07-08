#include "Imagen.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Imagen::Imagen() {
	archivo = new Archivo();
	fondoTerreno.ReadFromFile(
			archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
					"terreno.bmp").c_str());
	imagenDelTerreno.SetBitDepth(24);
	cultivo.ReadFromFile(
			archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
					"cultivodefault.bmp").c_str());
	cultivoVacio.ReadFromFile(
			archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
					"cultivovacio.bmp").c_str());
	cultivoSeco.ReadFromFile(
			archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
					"cultivoseco.bmp").c_str());
	cultivoRecienSembrado.ReadFromFile(
			archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
					"cultivobebe.bmp").c_str());
	cultivoPodrido.ReadFromFile(
			archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
					"cultivopodrido.bmp").c_str());
}

void Imagen::mostrarTerrenos(Jugador* jugador, unsigned int columnas,
		unsigned int filas, unsigned int turno) {
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

void Imagen::obtenerImagenDelTerreno(Terreno* terreno, Jugador* jugador,
		unsigned int columnas, unsigned int filas, unsigned int turno,
		int numeroTerreno) {
	string nombreImagen = jugador->obtenerNombre() + "-turno-"
			+ texto.intToString(turno) + "-terreno-"
			+ texto.intToString(numeroTerreno) + EXTENSION_IMAGEN;
	this->determinarMedidaDeLaImagen(columnas, filas);
	this->pegarFondo(columnas, filas);
	this->pegarEstadoDelTerreno(terreno, columnas, filas);
	archivo->crearDirectorio(archivo->obtenerRutaCapturasPantalla().c_str());
	string rutaCompleta = archivo->concatenarRutas(
			archivo->obtenerRutaCapturasPantalla(), nombreImagen);
	imagenDelTerreno.WriteToFile(rutaCompleta.c_str());
	archivo->abrirConAplicacionPredeterminada(rutaCompleta.c_str());
}

void Imagen::determinarMedidaDeLaImagen(unsigned int columnas,
		unsigned int filas) {
	imagenDelTerreno.SetSize((cultivo.TellWidth() * columnas) + 135,
			(cultivo.TellHeight() * filas) + 135);
}
void Imagen::pegarFondo(unsigned int columnas, unsigned int filas) {
	RangedPixelToPixelCopy(fondoTerreno, 0, fondoTerreno.TellWidth(),
			fondoTerreno.TellHeight(), 0, imagenDelTerreno, 0, 0);
}
void Imagen::pegarEstadoDelTerreno(Terreno* terreno, unsigned int columnas,
		unsigned int filas) {
	Lista<Parcela*>* parcelas = terreno->obtenerParcelas();
	parcelas->iniciarCursor();
	unsigned int fila = 1;
	unsigned int columna = 1;

	while (fila <= filas) {
		while (columna <= columnas && parcelas->avanzarCursor()) {
			Parcela* parcela = parcelas->obtenerCursor();

			if (parcela->obtenerEstado() == SECA) {
				RangedPixelToPixelCopyTransparent(cultivoSeco, 0,
						cultivo.TellWidth(), cultivo.TellHeight(), 0,
						imagenDelTerreno, (columna * cultivo.TellWidth()),
						(fila * cultivo.TellHeight()), *cultivo(0, 49));
			} else if (parcela->obtenerEstado() == SEMBRADA) {
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
	string nombreArchivo = archivo->concatenarRutas(
			archivo->obtenerRutaRecursos(), nombreCultivo + EXTENSION_IMAGEN);
	if (!archivo->existe(nombreArchivo))
		nombreArchivo = archivo->concatenarRutas(archivo->obtenerRutaRecursos(),
				"cultivodefault.bmp");
	if (archivo->existe(nombreArchivo))
		cultivo.ReadFromFile(nombreArchivo.c_str());
}

Imagen::~Imagen() {
	delete archivo;
}
