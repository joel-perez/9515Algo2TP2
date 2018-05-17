#include <iostream>
#include <string>
#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = new Lista<Jugador*>;
	this->cultivos = new Lista<Cultivo*>;
	this->destinos = new Lista<Destino*>;
	this->turnos = 0;
	this->turnoActual = 0;
	this->numeroDeJugadores = 0;
	this->anchoTerreno = 0;
	this->altoTerreno = 0;
}

Lista<Jugador*>* Juego::obtenerJugadores() {
	return this->jugadores;
}
Lista<Cultivo*>* Juego::obtenerCultivos(){
	return this->cultivos;
}
void Juego::administrarAguaDelTurno(Jugador* jugador) {

}

void Juego::solicitarAcciones(Jugador* jugador) {

}

void Juego::procesarTurno(Jugador* jugador) {

}

void Juego::solicitarDatosIniciales() {
	solicitarTamanioTerreno(); //TODO: Ver si es sencillo usar un TDA Dimensiones, o devolver valores por referencia, etc.
	this->jugadores = solicitarJugadores();
	this->turnos = solicitarCantidadTurnos();
	this->dificultad = solicitarDificultad();
}

Lista<Jugador*>* Juego::solicitarJugadores() {

	Lista<Jugador*>* resultado = new Lista<Jugador*>;
	unsigned int contador = 0;
	unsigned int cantidad;
	string nombre = "";
	cout << "Ingrese la CANTIDAD de jugadores: ";
	cin >> cantidad;
	this->numeroDeJugadores = cantidad;
	do {
		cout << ">JUGADOR -" << contador + 1 << "- :";
		nombre = consola.SolicitarIngresoLineaTexto();
		Jugador* nuevoJugador = new Jugador(nombre);
		Terreno* nuevoTerreno = new Terreno(altoTerreno, anchoTerreno);
		nuevoJugador->obtenerTerrenos()->agregar(nuevoTerreno);
		resultado->agregar(nuevoJugador);
		contador++;
	} while (contador < this->numeroDeJugadores);
	return resultado;
}

unsigned int Juego::solicitarCantidadTurnos() {

	cout << "Ingrese la cantidad de TURNOS [cantidad max. " << MAX_TURNO
			<< " - cantidad min. " << MIN_TURNO << "]: " << endl;
	unsigned int cantidadDeTurnos = consola.solicitarIngresoNumerico(MIN_TURNO,
			MAX_TURNO);
	return (this->turnos = cantidadDeTurnos);
}

void Juego::solicitarTamanioTerreno() {
	cout << "Ingrese cuantas filas y columnas tendra el Terreno." << endl;
	cout << "[el minimo es " << TERRENO_MIN_FILA_COLUMNA << "]" << endl;
	cout << "[el maximo es " << TERRENO_MAX_FILA_COLUMNA << "]" << endl;
	cout << ">Filas:";
	this->altoTerreno = consola.solicitarIngresoNumerico(
			TERRENO_MIN_FILA_COLUMNA, TERRENO_MAX_FILA_COLUMNA);
	cout << ">columnas:";
	this->anchoTerreno = consola.solicitarIngresoNumerico(
			TERRENO_MIN_FILA_COLUMNA, TERRENO_MAX_FILA_COLUMNA);
}

Dificultad Juego::solicitarDificultad() {
	cout << "Ingrese el Nivel de Dificultad:" << endl;
	cout << "1 - Facil." << endl;
	cout << "2 - Medio." << endl;
	cout << "3 - Dificil." << endl;
	unsigned int dificultadSeleccionada = consola.solicitarIngresoNumerico(1,
			3);
	return Dificultad(dificultadSeleccionada);
}

void Juego::cargarArchivos() {
	this->cultivos = archivo.leerCultivo();
	this->destinos = archivo.leerDestino();
}

void Juego::iniciarJuego() {
	consola.mostrarBienvenida();
	cargarArchivos();
	solicitarDatosIniciales();
	while (turnoActual <= this->turnos) {
		jugadores->iniciarCursor();
		while (jugadores->avanzarCursor()) {
			Jugador* jugadorActual = jugadores->obtenerCursor();
			//Esto va a ir en el TDA Jugador, posiblemente...
			consola.mostrarDatosDelTurno(jugadorActual);
			consola.mostrarTerreno(jugadorActual);
			administrarAguaDelTurno(jugadorActual);
			solicitarAcciones(jugadorActual);
			procesarTurno(jugadorActual);
			//
		}
		turnoActual++;
	}
	consola.mostrarFin(jugadores);
}
