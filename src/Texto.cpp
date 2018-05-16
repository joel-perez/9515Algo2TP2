#include "Texto.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string Texto::pedirRuta(){
	std::string ruta = "cultivos.txt";
	return ruta;
}

void Texto::leerCultivo(Lista<Cultivo*>* cultivos){

	std::ifstream entrada;
	std::string rutaDeterminada = this->pedirRuta();
	entrada.open(rutaDeterminada.c_str());

	std::string linea;
	if (entrada.fail()){
		std::cout<<"Error al abrir el archivo"<<std::endl;
	}
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
			cultivos->agregar(nuevoCultivo);
		}

	entrada.close();
}
