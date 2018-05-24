#include "Cosecha.h"

Cosecha::Cosecha() {
	this->cultivos= new Lista<Cultivo*>;

}

Lista<Cultivo*>* Cosecha::obtenerCosecha(){
	return this->cultivos;
}

Cultivo*Cosecha::obtenerUncultivoCosechado(unsigned int cultivoCosechadoElegido){
	return (this->cultivos->obtener(cultivoCosechadoElegido));
}
unsigned int Cosecha::obtenerCantidadDeCultivosEnUnaCosecha(){
		return(this->cultivos->contarElementos());
	}

Cosecha::~Cosecha(){
	this->cultivos->iniciarCursor();
	while(cultivos->avanzarCursor()){
		delete this->cultivos->obtenerCursor();
	}
	delete cultivos;
}

//TODO: Implementar los metodos necesarios...
