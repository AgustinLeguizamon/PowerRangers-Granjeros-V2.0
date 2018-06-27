/*
 * CaminosMinimos.cpp
 *
 *  Created on: 27 jun. 2018
 *      Author: purrevil
 */

#include "CaminosMinimos.h"
#include "Cola.h"

Lista<Arribo*>* CaminosMinimos::caminosMinimos(Cola<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia){

	//busca en la lista de adyacencia, la lista de arribos de almacen
	Lista<Arribo*>* arribosAlmacen = buscarEnListaDeAdyacenciaPorNombre(listaDeAdyacencia, "ALMACEN");

	while (!heap->estaVacia()){

		/*Quita la raiz del heap y la guarda en almacenAProvincia*/
		Arribo* almacenAProvincia = heap->quitarRaiz();

		//busca en la lista de adyacencia, la lista de arribos de la provincia que fue removida
		Lista<Arribo*>* arribosProvincia = buscarEnListaDeAdyacencia(listaDeAdyacencia,
				almacenAProvincia);

		if(arribosProvincia != NULL){

			//recorre la lista de arribos de la provincia removida
			arribosProvincia->iniciarCursor();

			while(arribosProvincia->avanzarCursor()){

			/*obtiene el arribo actual de la lista de arribos*/
				Arribo* provinciaAProvincia = arribosProvincia->obtenerCursor();

			/*busca la distancia desde almacen hasta la provincia actual
			en la lista de arribos de Almacen*/
				Arribo* candidatoAlmacenAProvincia = buscarEnListaDeArribos(arribosAlmacen, provinciaAProvincia);


				if ( elCosteDeLaSumaEsMenorAlCosteDirecto(almacenAProvincia,
						provinciaAProvincia, candidatoAlmacenAProvincia)){

					unsigned int nuevoCosto= ((*almacenAProvincia->obtenerCosto()) + (*provinciaAProvincia->obtenerCosto()));

				/****METODO DE LA CLASE ARRIBO ******/
					candidatoAlmacenAProvincia->cambiarCosto(nuevoCosto);

				/****METODO DEL HEAP******/
					heap->promover(candidatoAlmacenAProvincia);
				/**puede ser que la provincia ya no este en el heap, en este caso
				 * no pasa nada
				 */
				}

			}

		}

	}

	return arribosAlmacen;
}



bool CaminosMinimos::elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia){

	unsigned int sumaAlmacenAProvinciayProvinciaAProvincia = (*almacenAProvincia->obtenerCosto()) + (*provinciaAProvincia->obtenerCosto());

	unsigned int costeCandidatoAlmacenAProvincia = (*candidatoAlmacenAProvincia->obtenerCosto());

	return (sumaAlmacenAProvinciayProvinciaAProvincia < costeCandidatoAlmacenAProvincia);

}


Lista<Arribo*>* CaminosMinimos::buscarEnListaDeAdyacencia(Lista<Viaje*>*
		listaDeAdyacencia, Arribo* unArribo){

	bool encontro=false;


	Lista<Arribo*>* arribos=NULL;
	/* si no tiene ningun arribo, no debería estar en la lista de adyacencia
	desde un principio*/

	listaDeAdyacencia->iniciarCursor();

	while(listaDeAdyacencia->avanzarCursor() && !encontro){

		Viaje* unViaje = listaDeAdyacencia->obtenerCursor();

		if(unViaje->obtenerSalidaDelViaje() == unArribo->obtenerArribo()){

			arribos = unViaje->obtenerArribos();
			encontro = true;

		}

	}

	return arribos;
}


Lista<Arribo*>* CaminosMinimos::buscarEnListaDeAdyacenciaPorNombre(Lista<Viaje*>* listaDeAdyacencia,
		std::string nombreProvincia){

	bool encontro=false;

	Lista<Arribo*>* arribos=NULL;
	/* si no tiene ningun arribo, no debería estar en la lista de adyacencia
	desde un principio*/

	listaDeAdyacencia->iniciarCursor();

	while(listaDeAdyacencia->avanzarCursor() && !encontro){

		Viaje* unViaje = listaDeAdyacencia->obtenerCursor();

		if(unViaje->obtenerSalidaDelViaje() == nombreProvincia){

			arribos = unViaje->obtenerArribos();
			encontro = true;

		}

	}

	return arribos;

}


Arribo* CaminosMinimos::buscarEnListaDeArribos(Lista<Arribo*>* listaDeArribos,
		Arribo* unArribo){

	bool encontro=false;


	Arribo* arribo=NULL;

	listaDeArribos->iniciarCursor();

	while(listaDeArribos->avanzarCursor() && !encontro){

		if(listaDeArribos->obtenerCursor()->obtenerArribo() == unArribo->obtenerArribo()){

			arribo = listaDeArribos->obtenerCursor();
			encontro = true;

		}

	}

	return arribo;

}




