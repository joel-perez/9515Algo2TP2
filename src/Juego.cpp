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

Lista<Cultivo*>* Juego::obtenerCultivos() {
	return this->cultivos;
}

Lista<Destino*>* Juego::obtenerDestinos() {
	return this->destinos;
}

Cultivo* Juego::obtenerCultivoPorNombre(string nombreCultivo) {
	Cultivo* resultado;
	this->cultivos->obtenerCursor();
	while (this->cultivos->avanzarCursor()) {
		Cultivo* cultivoEncontrado = this->cultivos->obtenerCursor();
		if (cultivoEncontrado->obtenerNombre() == nombreCultivo)
			resultado = cultivoEncontrado;
	}
	return resultado;
}
Dificultad Juego::obtenerDificultad() {
	return this->dificultad;
}

void Juego::administrarAguaDelTurno(Jugador* jugador) {
	Tanque* tanqueActual = jugador->obtenerTanque();
	tanqueActual->asignarAguaDisponible();
}

void Juego::solicitarAcciones(Jugador* jugador) {
	int accionSeleccionada = 0;
	unsigned int tanqueDeAgua = jugador->obtenerTanque()->obtenerAguaDisponible();
	unsigned int credito =jugador->obtenerCreditos();
	while (accionSeleccionada != ACCION_SIGUIENTE_TURNO) {
		consola.mostrarPosiblesAcciones();
		accionSeleccionada = consola.solicitarIngresoNumerico(1, 11);
		unsigned int tanqueDeAgua = jugador->obtenerTanque()->obtenerAguaDisponible();
		unsigned int credito =jugador->obtenerCreditos();
		ejecutarAccion(accionSeleccionada, jugador, credito,tanqueDeAgua);
	}
}

void Juego::ejecutarAccion(unsigned int accionSeleccionada, Jugador* jugador, unsigned int credito, unsigned int tanqueDeAgua) {
	switch (accionSeleccionada) {
	case ACCION_SEMBRAR:
		sembrarParcela(jugador);
		break;
	case ACCION_COSECHAR:
		//TODO: Implementar...
		break;
	case ACCION_REGAR:
		//TODO: Implementar...
		break;
	case ACCION_ENVIAR_A_DESTINO:
			break;
	case ACCION_COMPRAR_TERRENO:
		break;
	case ACCION_VENDER_TERRENO:
		break;
	case ACCION_COMPRAR_CAPACIDAD_TANQUE:
		break;
	case ACCION_COMPRAR_CAPACIDAD_ALMACEN:
		break;
	case ACCION_CAMBIAR_TERRENO:
		break;
	case ACCION_SIGUIENTE_TURNO:
		break;
	case ACCION_ABANDONAR:
		break;

		}
	//TODO: Implementar las demas acciones que hagan falta...
}

unsigned int Juego::sembrarParcela(Jugador* jugador){
	unsigned int creditoUtilizado=0;
	Lista<Terreno*>* terrenosJugadorActual= jugador->obtenerTerrenos();

	Lista<Parcela*>* terrenoActual= jugador->obtenerTerrenoActual()->seleccionarTerreno(terrenosJugadorActual);


	return (jugador->cambiarCredito(creditoUtilizado));

}



void Juego::procesarTurno(Jugador* jugador) {

}

void Juego::solicitarDatosIniciales() {
	solicitarTamanioTerreno(); //TODO: Ver si es sencillo usar un TDA Dimensiones, o devolver valores por referencia, etc.
	this->jugadores = solicitarJugadores();

	//TODO: Eliminar esto cuando termine las pruebas...
	this->jugadores->iniciarCursor();
	while (this->jugadores->avanzarCursor()) {
		Jugador* jugador = this->jugadores->obtenerCursor();
		cout << "Jugador: '" << jugador->obtenerNombre() << "'" << endl;
	}
	//

	this->turnos = solicitarCantidadTurnos();
	this->dificultad = solicitarDificultad();
}

Lista<Jugador*>* Juego::solicitarJugadores() {
	Lista<Jugador*>* resultado = new Lista<Jugador*>;
	unsigned int contador = 0;
	unsigned int cantidad;
	string nombre = "";
	cout << "Ingrese la CANTIDAD de jugadores: ";
	cantidad = consola.solicitarIngresoNumerico(1, CANTIDAD_MAXIMA_JUGADORES);
	consola.LimpiarIngreso();
	this->numeroDeJugadores = cantidad;
	do {
		cout << ">Ingrese el Nombre del JUGADOR -" << contador + 1 << "- :";
		nombre = consola.SolicitarIngresoLineaTexto();
		Jugador* nuevoJugador = new Jugador(nombre);
		Terreno* nuevoTerreno = new Terreno(altoTerreno, anchoTerreno);
		nuevoJugador->agregarTerreno(nuevoTerreno);
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
	cout << "[el minimo es " << TERRENO_MIN_FILAS << "]" << endl;
	cout << "[el maximo es " << TERRENO_MAX_FILAS << "]" << endl;
	cout << ">Filas:";
	this->altoTerreno = consola.solicitarIngresoNumerico(TERRENO_MIN_FILAS,
			TERRENO_MAX_FILAS);
	cout << ">columnas:";
	this->anchoTerreno = consola.solicitarIngresoNumerico(TERRENO_MIN_FILAS,
			TERRENO_MAX_FILAS);
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
	this->cultivos = archivo.leerCultivos();
	this->destinos = archivo.leerDestinos();

	//TODO: Eliminar esto cuando terminemos las pruebas...
	cout << "Cultivos Cargados desde Archivo:" << endl;
	this->cultivos->iniciarCursor();
	while (this->cultivos->avanzarCursor()) {
		Cultivo* cultivo = this->cultivos->obtenerCursor();
		cout << "Cultivo: " << cultivo->obtenerNombre() << endl;
	}
	cout << endl;
	cout << "Destinos Cargados desde Archivo:" << endl;
	this->destinos->iniciarCursor();
	while (this->destinos->avanzarCursor()) {
		Destino* destino = this->destinos->obtenerCursor();
		cout << "Destino: " << destino->obtenerNombre() << endl;
	}
	//
}

void Juego::mostrarTerrenos(Jugador* jugadorActual) {
	consola.mostrarTerrenos(jugadorActual);
	imagen.mostrarTerrenos(jugadorActual);
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
			consola.mostrarDatosDelTurno(jugadorActual, turnoActual);
			mostrarTerrenos(jugadorActual);
			administrarAguaDelTurno(jugadorActual);
			solicitarAcciones(jugadorActual);
			procesarTurno(jugadorActual);
			//
		}
		turnoActual++;
	}
	consola.mostrarFin(jugadores);
}

Juego::~Juego() {
//TODO: Eliminar jugadores, cultivos y destinos...
	this->obtenerJugadores()->~Lista();
	this->obtenerCultivos()->~Lista();
	this->obtenerDestinos()->~Lista();
}
