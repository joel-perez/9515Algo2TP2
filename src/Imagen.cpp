#include "Imagen.h"
#include <string>

using namespace std;

Imagen::Imagen() {
	fondoTerreno.ReadFromFile("terreno.bmp");
	imagenDelTerreno.SetSize(fondoTerreno.TellWidth(),
			fondoTerreno.TellHeight());
	imagenDelTerreno.SetBitDepth(24);
	cultivo.ReadFromFile("frutilla.bmp");
	color.Red = 225;
	color.Blue = 225;
	color.Green = 225;
}

void Imagen::mostrarTerrenos(Jugador* jugador, unsigned int columnas,
		unsigned int filas) {
	//	archivo.abrirConAplicacionPredeterminada("C:\\Cloud\\MEGA\\UBA\\FIUBA\\95 Computacion\\95.15 Algoritmos y Programaci�n II\\Trabajos Practicos\\2018 a\\GitHub\\EasyBMPTest\\res\\frutilla.bmp");

	Lista<Terreno*>* terrenos = jugador->obtenerTerrenos();
	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		Terreno* terrenoParaGraficar = terrenos->obtenerCursor();
		this->obtenerImagenDelTerreno(terrenoParaGraficar, jugador, columnas,
				filas);
	}

}

void Imagen::obtenerImagenDelTerreno(Terreno* terreno, Jugador* jugador,
		unsigned int columnas, unsigned int filas) {
	string nombre = jugador->obtenerNombre();

	this->pegarEstadoDelTerreno(terreno, columnas, filas);
	string rutaCompleta = archivo.concatenarRutas(
			archivo.obtenerRutaCapturasPantalla(), "ejemploterreno.bmp");
	imagenDelTerreno.WriteToFile(rutaCompleta.c_str());
}

void Imagen::rescalarImagenes(unsigned int columnas) {
	Rescale(cultivo, 'f',
			(imagenDelTerreno.TellWidth() - (2 * MARGEN_COLUMNA)) / columnas);
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
				char datoParaImprimir[20] = "asdfghjkloiuytredsg";

				std::strcpy(datoParaImprimir, parcela->obtenerNombre().c_str());

				RangedPixelToPixelCopyTransparent(cultivo, 0,
						cultivo.TellWidth(), cultivo.TellHeight(), 0,
						imagenDelTerreno, (columna * cultivo.TellWidth()) + 0,
						(fila * cultivo.TellHeight()) + 0, *cultivo(0, 49));
				PrintString(cultivo, datoParaImprimir, cultivo.TellWidth() / 2,
						(cultivo.TellHeight() / 2) + 17, 8, color);

			}
			columna++;
		}
		fila++;
		columna = 1;
	}
}

Imagen::~Imagen() {

}
