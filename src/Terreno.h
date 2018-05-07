#ifndef TERRENO_H_
#define TERRENO_H_

#include "Lista.h"
#include "Parcela.h"

class Terreno {
private:
	Lista<Parcela> parcelas;

public:
	Terreno();
	Terreno(const Terreno& terreno);

	//TODO: Implementar los metodos que sean necesarios...
};

#endif
