#include <iostream>
#include "Cosecha.h"

Cosecha::Cosecha() {
	this->cultivos= new Lista<Cultivo*>;

}

Lista<Cultivo*>* Cosecha::obtenerCosecha(){
	return this->cultivos;
}
void Cosecha::agregarCultivoACosecha(Cultivo* cultivo){
	this->cultivos->agregar(cultivo);
}


Cultivo*Cosecha::obtenerUncultivoCosechado(unsigned int cultivoCosechadoElegido){
	return (this->cultivos->obtener(cultivoCosechadoElegido));
}
unsigned int Cosecha::obtenerCantidadDeCultivosEnUnaCosecha(){
		return(this->cultivos->contarElementos());
	}

Cosecha::~Cosecha(){
	std::cout << "Cosecha::~Cosecha()" << std::endl;
	this->cultivos->iniciarCursor();
	while(cultivos->avanzarCursor()){
		delete this->cultivos->obtenerCursor();
	}
	delete cultivos;
}
