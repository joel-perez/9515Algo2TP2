#ifndef ENVIO_H_
#define ENVIO_H_
#include<iostream>
#include <string>

class Envio{
private:
	std::string nombreCultivo;
	unsigned int precioEnvio;

public:
	/*
	 *
	 */
	Envio(std::string nombreCultivo, unsigned int precioEnvio);
	/*
	 *
	 */
	unsigned int obtenerPrecioEnvio();
	/*
	 *
	 */
	std::string obtenerNombreCultivo();
	/*
	 *
	 */
	void cambiarPrecio(unsigned int precio);
	/*
	 *
	 */
	void cambiarNombreCultivo(std::string nombre);
};



#endif /* ENVIO_H_ */
