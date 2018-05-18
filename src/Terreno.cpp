#include "Terreno.h"

using namespace std;

Terreno::Terreno() {
	//this->parcelas = new Lista<Lista<Parcela*>*>;
	this->tamanioFilas = 0;
	this->tamanioColumnas = 0;

}

Terreno::Terreno(unsigned int filas, unsigned int columnas) {

	if ((filas < TERRENO_MIN_FILAS) || (columnas < TERRENO_MIN_COLUMNAS))
		//throw std::string("El terreno como minimo debe ser de " + TERRENO_MIN_FILAS + " filas por " + TERRENO_MIN_COLUMNAS + " columnas");
		throw string("Error al contruir terreno...");
	this->inicializarTerreno(filas, columnas);
}

void Terreno::inicializarTerreno(unsigned int filas, unsigned int columnas) {

	//Esto es usando un array... pero no me deja hacerlo dinamicamente...
	//this->parcelas = new Parcela[filas][columnas];
	//

	//Probando una nueva implementacion de lista...
	unsigned int tamanioTotal = filas * columnas;
	this->parcelas = new Lista<Parcela*>();
	for (unsigned int i = 0; i < tamanioTotal; i++) {
		Parcela* nuevaParcela = new Parcela();
		this->parcelas->agregar(nuevaParcela);
	}
	//

	// Esto es usando Lista...
	/*for (unsigned int i = 0; i < columnas; i++) {

	 Lista<Parcela*>* nuevaColumna = new Lista<Parcela*>;

	 for (unsigned int j = 0; j < filas; j++) {

	 Parcela* nuevaParcela = new Parcela;
	 nuevaColumna->agregar(nuevaParcela);
	 }}*/
	//
	this->tamanioFilas = filas;
	this->tamanioColumnas = columnas;
}

unsigned int Terreno::obtenerFilas() {
	return this->tamanioFilas;
}
unsigned int Terreno::obtenerColumnas() {
	return this->tamanioColumnas;
}

Parcela* Terreno::obtenerParcela(unsigned int fila, unsigned int columna) {
	Parcela* resultado;
	if (fila > this->tamanioFilas || columna > this->tamanioColumnas)
		throw string("Indice fuera de rango."); // TODO: Mejorar este mensaje...
	unsigned int indiceBuscado = fila * this->tamanioColumnas + columna;
	unsigned int indiceActual = 0;
	this->parcelas->iniciarCursor();
	while (this->parcelas->avanzarCursor() && indiceActual < indiceBuscado) {
		resultado = this->parcelas->obtenerCursor();
	}
	return resultado;
}
