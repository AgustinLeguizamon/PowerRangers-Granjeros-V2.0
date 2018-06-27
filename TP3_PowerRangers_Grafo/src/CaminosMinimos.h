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
#include "Cola.h"




class CaminosMinimos{

	private:

	Lista<Arribo*>* copiaDeListaDeArribosAlmacen;

	public:

	/*
	 * post: recibe por parametro el heap con los costes de envio, y la lista
	 * de adyacencia, remueve la raiz del heap y actualiza los costes
	 * de los arribos y devuelve la lista de arribo a almacen.
	 */

	Lista<Arribo*>* caminosMinimos(Cola<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia);

	/*
	 * post: devuelve si la suma del coste de los dos primeros parametros es menor
	 * al coste del tercer parametro
	 */

	bool elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia);

	/*
	 *post: busca en la lista de adyacencia un puntero a un arribo
	 * pasado por parametro y lo devuelve.
	 */

	Lista<Arribo*>* buscarEnListaDeAdyacencia(Lista<Viaje*>* listaDeAdyacencia,
												Arribo* unArribo);

	/*
	 * post: busca en la lista de adyacencia un puntero a un arribo,
	 * utilizando el nombre del arribo como criterio de busqueda y lo devuelve
	 */

	Lista<Arribo*>* buscarEnListaDeAdyacenciaPorNombre(Lista<Viaje*>* listaDeAdyacencia, std::string nombreProvincia);

	/*
	 * post: busca en la lista de arribos un puntero a un arribo y lo devuelve
	 */

	Arribo* buscarEnListaDeArribos(Lista<Arribo*>* listaDeArribos, Arribo* unArribo);



};



#endif /* SRC_CAMINOSMINIMOS_H_ */
