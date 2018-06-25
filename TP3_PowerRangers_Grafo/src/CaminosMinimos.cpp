/*
 * CaminosMinimos.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: agustin
 */


#include "CaminosMinimos.h"
//#include "HIIIIIP"


void CaminosMinimos::caminosMinimos(Lista<Arribo*>* heap, Lista<Viaje*>* listaDeAdyacencia){

	while (!heap->estaVacia()){

		/****METODO DEL HEAP****////
		Arribo* almacenAProvincia = heap->removerRaiz();

		//busca en la lista de adyacencia, la lista de arribos de almacen
		Lista<Arribo*>* arribosAlmacen = buscarEnListaDeAdyacenciaPorNombre(listaDeAdyacencia, "ALMACEN"); //el metodo busca la clase que tenga nombre ALMACEN

		//busca en la lista de adyacencia, la lista de arribos de la provincia que fue removida
		Lista<Arribo*>* arribosProvincia = buscarEnListaDeAdyacencia(listaDeAdyacencia, almacenAProvincia);

		//recorre la lista de arribos de la provincia removida
		arribosProvincia->iniciarCursor();

		while(arribosProvincia->avanzarCursor()){

			//obtiene el primer arribo de la lista de arribos de la provincia de viajes
			Arribo* provinciaAProvincia = arribosProvincia->obtenerCursor();

			//busca la distancia desde almacen hasta la provincia actual de la lista arribos
			Arribo* candidatoAlmacenAProvincia = buscarEnListaDeArribos(arribosAlmacen, provinciaAProvincia);


			if (elCosteDeLaSumaEsMenorAlCosteDirecto(almacenAProvincia,provinciaAProvincia, candidatoAlmacenAProvincia)){

				int nuevoCosto= almacenAProvincia->obtenerCosto() + provinciaAProvincia->obtenerCosto();

				/****METODO DE LA CLASE ARRIBO ******/
				candidatoAlmacenAProvincia->modificarCosto(nuevoCosto);

				/****METODO DEL HEAP******/
				reordenarHeap();
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


	Lista<Arribo*> arribos=NULL;
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

	Lista<Arribo*> arribos=NULL;
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
	/* si no tiene ningun arribo, no debería estar en la lista de adyacencia
	desde un principio*/

	listaDeArribos->iniciarCursor();

	while(listaDeArribos->avanzarCursor() && !encontro){

		if(listaDeArribos->obtenerCursor()->obtenerArribo() == unArribo->obtenerArribo()){

			arribo = listaDeArribos->obtenerCursor();
			encontro = true;

		}

	}

	return arribo;

}


/*NOTA: como hago para no hacer tres metodos de busqueda para evitar repetir tanto codigo
 * la primera busca una lista de arribos en la lista de adyacencia
 * la segunda busca una lista de arribos en la lista de adyacencia por nombre string
 * la tercera busca un arribo en una lista de arribos*/
