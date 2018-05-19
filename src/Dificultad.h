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
	 * PRE:~
	 * POST:Dificultad lista para usar.
	 */
	Dificultad();

	/*
	 * PRE:  dificultadSeleccionada debe de estar en el
	 * 	intervalo de [1,3].
	 * POST: Dificultad lista para ser usada segun la dificultadSeleccionada.
	 */
	Dificultad(unsigned int dificultadSeleccionada);
	/*
	 * PRE:~
	 * POST:devuelve el coeficioenteCredito según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficienteCreditosAsignados();
	/*
	 * PRE:~
	 * POST:devuelve el CoeficienteTamanioTanqueo según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficienteTamanioTanque();
	/*
	 * PRE:~
	 * POST:devuelve el coeficioenteCreditoALmance según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficienteTamanioAlmacen();
	/*
	 * PRE:
	 * POST:devuelve el coeficioenteCantidadTurnos según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficienteCantidadTurnos();
	/*
	 * PRE:~
	 * POST:devuelve el coeficioentTamanioTerreno según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficienteTamanioTerreno();
	/*
	 * PRE:
	 * POST:devuelve el CoeficientePrecioCultivo según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficientePrecioCultivo();
	/*
	 * PRE:~
	 * POST:devuelve el CoeficientePrecioTerreno según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficientePrecioTerreno();
	/*
	 * PRE:
	 * POST:Devuelve el tipo de cultivo.
	 */

	TipoDificultad obtenerDificultad();
	/*
	 * PRE:
	 * POST:devuelve el CoeficienteMultiplicadorAgua según la dificultadSeleccionada.
	 */
	unsigned int obtenerCoeficienteMultiplicadorAgua();

private:
	/*
	 *PRE:~
	 * POST: elige el multiplicador segun la dificultad
	 */
	unsigned int elegirMultiplicador();

	//Agregar los metodos publicos necesarios...
};

#endif
