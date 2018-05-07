#ifndef CULTIVO_H_
#define CULTIVO_H_

#include <string>

class Cultivo {
private:
	std::string nombre;
	float costo;
	unsigned int tiempoDeCrecimiento;
	unsigned int rentabilidad;
	unsigned int tiempoDeRecuperacion;
	unsigned int consumoDeAgua;

public:
	Cultivo();
};

#endif
