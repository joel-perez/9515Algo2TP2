#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

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
	cout << "Archivo de Cultivos: "
			<< archivo.obtenerRutaArchivosDatos(ARCHIVO_CULTIVOS) << endl;
	cout << "Archivo de Destinos: "
			<< archivo.obtenerRutaArchivosDatos(ARCHIVO_DESTINOS) << endl;
	cout << "Recursos (Imagenes): " << archivo.obtenerRutaRecursos() << endl
			<< endl << endl << endl;
}

void Consola::mostrarDatosDelTurno(Jugador* jugadorActual,
		unsigned int turnoActual) {
	cout << endl << "JUGADOR: " << jugadorActual->obtenerNombre() << endl;
	cout << "Turno Nro: " << turnoActual << endl;
	cout << "Creditos: " << jugadorActual->obtenerCreditos() << endl;
}

void Consola::mostrarTerrenos(Jugador* jugadorActual) {
	cout << "Estado del Terreno:" << endl << endl;
	Lista<Terreno*>* terrenos = jugadorActual->obtenerTerrenos();
	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		Terreno* terrenoActual = terrenos->obtenerCursor();
		for (unsigned int i = 1; i <= terrenoActual->obtenerFilas(); i++) {
			for (unsigned int j = 1; j <= terrenoActual->obtenerColumnas();
					j++) {
				Parcela* miParcela = terrenoActual->obtenerParcela(i, j);
				cout
						<< texto.rellenarDerecha(
								miParcela->obtenerEstadoParaMostrarEnPantalla(),
								10, ' ');
			}
			cout << endl;
		}
	}
}

void Consola::mostrarFin(Lista<Jugador*>* jugadores) {
	//TODO: Agregar resultados finales, o sea quien gano el juego con sus terrenos,
	//      La lista de todos los jugadores ordenados descendentemente por cantidad de creditos.
	//      Guardar la imagen BMP final con todos estos datos tambien...
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

void Consola::mostrarDestinosDisponibles(Lista<Destino*>* destinos) {
	destinos->iniciarCursor();
	while (destinos->avanzarCursor()) {
		Destino* destinoActual = destinos->obtenerCursor();
		cout << "Destino: " << destinoActual->obtenerNombre() << endl;
		cout << "\t Costo de envio: " << destinoActual->obtenerCostoDeEnvio()
				<< endl;
		cout << "\t Tipo de cultivo que acepta: "
				<< destinoActual->obtenerCultivoQueAcepta().obtenerNombre()
				<< endl;
	}
}
