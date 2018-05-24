#include "Almacen.h"

Almacen::Almacen() {
	this->cosechas = new Lista<Cosecha*>;
	this->capacidadMaximaAlmacen = 1;
}

Almacen::Almacen(unsigned int coeficienteCapacidadAlmacen, unsigned int filas, unsigned int columnas){
	this->cosechas = new Lista<Cosecha*>;
	this->capacidadMaximaAlmacen = coeficienteCapacidadAlmacen * (filas + columnas);
}


unsigned int Almacen::obtenerCapacidadMaxima(){
	return this->capacidadMaximaAlmacen;
}

void Almacen::agregarCosechaAmiAlmacen(Cultivo* cultivo){

}

void Almacen::enviarCosechas(){

}
Lista<Cosecha*>* Almacen::obtenerCosechas(){
	return this->cosechas;
}

bool Almacen::estaLleno(){
	return (this->obtenerCosechas()->contarElementos() == this->obtenerCapacidadMaxima());
}
Almacen::~Almacen(){
	this->cosechas->iniciarCursor();
	while(this->cosechas->avanzarCursor()){
		delete this->cosechas->obtenerCursor();
	}
	this->cosechas->~Lista();
	delete cosechas;
}
//TODO: Implementar los metodos necesarios... 
