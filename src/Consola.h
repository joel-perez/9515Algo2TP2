#ifndef CONSOLA_H_
#define CONSOLA_H_

#include "Lista.h"
#include "Jugador.h"
#include "Archivo.h"
#include "Texto.h"

class Consola {
	Texto texto;

public:
	/*
	 * PRE:~
	 * POST:Recibe por teclado un numero entero valido.
	 */
	unsigned int solicitarIngresoNumerico(unsigned int minValor,
			unsigned int maxValor);

	/*
	 * PRE:~
	 * POST:imprime en pantalla un mensaje de bienvenida.
	 */
	void mostrarBienvenida();

	/*
	 * PRE:~
	 * POST: muestra por pantalla  la ficha tecnica del
	 * 		jugadorActual.
	 */
	void mostrarDatosDelTurno(Jugador* jugadorActual, unsigned int turnoActual);

	/*
	 * PRE:
	 * POST:
	 */
	void mostrarFin(Lista<Jugador*>* jugadores);

	/*
	 * PRE:
	 * POST:muestra el estado del terreno del
	 * 	jugadorActual.
	 */
	void mostrarTerrenos(Jugador* jugadorActual);

	/*
	 * PRE:~
	 * POST:imprime en pantalla un mensaje.
	 */
	void solicitarEnterParaSalir();

	/*
	 * PRE:~
	 * POST:Devuelve la cadena de caracteres.
	 */
	std::string SolicitarIngresoLineaTexto();

	/*
	 * POST: Limpia el buffer de ingreso.
	 */
	void LimpiarIngreso();

	/*
	 *
	 * POST: imprime por pantalla las acciones disponibles
	 * 		para el jugadorActual.
	 */
	void mostrarPosiblesAcciones();
	/*
	 *
	 * POST: imprime por pantalla la cantidad e terrenos que posee el
	 * 		jugadorActual, y debe elegir uno de ello para  dicha acción.
	 */
	void mostrarTerrenosParaAccionElegida();

	/*
	 * POST: Convierte un entero a String para poder mostrarlo en pantalla.
	 */
	/*std::string intToString(int number);*/

	/*
	 *POST; imprime la lista de cultivos disponiles
	 */
	void mostrarCultivosDisponibles(Lista<Cultivo*>* cultivos);
	/*
	 * POST: imprime la lista de destinos disponibles.
	 */
	void mostrarDestinosDisponibles(Grafo* destinos);

	/*
	 * POST: Imprime en pantalla la lista de almacenes indicada.
	 */
	void mostrarAlmacenesDisponibles(Lista<Almacen*>* almacenes);
	/*
	 * POTS: Imprime en pantalla la lista de cultivos del almacen indicado.
	 */
	void mostrarCultivosDisponiblesDeUnAlmacen(Almacen* almacen);


};

#endif
