#include <iostream>
#include <limits>
#include <string>
#include "Consola.h"

using namespace std;

void Consola::mostrarBienvenida() {
	cout << "=) T.P. Nro. 2 - Granjeros." << endl;
	cout << "  		   ..:::Bienvenidos:::.." << endl << endl;
	cout << "El juego consiste en maximizar las ganancias del jugador" << endl;
	cout << "				Buena suerte		" << endl << endl;

	Archivo archivo;
	cout << "El separador de directorios para el S.O. Actual es: "
			<< archivo.obtenerSeparadorDirectorio() << endl;
	cout << "La ruta del ejecutable actual es: "
			<< archivo.obtenerRutaEjecutable() << endl;
}

void Consola::mostrarDatosDelTurno(Jugador* jugadorActual) {

}

void Consola::mostrarTerreno(Jugador* jugadorActual) {

}

void Consola::mostrarFin(Lista<Jugador*>* jugadores) {
	this->solicitarEnterParaSalir();
}

unsigned int Consola::solicitarIngresoNumerico(unsigned int minValor,
		unsigned int maxValor) {
	unsigned int numero = 0;
	bool esValido = false;
	while (!esValido) {
		if (!(cin >> numero)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Debe ingresar un numero valido." << endl;
		}
		esValido = (numero >= minValor && numero <= maxValor);
		if (!esValido) {
			cout << "Debe ingresar un numero entre " << minValor << " y "
					<< maxValor << endl;
		}
	}
	return numero;
}

void Consola::solicitarEnterParaSalir() {
	cout << "Presione ENTER para Salir." << endl;
	cin.ignore();
	cin.get();
}
