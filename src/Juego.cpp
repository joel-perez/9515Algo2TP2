#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = new Lista<Jugador*>;
}

Lista<Jugador*>* Juego::obtenerJugadores() {
	return this->jugadores;
}

void Juego::iniciarJuego() {
	Consola consola;
	consola.MostrarBienvenida();
	//TODO: Lo siguiente lo copie y pegue del TP1, hay que mejorarlo y ya esta.
	//while (turnoActual <= CANTIDAD_TURNOS) {
	//	mostrarDatosDelTurno(turnoActual, creditoActual);
	//	mostrarTerreno(terreno);
	//	administrarAguaDelTurno(tanqueCantidadActual);
	//	solicitarAcciones(terreno, creditoActual, tanqueCantidadActual);
	//	procesarTurno(terreno);
	//	turnoActual++;
	//}
	//mostrarFin(terreno, creditoActual, tanqueCantidadActual);
}

//TODO: Agregar los metodos publicos necesarios con sus PRE y POST condiciones...
