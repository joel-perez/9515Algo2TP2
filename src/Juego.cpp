#include <iostream>
#include <string>

#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = NULL;
	this->cultivos = NULL;
	this->destinos = NULL;
	this->dificultad = Dificultad(1);
	this->turnos = 0;
	this->turnoActual = 1;
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
unsigned int Juego::obtenerAnchoTerreno() {
	return this->anchoTerreno;
}
unsigned int Juego::obtenerAltoTerreno() {
	return this->altoTerreno;
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

	while (accionSeleccionada != ACCION_SIGUIENTE_TURNO
			&& accionSeleccionada != ACCION_ABANDONAR) {
		consola.mostrarPosiblesAcciones();
		accionSeleccionada = consola.solicitarIngresoNumerico(1, 11);
		ejecutarAccion(accionSeleccionada, jugador);
	}
	if (accionSeleccionada == ACCION_ABANDONAR)
		jugador->abandonarJuego();
}

void Juego::ejecutarAccion(unsigned int accionSeleccionada, Jugador* jugador) {
	switch (accionSeleccionada) {
	case ACCION_SEMBRAR:
		sembrarParcela(jugador);
		break;
	case ACCION_COSECHAR:
		cosecharParcela(jugador);
		break;
	case ACCION_REGAR:
		regarParcela(jugador);
		break;
	case ACCION_ENVIAR_A_DESTINO:
		enviarCosechaADestino(jugador);
		break;
	case ACCION_COMPRAR_TERRENO:
		comprarTerreno(jugador);
		break;
	case ACCION_VENDER_TERRENO:
		venderTerreno(jugador);
		break;
	case ACCION_COMPRAR_CAPACIDAD_TANQUE:
		comprarCapacidadTanque(jugador);
		break;
	case ACCION_COMPRAR_CAPACIDAD_ALMACEN:
		comprarAlmacen(jugador);
		break;
	case ACCION_CAMBIAR_TERRENO:
		solicitarCambioTerreno(jugador);
		break;
	}
}

void Juego::comprarCapacidadTanque(Jugador* jugador) {
	jugador->obtenerTanque()->aumentarCapacidad();
	//TODO: FALTA RESTAR CREDITOS...
}

void Juego::comprarTerreno(Jugador* jugador) {
	//TODO: Implementar...
}

void Juego::venderTerreno(Jugador* jugador) {
	//TODO: Implementar...
}

void Juego::solicitarCambioTerreno(Jugador* jugador) {
	unsigned int indiceTerrenoSeleccionado = 1;
	unsigned int cantidadTerrenosDelJugador =
			jugador->obtenerTerrenos()->contarElementos();
	if (cantidadTerrenosDelJugador == 0) {
		cout << "Usted no tiene terrenos. Debe comprar uno primero." << endl;
	} else if (cantidadTerrenosDelJugador == 1) {
		cout << "Tiene un solo terreno" << endl;
	} else {
		indiceTerrenoSeleccionado = solicitarSeleccionarTerreno(jugador);
	}
	jugador->cambiarTerrenoActual(indiceTerrenoSeleccionado);
}

unsigned int Juego::solicitarSeleccionarTerreno(Jugador* jugador) {
	unsigned int cantidadTerrenosDelJugador =
			jugador->obtenerTerrenos()->contarElementos();
	cout << "Tiene " << cantidadTerrenosDelJugador << " Terrenos." << endl;
	cout << "Seleccione el terreno con el cual desea trabajar (del " << 1
			<< " al " << cantidadTerrenosDelJugador << "):" << endl;
	return consola.solicitarIngresoNumerico(1, cantidadTerrenosDelJugador);

}

void Juego::comprarAlmacen(Jugador* jugador) {
	Almacen* nuevoAlmacen = new Almacen(
			this->obtenerDificultad().obtenerCoeficienteTamanioAlmacen(),
			this->obtenerAltoTerreno(), this->obtenerAnchoTerreno());
	jugador->obtenerAlmacenes()->agregar(nuevoAlmacen);
//ELIMINAR ESTO LUEGO DE LA PRUEBA
	cout << "Ahora hay " << jugador->obtenerAlmacenes()->contarElementos()
			<< " almacenes" << endl;
//FALTA RESTAR CREDITO
}

Parcela* Juego::seleccionarParcela(Terreno* terreno) {
	cout << "Seleccione una Parcela:" << endl;
	cout << "Ingrese Fila: ";
	int fila = consola.solicitarIngresoNumerico(1, terreno->obtenerFilas());
	cout << "Ingrese Columna: ";
	int columna = consola.solicitarIngresoNumerico(1,
			terreno->obtenerColumnas());
	cout << "Ha seleccionado la Parcela(" << fila << ", " << columna << ")"
			<< endl;
	return terreno->obtenerParcela(fila, columna);
}

int Juego::regarParcela(Jugador* jugador) {
	int aguaUtilizada = 0;
	Parcela* parcelaActual = seleccionarParcela(
			jugador->obtenerTerrenoActual());
	if (parcelaActual->estaOcupada()) {
		if (!parcelaActual->yaEstaRegada()) {
			if (jugador->obtenerTanque()->obtenerAguaDisponible() > 0) {
				parcelaActual->regar();
				aguaUtilizada =
						parcelaActual->obtenerCultivo()->obtenerConsumoDeAgua();
				cout << "La parcela ha sido regada." << endl;
			} else {
				cout << "No hay suficiente agua para regar la parcela." << endl;
			}
		} else {
			cout << "No hace falta regar la parcela, ya estaba regada." << endl;
		}
	} else {
		cout << "Solo se pueden regar parcelas con cultivo." << endl;
	}
	return aguaUtilizada;
}

void Juego::cosecharParcela(Jugador* jugador) {
	Parcela* parcelaActual = this->seleccionarParcela(
			jugador->obtenerTerrenoActual());
	Cultivo* cultivoSelcionado = parcelaActual->obtenerCultivo();
	cultivoSelcionado->obtenerNombre();
	if (parcelaActual->estaOcupada()) {
		if (cultivoSelcionado->obtenerTiempoHastaCosecha() == 0
				&& cultivoSelcionado->obtenerNombre()
						!= PARCELA_EN_RECUPERACION) {
			if (cultivoSelcionado->obtenerNombre() != CULTIVO_PODRIDO
					&& cultivoSelcionado->obtenerNombre() != CULTIVO_SECO) {
				parcelaActual->cosechar(cultivoSelcionado);

			} else {
				cout
						<< "Solo se puede cosechar parcelas que no esten podridas o secas."
						<< endl;
			}

		} else {
			cout
					<< "Solo se pueden cosechar parcelas a tiempo de ser cosechadas."
					<< endl;
		}

	} else {
		cout << "Solo se pueden cosechar parcelas con cultivo." << endl;
	}

}

void Juego::enviarCosechaADestino(Jugador* jugador) {
//TODO: Implementar...
}

Cultivo* Juego::seleccionarCultivo() {
	consola.mostrarCultivosDisponibles(this->obtenerCultivos());
	unsigned int opcionSeleccionada = consola.solicitarIngresoNumerico(1,
			cultivos->contarElementos());
	return cultivos->obtener(opcionSeleccionada);
}

void Juego::sembrarParcela(Jugador* jugador) {
	unsigned int creditoUtilizado = 0;
	Parcela* parcelaActual = seleccionarParcela(
			jugador->obtenerTerrenoActual());
	Cultivo* cultivoSeleccionado = seleccionarCultivo();
	creditoUtilizado = parcelaActual->sembrar(cultivoSeleccionado);
	jugador->restarCredito(creditoUtilizado);
}

void Juego::procesarTurno(Jugador* jugador) {
//TODO: JOEL se va a encargar de esto!! =)
}

void Juego::solicitarDatosIniciales() {
	solicitarTamanioTerreno();
	this->dificultad = solicitarDificultad();
	this->jugadores = solicitarJugadores(this->obtenerDificultad());
	this->turnos = solicitarCantidadTurnos();
}

Lista<Jugador*>* Juego::solicitarJugadores(Dificultad dificultad) {
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
		Jugador* nuevoJugador = new Jugador(nombre, dificultad, altoTerreno,
				anchoTerreno);
		Terreno* nuevoTerreno = new Terreno(altoTerreno, anchoTerreno);
		Almacen* nuevoAlmacen = new Almacen(
				dificultad.obtenerCoeficienteTamanioAlmacen(), altoTerreno,
				anchoTerreno);
		nuevoJugador->agregarTerreno(nuevoTerreno);
		nuevoJugador->agregarAlmacen(nuevoAlmacen);
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
}

void Juego::mostrarTerrenos(Jugador* jugadorActual) {
	consola.mostrarTerrenos(jugadorActual);
	imagen.mostrarTerrenos(jugadorActual, this->obtenerAnchoTerreno(),
			this->obtenerAltoTerreno(), this->turnoActual);
}

void Juego::iniciarJuego() {
	consola.mostrarBienvenida();
	cargarArchivos();
	solicitarDatosIniciales();
	while (turnoActual <= this->turnos) {
		jugadores->iniciarCursor();
		while (jugadores->avanzarCursor()) {
			Jugador* jugadorActual = jugadores->obtenerCursor();
			if (!jugadorActual->abandono()) {
				consola.mostrarDatosDelTurno(jugadorActual, turnoActual);
				mostrarTerrenos(jugadorActual);
				administrarAguaDelTurno(jugadorActual);
				solicitarAcciones(jugadorActual);
			}
			procesarTurno(jugadorActual);
		}
		turnoActual++;
	}
	consola.mostrarFin(jugadores);
}

Juego::~Juego() {
//TODO: Eliminar jugadores, cultivos y destinos...

//this->obtenerJugadores()->~Lista();
//this->obtenerCultivos()->~Lista();
//this->obtenerDestinos()->~Lista();

	this->jugadores->iniciarCursor();
	while (jugadores->avanzarCursor()) {
		delete this->jugadores->obtenerCursor();
	}
	this->cultivos->iniciarCursor();
	while (cultivos->avanzarCursor()) {
		delete this->cultivos->obtenerCursor();
	}

	this->destinos->iniciarCursor();
	while (destinos->avanzarCursor()) {
		delete this->destinos->obtenerCursor();
	}
	delete jugadores;
	delete cultivos;
	delete destinos;
}
