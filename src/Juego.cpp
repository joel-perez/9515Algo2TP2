#include <iostream>
#include <string>
#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = new Lista<Jugador*>;
	this->cultivos = new Lista<Cultivo*>;
	this->turnos = 0;
	this->turnoActual = 0;
	//this->dificultad = Dificultad(1);
}

Lista<Jugador*>* Juego::obtenerJugadores() {
	return this->jugadores;
}

void Juego::administrarAguaDelTurno(Jugador* jugador) {

}

void Juego::solicitarAcciones(Jugador* jugador) {

}

void Juego::procesarTurno(Jugador* jugador) {

}

void Juego::solicitarDatosIniciales() {
	this->jugadores = solicitarJugadores();
	solicitarTamanioTerreno(); //TODO: Ver si es sencillo usar un TDA Dimensiones, o devolver valores por referencia, etc.
	this->turnos = solicitarCantidadTurnos();
	this->dificultad = solicitarDificultad();
}

Lista<Jugador*>* Juego::solicitarJugadores() {
	return new Lista<Jugador*>();
}

unsigned int Juego::solicitarCantidadTurnos() {
	return 1; //TODO: Completar...
}

void Juego::solicitarTamanioTerreno() {

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

}

void Juego::iniciarJuego() {
	consola.mostrarBienvenida();
	cargarArchivos();
	solicitarDatosIniciales();
	while (turnoActual <= this->turnos) {
		jugadores->iniciarCursor();
		while (jugadores->avanzarCursor()) {
			Jugador* jugadorActual = jugadores->obtenerCursor();
			//Esto va a ir en el TDA Jugador
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

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...
