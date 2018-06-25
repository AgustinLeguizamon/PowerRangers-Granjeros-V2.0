/*
 * CaminosMinimo.h
 *
 *  Created on: Jun 24, 2018
 *      Author: agustin
 */

#ifndef SRC_CAMINOSMINIMOS_H_
#define SRC_CAMINOSMINIMOS_H_


#include "Viaje.h"
#include "Lista.h"



class CaminosMinimos{

	public:

	/*
	 * pre:
	 * post: recibe por parametro el heap con los costes de envio, remueve
	 * la raiz y actualiza la prioridad de heap.
	 */

	void caminosMinimos(Lista<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia);


	bool elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia);


	Lista<Arribo*>* buscarEnListaDeAdyacencia(Lista<Viaje*>* listaDeAdyacencia, Arribo* unArribo);

	Lista<Arribo*>* buscarEnListaDeAdyacenciaPorNombre(Lista<Viaje*>* listaDeAdyacencia, std::string nombreProvincia);

	Arribo* buscarEnListaDeArribos(Lista<Arribo*>* listaDeArribos, Arribo* unArribo);


};



#endif /* SRC_CAMINOSMINIMOS_H_ */
