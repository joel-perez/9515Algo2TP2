#ifndef PARCELA_H_
#define PARCELA_H_

#ifndef NULL
#define NULL 0
#endif

#include "Constantes.h"
#include "Cultivo.h"
#include "EstadoParcela.h"
#include "Almacen.h"

/*
 * Una PARCELA es un cubiculo donde se puede almacenar un cultivo.
 */
class Parcela {

private:
	EstadoParcela estadoParcela;
	Cultivo* cultivo;
	int tiempoHastaCosecha;
	int tiempoHastaRecuperacion;
	int rentabilidad;
	bool estaRegada;

public:
	/*
	 * PRE:
	 * POST: Parcela vacia y sin cultivo.
	 */
	Parcela();

	/*
	 * PRE:
	 * POST: Informa si la parcela esta ocupada o no.
	 */
	bool estaOcupada();

	/*
	 * PRE:
	 * POST:Deulve el cultivo actual.
	 */
	Cultivo* obtenerCultivo();

	/*
	 * PRE:
	 * POST:delvuele el estado .
	 */
	EstadoParcela obtenerEstado();

	/*
	 * PRE:
	 * POST:devuelve el nombre  del cultivo en la parcela.
	 */
	std::string obtenerNombre();

	/*
	 * PRE:~
	 * POST:Establece un nuevo cultivo en la parcela.
	 */
	void establecerCultivo(Cultivo* tipoCultivo);

	/*
	 * PRE:~
	 * POST:Riega la parcela, para que dure un turno mas.
	 */
	void regar();
	/*
	 * PRE:
	 * POST:Indica si la parcela ya esta regada.
	 */
	bool yaEstaRegada();

	/*
	 * PRE:
	 * POST:Devuelve la cantidad de creditos que se obtienen al cosechar esta parcela.
	 */
	unsigned int obtenerRentabilidad();

	/*
	 * PRE:
	 * POST:Devuelve la cantidad de turnos que faltan para poder cosechar esta parcela.
	 */
	unsigned int obtenerTiempoHastaCosecha();

	/*
	 * PRE:
	 * POST: Indica cuando credito es necesario para comprar semillas
	 * de un determinado cultivo.
	 */

	//unsigned int creditoRequeridoPara(TipoCultivo tipoCultivo);
	/*
	 * PRE:
	 * POST:Procesa las acciones realizadas por el jugador para establecer las
	 * condiciones iniciales del siguiente turno.
	 */
	void procesarTurno();

	/*
	 *POST:cambia el de la parcela para el siguiente turno.
	 */
	void procesarTurnoCultivoNormal();

	/*
	 *POST:cambia el estado de la parcela a Seco para el siguiente turno.
	 */
	void procesarTurnoCultivoSeco();

	/*
	 *POST:cambia el estado de la parcela a Podrido para el siguiente turno
	 */
	void procesarTurnoCultivoPodrido();

	/*
	 *POST: cambia el estado de la parcela a Recuperacione en el turno actual.
	 */
	void procesarTurnoCultivoEnRecuperacion();

	/*
	 * PRE:
	 * POST:Siembra el cultivo indicado en la parcela actual.
	 */
	unsigned int sembrar(Cultivo* &tipoCultivo);

	/*
	 * PRE:
	 * POST: Cosecha la parcela, dejando su estado en recuperacion, y guarda
	 *       el producto en el almacen indicado.
	 */
	void cosechar(Almacen* almacen);

	/*
	 * PRE:
	 * POST: Devuelve el estado de la parcela listo para mostrar en pantalla.
	 */
	std::string obtenerEstadoParaMostrarEnPantalla();

	/*
	 * POST: Libera los recursos utilizados.
	 */
	~Parcela();
};

#endif
