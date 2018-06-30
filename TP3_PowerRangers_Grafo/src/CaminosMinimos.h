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
#include "Semilla.h"



class CaminosMinimos{

	private:

	Lista<Arribo*>* copiaDeListaDeArribosAlmacen;

	public:

	/*
	 * post: , remueve la raiz del heap y actualiza los costes
	 * de los arribos y devuelve la lista de arribo a almacen.
	 */

	Lista<Arribo*>* caminosMinimosSegunLaSemilla(Cola<Arribo*>* heap,
			Lista<Viaje*>* listaDeAdyacencia,Semilla* unaSemilla);

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

	Arribo* buscarEnListaDeArribos(Lista<Arribo*>* listaDeArribos,
			Arribo* unArribo, Semilla* unaSemilla);



	/*
	 * post: devuelve si el coste del candidatoAlmacenAProvincia proveniente
	 * de la lista de adyacencia fue actualizado
	 */

	bool CaminosMinimos::actualizarDatosListaAdyacencia(Arribo* almacenAProvincia,
			Arribo* provinciaAProvincia, Arribo* candidatoAlmacenAProvincia);


	/*
	 * devuelve si unArribo tiene como cultivo a unaSemilla
	 */

	bool elArriboTieneEstaSemilla(Semilla* unaSemilla,Arribo* unArribo);

};

#endif /* SRC_CAMINOSMINIMOS_H_ */
