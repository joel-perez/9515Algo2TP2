#ifndef DIFICULTAD_H_
#define DIFICULTAD_H_
enum Tipo{
	SIN_DIFICULTAD,
	FACIL,
	INTERMEDIO,
	DIFICIL
};

class Dificultad {
private:
	unsigned int turnos;
	unsigned int tamanioInicial;
	unsigned int dificultad;
	//Ver como contener los valores de las compras...

public:
	/*
	 * PRE:
	 * POST:
	 */
	Dificultad();

	/*
	 * PRE:
	 * POST:
	 */
	Dificultad(unsigned int dificultadSeleccionada);

	/*
	 * PRE:
	 * POST:
	 */
	unsigned int obtenerTurnos();

	unsigned int obtenerDificultad();

	//Agregar los metodos publicos necesarios...
};

#endif
