#ifndef TERRENO_H_
#define TERRENO_H_

#include "Lista.h"
#include "Parcela.h"
#include "Dificultad.h"

class Terreno {
private:
	Lista<Parcela*>* parcelas;

public:
	/*
	 * post: Crea un Terreno con 0 terrenoFila y 0 parcelaColumna.
	 */
	Terreno();
	Terreno(const Terreno& terreno);

	//TODO: Implementar los metodos que sean necesarios...
};

#endif
