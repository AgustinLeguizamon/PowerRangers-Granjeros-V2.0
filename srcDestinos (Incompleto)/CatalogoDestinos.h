/*
 * agendaEstelar.h
 *
 *  Created on: May 12, 2018
 *      Author: agustin
 */

#ifndef CATALOGODESTINOS_H_
#define CATALOGODESTINOS_H_

#include "Destino.h"
#include "Lista.h"

class CatalogoDestinos{

	public:

		/*
		 * post: devuelve el puntero a la clase Destino que tenga
		 * como atributo this->cultivo al (char cultivo)
		 */
		Destino* obtenerDestino(Lista <Destino*>* daniela, char cultivo);



};


#endif /* CATALOGODESTINOS_H_ */
