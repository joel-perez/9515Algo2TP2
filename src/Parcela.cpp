#include <iostream>
#include "Parcela.h"

Parcela::Parcela() {
	this->estado=PARCELA_LIBRE;
}

Cultivo Parcela::obtenerCultivo() {
	return this->cultivo;
}
