#ifndef PARCELA_H_
#define PARCELA_H_

#ifndef NULL
#define NULL 0
#endif

#include "Constantes.h"
#include "Cultivo.h"

/*
 *
 * Una PARCELA/PARCELAS es un cubiculo donde se puede almacenar algun  cultivo.
 *
 */
class Parcela {

private:
	Cultivo cultivo;
	char estado;

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
	 * POST:
	 */
	Cultivo obtenerCultivo();

//TODO: Implementar los metodos que sean necesarios...

};

#endif
