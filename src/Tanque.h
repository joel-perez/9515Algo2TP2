#ifndef TANQUE_H_
#define TANQUE_H_

class Tanque {
private:
	unsigned int capacidadMaxima;
	unsigned int aguaDisponible;

public:
	/*
	 * PRE:
	 * POST:
	 */
	Tanque();

	/*
	 *
	 * POST: Tanque listo para usar.
	 */
	Tanque(unsigned int alto, unsigned int ancho, unsigned int multiplicador);

	/*
	 *
	 * POST: devuelve la cantidad de agua que se almacena en el tanque.
	 */
	unsigned int obtenerAguaDisponible();
	/*
	 * PRE:
	 * POST: devuelve la capacidad maxima del tanque
	 */
	unsigned int obtenerCapacidadMaxima();
	/*
	 *
	 * POST: cambia el agua disponible en el tanque
	 * (iria mejor en aisgnarAguaDisponible pero estaba probando)
	 */
	void cambiarAguaDisponible(unsigned int aguaDelTurno);
	/*
	 *
	 * POST: aumenta la capacidad del tanque
	 */
	void aumentarCapacidad();

	/*
	 * PRE: la cantidad de agua debe ser mayor o igual a la que se desea usar
	 * POST: usa el agua disponible en el tanque. Si la cantidad disponible es menor a la que se desea usar no hace nada.
	 */
	void usarAguaDisponible(unsigned int cantidadUsada);

	/*
	 *
	 * POST: asigna el agua disponible para cada turno
	 */
	void asignarAguaDisponible();
	/*
	 *
	 * POST: devuelve un valor al azar segun las caras del dado.
	 */
	unsigned int tirarDado();

	/* esta lleno?
	 *
	 *
	 * true si supero y false si no
	 */
	bool superoCapacidadMaxima();

//TODO: Implementar los metodos que hagan falta...
};

#endif
