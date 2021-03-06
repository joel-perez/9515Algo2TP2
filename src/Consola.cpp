#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

#include "Consola.h"

using namespace std;

void Consola::mostrarBienvenida() {
	cout << "Algoritmos y Programacion 2 - T.P. Nro. 2 - Granjeros." << endl;
	cout << "..:::Bienvenidos:::.." << endl << endl;
	cout << "El juego consiste en maximizar las ganancias del jugador" << endl;
	cout << "Buena suerte!!" << endl << endl;
}

void Consola::mostrarDatosDelTurno(Jugador* jugadorActual,
		unsigned int turnoActual) {
	cout << endl << "JUGADOR: " << jugadorActual->obtenerNombre() << endl;
	cout << "Turno Nro: " << turnoActual << endl;
	cout << "Creditos: " << jugadorActual->obtenerCreditos() << endl;
	cout << "Unidades de agua almacenada en Tanque: "<<jugadorActual->obtenerTanque()->obtenerAguaDisponible()<<endl;

}

void Consola::mostrarTerrenos(Jugador* jugadorActual) {
	cout << "Estado del Terreno:" << endl << endl;
	Lista<Terreno*>* terrenos = jugadorActual->obtenerTerrenos();
	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		Terreno* terrenoActual = terrenos->obtenerCursor();
		mostrarTerreno(terrenoActual);
	}
}

void Consola::mostrarTerreno(Terreno* terrenoActual) {
	for (unsigned int i = 1; i <= terrenoActual->obtenerFilas(); i++) {
		for (unsigned int j = 1; j <= terrenoActual->obtenerColumnas(); j++) {
			Parcela* miParcela = terrenoActual->obtenerParcela(i, j);
			cout
					<< texto.rellenarDerecha(
							miParcela->obtenerEstadoParaMostrarEnPantalla()
									+ " ("
									+ texto.intToString(
											miParcela->obtenerTiempoHastaCosecha())
									+ ")", 15, ' ');
		}
		cout << endl;
	}
}

void Consola::mostrarFin(Lista<Jugador*>* jugadores) {
	unsigned int maxCredito = 0;
	string nombreMaxCredito = "";
	jugadores->iniciarCursor();
	while (jugadores->avanzarCursor()) {
		Jugador* jugador = jugadores->obtenerCursor();
		if (jugador->obtenerCreditos() > maxCredito) {
			maxCredito = jugador->obtenerCreditos();
			nombreMaxCredito = jugador->obtenerNombre();
		}
	}
	cout<<""<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << "El ganador es el jugador: " << nombreMaxCredito << endl;
	cout << "Que acumulo un total de " << maxCredito
			<< " Creditos al finalizar el juego." << endl << endl;

	this->solicitarEnterParaSalir();
}

unsigned int Consola::solicitarIngresoNumerico(unsigned int minValor,
		unsigned int maxValor) {
	unsigned int numero = 0;
	bool esValido = false;
	while (!esValido) {
		if (!(cin >> numero)) {
			LimpiarIngreso();
			cout << "Debe ingresar un numero valido." << endl;
		} else {
			esValido = (numero >= minValor && numero <= maxValor);
			if (!esValido) {
				cout << "Debe ingresar un numero entre " << minValor << " y "
						<< maxValor << endl;
			}
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
	string lineaTexto = "";
	bool esValido = false;
	while (!esValido) {
		char input[100];
		cin.getline(input, sizeof(input));
		lineaTexto = string(input);
		esValido = (lineaTexto != "");
		if (!esValido) {
			cout << "Debe ingresar un Texto." << endl;
		}
	}
	return lineaTexto;
}

void Consola::LimpiarIngreso() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Consola::mostrarPosiblesAcciones() {
	cout << "Ingrese la accion a realizar: " << endl << endl;
	cout << " 1 - Sembrar semillas en un parcela." << endl;
	cout << " 2 - Regar una parcela." << endl;
	cout << " 3 - Cosechar una parcela." << endl;
	cout << " 4 - Enviar una cosecha a un destino." << endl;
	cout << " 5 - Comprar un terreno." << endl;
	cout << " 6 - Vender un terreno." << endl;
	cout << " 7 - Comprar mas capacidad para el tanque." << endl;
	cout << " 8 - Comprar mas capacidad para el almacen." << endl;
	cout << " 9 - Cambiar de Terreno." << endl;
	cout << "10 - Avanzar al siguiente turno." << endl;
	cout << "11 - Abandonar el Juego." << endl;
}

void Consola::mostrarCultivosDisponibles(Lista<Cultivo*>* cultivos) {
	unsigned int i = 1;
	cout << "Seleccione uno de los siguientes cultivos:" << endl;
	cultivos->iniciarCursor();
	while (cultivos->avanzarCursor()) {
		Cultivo* cultivoActual = cultivos->obtenerCursor();
		cout << i << ") Cultivo: " << cultivoActual->obtenerNombre();
		cout << " Consumo de Agua: " << cultivoActual->obtenerConsumoDeAgua();
		cout << " Costo: " << cultivoActual->obtenerCosto();
		cout << " Rentabilidad: " << cultivoActual->obtenerRentabilidad();
		cout << " Tiempo de cosecha: "
				<< cultivoActual->obtenerTiempoHastaCosecha();
		cout << " Tiempo de recuperacion: "
				<< cultivoActual->obtenerTiempoRecuperacion();
		cout << endl;
		i++;
	}
}

void Consola::mostrarDestinosDisponibles(Grafo* destinos) {
	destinos->obtenerVertices()->iniciarCursor();
	while (destinos->obtenerVertices()->avanzarCursor()) {
		Vertice* actual = destinos->obtenerVertices()->obtenerCursor();
		cout << "Destino: " << actual->obtenerNombre()
				<< " // Posibles cultivos: ";
		actual->mostrarPosiblesEnvios();
		cout << endl;
	}
}

void Consola::mostrarAlmacenesDisponibles(Lista<Almacen*>* almacenes) {
	unsigned int i = 1;
	almacenes->iniciarCursor();
	while (almacenes->avanzarCursor()) {
		Almacen* almacen = almacenes->obtenerCursor();
		int cantidadCultivos = almacen->obtenerCultivos()->contarElementos();
		cout << texto.intToString(i) << " - Almacen Nro. "
				<< texto.intToString(i) << "(" << cantidadCultivos << ")"
				<< endl;
		i++;
	}
}

void Consola::mostrarCultivosDisponiblesDeUnAlmacen(Almacen* almacen) {
	unsigned int i = 1;
	Lista<Cultivo*>* cultivos = almacen->obtenerCultivos();
	cultivos->iniciarCursor();
	while (cultivos->avanzarCursor()) {
		Cultivo* cultivo = cultivos->obtenerCursor();
		cout << "Elija el cultivo que desea enviar a destino:" << endl;
		cout << i << " ) " << cultivo->obtenerNombre();
		cout << " - Rentabilidad: " << cultivo->obtenerRentabilidad() << endl;
		i++;
	}

}

void Consola::mostrarAguaDisponibleParaRegar(Jugador* jugadorActual){
	cout<<">Unidades de Agua disponoble para riego: "<<jugadorActual->obtenerTanque()->obtenerAguaDisponible()<<endl;
	cout<<""<<endl;
 }
