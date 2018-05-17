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

void Consola::mostrarDatosDelTurno(Jugador* jugadorActual, unsigned int turno) {
	cout<< "Turno Nro: "<< turno + 1 << endl;
	cout<<"Cantidad de creditos: "<<jugadorActual->obtenerCreditos()<<endl;
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

string Consola::SolicitarIngresoLineaTexto() {
	std::string textLine = "";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, textLine);
	return textLine;
}

void Consola::mostrarAcciones(){
	cout<<"Seleccione una accion:" <<endl;
	cout<<"\tSembrar semillas en una parcela."<<endl;
	cout<<"\tCosechar una parcela."<<endl;
	cout<<"\tRegar una parcela."<<endl;
	cout<<"\tEnviar una cosecha a destino."<<endl;
	cout<<"\tComprar un Terreno."<<endl;
	cout<<"\tVender un Terreno."<<endl;
	cout<<"\tComprar capacidad del tanque de agua."<<endl;
	cout<<"\tComprar capacidad del almacen."<<endl;
}
