#include <iostream>
#include <string>

#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->jugadores = NULL;
	this->cultivos = NULL;
	this->dificultad = Dificultad(1);
	this->destinos=NULL;
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

Grafo* Juego::obtenerDestinos() {
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
	jugador->restarCredito(
			PRECIO_BASE_TANQUE
					* this->dificultad.obtenerCoeficientePrecioTanque());
}

void Juego::comprarTerreno(Jugador* jugador) {
	Terreno* nuevoTerreno = new Terreno(this->obtenerAnchoTerreno(),
			this->obtenerAltoTerreno());
	nuevoTerreno->asignarPrecio(dificultad);
	jugador->obtenerTerrenos()->agregar(nuevoTerreno);
	jugador->restarCredito(
			nuevoTerreno->obtenerPrecio()
					* jugador->obtenerTerrenos()->contarElementos()
					* PROPORCIONAL_COMPRA_TERRENO);
}

void Juego::venderTerreno(Jugador* jugador) {
	if (jugador->obtenerTerrenos()->contarElementos() > 0) {
		cout << "Ingrese que numero de terreno desea vender: " << endl;
		unsigned int posicion = consola.solicitarIngresoNumerico(1,
				jugador->obtenerTerrenos()->contarElementos());
		jugador->agregarCredito(
				jugador->obtenerTerrenos()->obtener(posicion)->obtenerPrecio()
						* PROPORCIONAL_VENTA_TERRENO);
		jugador->obtenerTerrenos()->remover(posicion);
	} else {
		cout << "No posee terrenos para vender." << endl;
	}
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
				jugador->obtenerTanque()->usarAguaDisponible(aguaUtilizada);
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
	if (parcelaActual->estaOcupada()) {
		Cultivo* cultivoSeleccionado = parcelaActual->obtenerCultivo();
		Almacen* almacenSeleccionado = seleccionarAlmacen(jugador);
		if (cultivoSeleccionado->obtenerTiempoHastaCosecha() == 0
				&& cultivoSeleccionado->obtenerNombre()
						!= PARCELA_EN_RECUPERACION) {
			if (cultivoSeleccionado->obtenerNombre() != PARCELA_PODRIDA
					&& cultivoSeleccionado->obtenerNombre() != PARCELA_SECA) {
				parcelaActual->cosechar(almacenSeleccionado);
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
	/*Almacen* almacenSeleccionado = this->seleccionarAlmacen(jugador);

	consola.mostrarCultivosDisponiblesDeUnAlmacen(almacenSeleccionado);
	unsigned int posicionCultivo = consola.solicitarIngresoNumerico(1,
			almacenSeleccionado->obtenerCultivos()->contarElementos());
	consola.mostrarDestinosDisponibles(this->obtenerDestinos());
	unsigned int posicionDestino = consola.solicitarIngresoNumerico(1,
			this->obtenerDestinos()->contarElementos());

	Destino* destinoSeleccionado = this->obtenerDestinos()->obtener(
			posicionDestino);
	Cultivo* cultivoSeleccionado = almacenSeleccionado->obtenerUnCultivo(
			posicionCultivo);

	if (destinoSeleccionado->obtenerCultivoQueAcepta().obtenerNombre()
			== cultivoSeleccionado->obtenerNombre()) {
		if (jugador->obtenerCreditos()
				>= destinoSeleccionado->obtenerCostoDeEnvioFinal()) {
			jugador->restarCredito(
					destinoSeleccionado->obtenerCostoDeEnvioFinal());
			jugador->agregarCredito(cultivoSeleccionado->obtenerRentabilidad()); //TODO: solo la rentabilidad del txt?
			almacenSeleccionado->enviarCultivos(posicionCultivo);
		} else {
			cout << "No posee suficiente credito para realizar este envio"
					<< endl;
		}

	} else {
		cout << "Este destino no acepta el cultivo seleccionado." << endl;
	}*/
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

void Juego::procesarTurnoJugador(Jugador* jugador) {
	Lista<Terreno*>* terrenos = jugador->obtenerTerrenos();
	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		procesarTurnoTerreno(terrenos->obtenerCursor());
	}
}

void Juego::procesarTurnoTerreno(Terreno* terreno) {
	Lista<Parcela*>* parcelas = terreno->obtenerParcelas();
	parcelas->iniciarCursor();
	while (parcelas->avanzarCursor()) {
		parcelas->obtenerCursor()->procesarTurno();
	}
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
		nuevoTerreno->asignarPrecio(dificultad);
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

Almacen* Juego::seleccionarAlmacen(Jugador* jugador) {
	Lista<Almacen*>* almacenes = jugador->obtenerAlmacenes();
	consola.mostrarAlmacenesDisponibles(almacenes);
	unsigned int opcionSeleccionada = consola.solicitarIngresoNumerico(1,
			almacenes->contarElementos());
	return almacenes->obtener(opcionSeleccionada);
}

void Juego::cargarArchivos() {
	//this->cultivos = archivo.leerCultivos();
	this->destinos = archivo.leerDestinos();
	this->destinos->mostrarListaAdyacencia();
}

void Juego::mostrarTerrenos(Jugador* jugadorActual) {
	consola.mostrarTerrenos(jugadorActual);
	imagen.mostrarTerrenos(jugadorActual, this->obtenerAnchoTerreno(),
			this->obtenerAltoTerreno(), this->turnoActual);
}

void Juego::mostrarTerrenosFinales(Lista<Jugador*>* jugadores) {
	jugadores->iniciarCursor();
	while (jugadores->avanzarCursor()) {
		Jugador* jugador = jugadores->obtenerCursor();
		cout << "Jugador: " << jugador->obtenerNombre() << endl << endl;
		mostrarTerrenos(jugador);
	}
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
			procesarTurnoJugador(jugadorActual);
		}
		turnoActual++;
	}
	mostrarTerrenosFinales(jugadores);
	consola.mostrarFin(jugadores);
}

Juego::~Juego() {

	this->jugadores->iniciarCursor();
	while (jugadores->avanzarCursor()) {
		Jugador* jugador = this->jugadores->obtenerCursor();
		delete jugador;
	}

	this->cultivos->iniciarCursor();
	while (cultivos->avanzarCursor()) {
		Cultivo* cultivo = this->cultivos->obtenerCursor();
		delete cultivo;
	}

	delete jugadores;
	delete cultivos;
	delete destinos;
}
