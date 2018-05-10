#include <iostream>
#include <string>
#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = new Lista<Jugador*>;
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
	cout << "Ingrese un numero entre 1 y 10... solo para probar ;)" << endl;
	unsigned int numerito = consola.solicitarIngresoNumerico(1, 10);
	cout << "El numero ingresado es: " << numerito << endl;
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
