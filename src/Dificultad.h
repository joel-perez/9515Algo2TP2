#ifndef DIFICULTAD_H_
#define DIFICULTAD_H_
enum TipoDificultad {
	FACIL, INTERMEDIO, DIFICIL
};

class Dificultad {
private:
	TipoDificultad dificultadSeleccionada;
	unsigned int coeficienteCreditosAsignados;
	unsigned int coeficienteTamanioTanque;
	unsigned int coeficienteTamanioAlmacen;
	unsigned int coeficienteCantidadturnos;
	unsigned int coeficienteTamanioTerreno;
	unsigned int coeficientePrecioCultivo;
	unsigned int coeficientePrecioTerreno;
	unsigned int coeficienteMultiplicadorAgua;

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

	unsigned int obtenerCoeficienteCreditosAsignados();
	unsigned int obtenerCoeficienteTamanioTanque();
	unsigned int obtenerCoeficienteTamanioAlmacen();
	unsigned int obtenerCoeficienteCantidadTurnos();
	unsigned int obtenerCoeficienteTamanioTerreno();
	unsigned int obtenerCoeficientePrecioCultivo();
	unsigned int obtenerCoeficientePrecioTerreno();

	TipoDificultad obtenerDificultad();

	/*
	 *
	 *
	 */
	unsigned int obtenerCoeficienteMultiplicadorAgua();

private:
	/*
	 *
	 * POST: elige el multiplicador segun la dificultad
	 */
	unsigned int elegirMultiplicador();

	//Agregar los metodos publicos necesarios...
};

#endif
