/*
 * parcela.h
 *
 *  Created on: 28 abr. 2018
 *      Author: gabriela
 */

#ifndef PARCELA_H_
#define PARCELA_H_

const char PARCELA_LIBRE='#';
const char CULTIVO_PERDIDO_RECUPERADO='X';
const char CULTIVO_A= 'A';
const char CULTIVO_B= 'B';
const char CULTIVO_C= 'C';

/*
 *
 * Una PARCELA/PARCELAS es un cubiculo donde se puede almacenar algun  cultivo.
 *
 */

class Casilla {

	private:

		char cultivo;
		char estado;

	public:
		/*
		 * post: Parcela vacia y sin cultivo.
		 */
		Parcela();

		/*
		 * post: Informa si la parcela esta ocupada o no.
		 */
		bool estaOcupada();

}

#endif /* PARCELA_H_ */
