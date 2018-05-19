#include "Cosecha.h"

Cosecha::Cosecha() {
	this->cosechas= new Lista<Cultivo*>;

}

Lista<Cultivo*>* Cosecha::obtenerCosechas(){
	return this->cosechas;
}
//TODO: Implementar los metodos necesarios...
