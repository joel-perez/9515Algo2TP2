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
	unsigned int multiplicadorAgua;

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
	/*
	 *
	 *
	 */
	unsigned int obtenerDificultad();
	/*
	 *
	 *
	 */
	unsigned int obtenerMultiplicadorAgua();

private:
	/*
	 *
	 * POST: elige el multiplicador segun la dificultad
	 */
	unsigned int elegirMultiplicador();

	//Agregar los metodos publicos necesarios...
};

#endif
