#include "Texto.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string Texto::pedirRuta(std::string obteneRuta){
	// Por ahora fijo, se debe preguntar el nombre del archivo....
	std::string ruta = obteneRuta;
	return ruta;
}

Lista<Cultivo*>* Texto::leerCultivo(){

	std::ifstream entrada;
	std::string rutaDeterminada = this->pedirRuta(RUTA_CULTIVO);
	entrada.open(rutaDeterminada.c_str());

	std::string linea;
	if (entrada.fail()){
		std::cout<<"Error al abrir el archivo"<<std::endl;
	}
	Lista<Cultivo*>* cultivosDisponibles = new Lista<Cultivo*>;

		while(getline(entrada,linea)){
			std::stringstream ss(linea);

			std::string nombreCultivo;
			getline(ss,nombreCultivo,',');

			int costo = 0, tiempoDeCrecimiento = 0, rentabilidad =0, tiempoDeRecuperacion = 0, consumoDeAgua= 0;
			char separador;

			ss>>costo >>separador;
			ss>>tiempoDeCrecimiento>>separador;
			ss>>rentabilidad>>separador;
			ss>>tiempoDeRecuperacion>>separador;
			ss>>consumoDeAgua>>separador;

			Cultivo* nuevoCultivo=new Cultivo(nombreCultivo, costo, tiempoDeCrecimiento, rentabilidad, tiempoDeRecuperacion,consumoDeAgua);
			cultivosDisponibles->agregar(nuevoCultivo);
		}

	entrada.close();
	return cultivosDisponibles;
}

Lista<Destino*>* Texto::leerDestino(){
	std::ifstream entrada;
	std::string rutaDeterminada = this->pedirRuta(RUTA_DESTINO);

	entrada.open(rutaDeterminada.c_str());
	if (entrada.fail()){
		std::cout<<"Fallo abirr el archivo"<<std::endl;
	}
	Lista<Destino*>* destinosDisponibles = new Lista<Destino*>;

	std::string linea;
	while(getline(entrada,linea)){
		std::stringstream ss(linea);

		std::string nombreDestino;
		getline(ss,nombreDestino,',');

		int km = 0, precio=0;
		char separador;
		std::string cultivoAceptado;

		Destino* nuevoDestino=new Destino(nombreDestino, km, precio, cultivoAceptado);
		destinosDisponibles->agregar(nuevoDestino);

	}

	entrada.close();
	return destinosDisponibles;
}
