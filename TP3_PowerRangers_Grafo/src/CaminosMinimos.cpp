/*
 * CaminosMinimos.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: agustin
 */


#include "CaminosMinimos.h"
//#include "HIIIIIP"


void CaminosMinimos::caminosMinimos(/*ojo que no es una lista, reemplazar por heap*/
		Lista<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia){


	while (!heap->estaVacia()){

		/****METODO DEL HEAP****////
		Arribo* almacenAProvincia = heap->quitarRaiz();

		//busca en la lista de adyacencia, la lista de arribos de almacen
		Lista<Arribo*>* arribosAlmacen = buscarEnListaDeAdyacenciaPorNombre(listaDeAdyacencia, "ALMACEN"); //el metodo busca la clase que tenga nombre ALMACEN

		//busca en la lista de adyacencia, la lista de arribos de la provincia que fue removida
		Lista<Arribo*>* arribosProvincia = buscarEnListaDeAdyacencia(listaDeAdyacencia, almacenAProvincia);

		//recorre la lista de arribos de la provincia removida
		arribosProvincia->iniciarCursor();

		while(arribosProvincia->avanzarCursor()){

			/*obtiene el arribo actual de la lista de arribos*/
			Arribo* provinciaAProvincia = arribosProvincia->obtenerCursor();

			/*busca la distancia desde almacen hasta la provincia actual
			en la lista de arribos de Almacen*/
			Arribo* candidatoAlmacenAProvincia = buscarEnListaDeArribos(arribosAlmacen, provinciaAProvincia);


			if (candidatoAlmacenAProvincia != NULL && elCosteDeLaSumaEsMenorAlCosteDirecto(almacenAProvincia,provinciaAProvincia, candidatoAlmacenAProvincia)){

				int nuevoCosto= almacenAProvincia->obtenerCosto() + provinciaAProvincia->obtenerCosto();

				/****METODO DE LA CLASE ARRIBO ******/
				candidatoAlmacenAProvincia->modificarCosto(nuevoCosto);

				/****METODO DEL HEAP******/
				heap->promover(candidatoAlmacenAProvincia);
				/**puede ser que la provincia ya no este en el heap, en este caso
				 * no pasa nada
				 */
			}

		}
	}

}


bool CaminosMinimos::elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia){

	int sumaAlmacenAProvinciayProvinciaAProvincia = almacenAProvincia->obtenerCosto() + provinciaAProvincia->obtenerCosto();

	int costeCandidatoAlmacenAProvincia = candidatoAlmacenAProvincia->obtenerCosto();

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


/*NOTA:son tres metodos de busqueda
 * la primera busca una lista de arribos en la lista de adyacencia
 * la segunda busca una lista de arribos en la lista de adyacencia por nombre string
 * la tercera busca un arribo en una lista de arribos*/


/*IMPORTANTE: el codigo actual obtiene las provincias de la lista de almacen
 * si el arribo no esta, devuelve NULL por lo cual nunca va a mejorar el coste
 * de aquellos que no aparezcan desde un principio.
 *
 * Ver de buscar el puntero en el heap y agregarlo a la lista de adyacencia,
 * si no s encuentra en el heap es porque ya salio, devuelve NULL
 * y te ahorras el hacer las cuentas
 *
 */
