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
	cout << "La carpeta del ejecutable actual es: "
			<< archivo.obtenerRutaEjecucion() << endl;
	cout << "Capturas de Pantalla: " << archivo.obtenerRutaCapturasPantalla()
			<< endl;
	cout << "Recursos (Imagenes): " << archivo.obtenerRutaRecursos() << endl;
}

void Consola::mostrarDatosDelTurno(Jugador* jugadorActual, unsigned int turnoActual) {
	cout<<"\n JUGADOR: "<<jugadorActual->obtenerNombre()<<endl;
	cout<<"Turno Nro: "<<turnoActual+1<<endl;
	cout<<"Creditos: "<<jugadorActual->obtenerCreditos()<<endl;

}

void Consola::mostrarTerrenos(Jugador* jugadorActual) {
	cout << "Estado del Terreno:" << endl << endl;
	Lista<Terreno*>* terrenos = jugadorActual->obtenerTerrenos();
	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		Terreno* terrenoActual = terrenos->obtenerCursor();

		for (unsigned int i = 0; i < terrenoActual->obtenerFilas(); i++) {
			for (unsigned int j = 0; j < terrenoActual->obtenerColumnas();
					j++) {
				Parcela* miParcela = terrenoActual->obtenerParcela(i, j);
				cout << " " << miParcela->obtenerEstado();
			}
			cout << endl;
		}

		/*
		 Lista<Lista<Parcela*>*>* parcelas = terrenoActual->obtenerParcelas();
		 parcelas->iniciarCursor();
		 while (parcelas->avanzarCursor()) {
		 Lista<Parcela*>* unaColumna = parcelas->obtenerCursor();
		 unaColumna->iniciarCursor();
		 while (unaColumna->avanzarCursor()) {
		 Parcela* unaParcela = unaColumna->obtenerCursor();
		 std::cout << " | " << unaParcela->obtenerEstado() << "|";
		 }
		 std::cout << std::endl;
		 }
		 */
	}

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

string Consola::SolicitarIngresoLineaTexto() {
	std::string textLine = "";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, textLine);
	return textLine;
}
