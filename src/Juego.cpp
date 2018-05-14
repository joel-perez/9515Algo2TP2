#include <iostream>
#include <string>
#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = new Lista<Jugador*>;
	this->cultivos = new Lista<Cultivo*>;

	this->turnos = 0;
	this->turnoActual = 0;
	this->numeroDeJugadores=0;

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
	solicitarJugadores();
	solicitarTamanioTerreno(); //TODO: Ver si es sencillo usar un TDA Dimensiones, o devolver valores por referencia, etc.
	this->turnos = solicitarCantidadTurnos();
	this->dificultad = solicitarDificultad();
}

void Juego::solicitarJugadores() {
	unsigned int contador=0;
	unsigned int cantidad;
	string nombre="";
	cout<<"Ingrese la CANTIDAD de jugadores:"<<endl;
	cin>>cantidad;
	this->numeroDeJugadores=cantidad;
	do{
		cout<<">JUGADOR -"<<contador + 1<<"- :";
		cin>>nombre;
		Jugador* nuevoJugador=new Jugador(nombre);
		this->jugadores->agregar(nuevoJugador);
		contador++;
	}while(contador < this->numeroDeJugadores);

}

unsigned int Juego::solicitarCantidadTurnos() {

	cout<<"Ingrese la cantidad de TURNOS [cantidad max. "<<MAX_TURNO<<" - cantidad min. "<<MIN_TURNO<<"]: "<<endl;
	unsigned int cantidadDeTurnos = consola.solicitarIngresoNumerico(MIN_TURNO,MAX_TURNO);
	return (this->turnos= cantidadDeTurnos);
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
