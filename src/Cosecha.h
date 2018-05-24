#ifndef COSECHA_H_
#define COSECHA_H_
#include "Lista.h"
#include "Cultivo.h"
/*
 * Una Cosecha  es una entidad que recoge los frutos que produce mi terreno.
 *
 */
class Cosecha {
private:
	Lista<Cultivo*>* cultivos;


public:
	/*
	 * PRE:
	 * POST:cosecha lista para usar.
	 */
	Cosecha();
	/*
	 * PRE:
	 * POST:devuelve los cultivos de esa cosecha.
	 */

	Lista<Cultivo*>* obtenerCosecha();
	/////////////////////////////////////////
	/*
	 * PRE:~
	 * POST:devuelve el cultivo indicada por cultivoCosechadoElegido.
	 */
	Cultivo* obtenerUncultivoCosechado(unsigned int cultivoCosechadoElegido);
	/*
	 * PRE:~
	 * POST:devuelve la cantidad de cultivos de esa cosecha.
	 */
	unsigned int obtenerCantidadDeCultivosEnUnaCosecha();

	~Cosecha();






};



#endif
