#ifndef TEXTO_H_
#define TEXTO_H_

#include <string>
#include "Lista.h"
#include "Cultivo.h"
#include "Destino.h"
#include "Constantes.h"

class Texto {
public:
	/* PRE: La obteneRuta del archito txt debe de exitir .
	 * POST:Obtien la determinada ruta;
	 */
	std::string pedirRuta(std::string obteneRuta);

	/* PRE:~
	 * POST:Devuelve una nueva Lista con todos los Cultivos.
	 */
	Lista<Cultivo*>* leerCultivo();

	/* PRE:~
	 * POST:Devuelve una nueva Lista con todos los Destinos.
	 */
	Lista<Destino*>* leerDestino();
};

#endif

