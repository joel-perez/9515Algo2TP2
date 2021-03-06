#ifndef JUEGO_H_
#define JUEGO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Cultivo.h"
#include "Dificultad.h"
#include "Consola.h"
#include "Constantes.h"
#include "Archivo.h"
#include "Terreno.h"
#include "Imagen.h"
#include "Grafo.h"
#include "Texto.h"

class Juego {
private:
	Lista<Jugador*>* jugadores;
	Lista<Cultivo*>* cultivos;
	Grafo* recorridos;
	Dificultad dificultad;
	unsigned int altoTerreno;
	unsigned int anchoTerreno;
	unsigned int turnos;
	unsigned int turnoActual;
	Consola* consola;
	Imagen imagen;
	Archivo* archivo;
	Texto texto;
	unsigned int numeroDeJugadores;

public:
	/*
	 * post: Juego listo para jugar una partida.
	 */
	Juego();

	/*
	 * PRE:
	 * POST:carga los datos asociados para el arranque de Juego
	 */
	void iniciarJuego();

	/*
	 * PRE:~
	 * POST:se obtiene los jugadores de la partida.
	 */
	Lista<Jugador*>* obtenerJugadores();

	/*
	 *
	 * POST: se obtiene los cultivos de la partida.
	 */
	Lista<Cultivo*>* obtenerCultivos();

	/*
	 * POST: Devuelve la lista de destinos que se cargo desde un archivo->
	 */
	Grafo* obtenerRecorridos();
	/*
	 * POST: devuelve la cantidad de columnas en el terreno
	 */
	unsigned int obtenerAnchoTerreno();
	/*
	 * POST: devuelve la cantidad de filas del terreno
	 */
	unsigned int obtenerAltoTerreno();

	/*
	 * PRE:
	 * POST:
	 */
	Cultivo* obtenerCultivoPorNombre(std::string nombreCultivo);

	void mostrarTerrenos(Jugador* jugador);

	/*
	 * PRE:~
	 * POST:Acumula el agua recibida con la que hay en el tanque, si
	 * supera un cierto limite, el sobrante se pierde quedando el tanque
	 *  lleno hasta el maximo.
	 */
	void administrarAguaDelTurno(Jugador* jugador);

	/*
	 * PRE:~
	 * POST:Solicita al jugador que realice una o mas acciones
	 * dentro del turnoActual.
	 */
	void solicitarAcciones(Jugador* jugador);

	/*
	 * PRE:~
	 * POST:Realiza las operaciones correspondientes al avance de un turno luego
	 * de que el jugador haya realizado las acciones que considero necesarias.
	 */
	void procesarTurnoJugador(Jugador* jugador);

	/*
	 * PRE:
	 * POST:
	 */
	void procesarTurnoTerreno(Terreno* terreno);

	/*
	 * PRE:
	 * POST: Solicita al usuario los datos con los cuales se va a iniciar el juego.
	 */
	void solicitarDatosIniciales();

	/*
	 * PRE: Los archivos deben de existir.
	 * POST: obtengo a "cultivos" cargado.
	 */
	void cargarArchivos();

	/*
	 * PRE:~
	 * POST:el Juego tiene una cantidad de TURNOS definidos
	 */
	unsigned int solicitarCantidadTurnos();

	/*
	 * PRE: Se ingresa al menos un jugador.
	 * POST: Jugadore listos para jugar.
	 */
	Lista<Jugador*>* solicitarJugadores(Dificultad dificultad);

	/*
	 * PRE:~
	 * POST:Crea un Terreno dinamico de 'N' filas x 'M' columnas.
	 *     el usuario ingresa por teclado las FILAS y las COLUMNAS.
	 */
	void solicitarTamanioTerreno();

	/*
	 *PRE :
	 * 		 'FACIL' asigna los valores predeterminados a Dificultad;
	 * 		 'MEDIO' idem.
	 * 		 'DIFICIL' indem.
	 *POST: El juego tiene una Dificultad definida
	 * 		 EL USUARIO YA PUEDE COMENZAR A JUGAR.
	 */
	Dificultad solicitarDificultad();

	/*
	 * PRE:~
	 * POST:Solicita al jugador que realice una o mas acciones
	 *  	dentro del turnoActual.
	 */
	Dificultad obtenerDificultad();

	/*
	 * PRE:~
	 * POST:Realiza la accion solicitada por el jugadorActual.
	 */
	void ejecutarAccion(unsigned int accionSeleccionada, Jugador* jugador);

	/*
	 * POST:Siembra la parcela seleccionada con el cultivo indicado por el usuario,
	 * verificando que se tenga el suficiente credito y la parcela este en condiciones
	 * de ser sembrada.
	 */
	void sembrarParcela(Jugador* jugador);

	/*
	 * POST: Devuelve el cultivo seleccionado.
	 */
	Cultivo* seleccionarCultivo();
	/*
	 * PRE:Solicita al usuario que ingrese uno de los terrenos disponibles
	 * POST:
	 * y devuelve una referencia a ese terreno, si solo tiene un terreno
	 * devolvera ese terreno.
	 */
	Lista<Parcela*>* seleccionarTerreno(Lista<Terreno*>* terrenosJugadorActual);

	/*
	 * POST: Devuelve la parcela indicada por el usuario.
	 */
	Parcela* seleccionarParcela(Terreno* terreno);

	/*
	 * POST: Riega la parcela del jugador indicado.
	 */
	int regarParcela(Jugador* jugador);
	/*
	 *
	 * POST: agrega un nuevo almacen a la lista de almacenes ddel jugador y se restan los creditos
	 *       correspondientes
	 */
	void comprarAlmacen(Jugador* jugador);

	/*
	 *PRE:~
	 *
	 *POST: Cosecha la parcela seleccionada por el usuario, verificando que la parcela este
	 * en condiciones de ser cosechada.
	 *
	 */
	void cosecharParcela(Jugador* jugador);

	/*
	 *
	 */
	void enviarCosechaADestino(Jugador* jugador);

	/*
	 *
	 */
	void comprarTerreno(Jugador* jugador);

	/*
	 *
	 */
	void venderTerreno(Jugador* jugador);

	/*
	 * POST: Solicita al usuario que seleccione con cual terreno quiere trabajar y lo asigna
	 *       a la variable terrenoActual.
	 */
	void solicitarCambioTerreno(Jugador* jugador);

	/*
	 *
	 */
	void comprarCapacidadTanque(Jugador* jugador);

	/*
	 * POST: Solicita al usuario que seleccione un terreno y devuelve el indice de ese terreno
	 *       dentro de su lista de terrenos.
	 */
	unsigned int solicitarSeleccionarTerreno(Jugador* jugador);

	/*
	 * POST: Solicita al usuario que seleccione uno de sus almacenes.
	 */
	Almacen* seleccionarAlmacen(Jugador* jugador);

	/*
	 * POST: Muestra los terrenos de todos los jugadores pasados como parametro.
	 */
	void mostrarTerrenosFinales(Lista<Jugador*>* jugadores);

	/*
	 * POST: Libera la memoria que habia sido solicitada en el Heap.
	 */
	~Juego();

};

#endif
