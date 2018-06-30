/*
 * CaminosMinimos.cpp
 *
 *  Created on: 27 jun. 2018
 *      Author: purrevil
 */

#include "CaminosMinimos.h"
#include "Cola.h"


Lista<Arribo*>* CaminosMinimos::caminosMinimosSegunLaSemilla(Cola<Arribo*>* heap,
		Lista<Viaje*>* listaDeAdyacencia,Semilla* unaSemilla){

	//busca en la lista de adyacencia, la lista de arribos de almacen
	Lista<Arribo*>* arribosAlmacen = buscarEnListaDeAdyacenciaPorNombre
			(listaDeAdyacencia, "ALMACEN");

	while (!heap->estaVacia()){

		/*Quita la raiz del heap y la guarda en almacenAProvincia*/
		Arribo* almacenAProvincia = heap->quitarRaiz();

		//busca en la lista de adyacencia, la lista de arribos de la provincia que fue removida
		Lista<Arribo*>* arribosProvincia = buscarEnListaDeAdyacencia
				(listaDeAdyacencia,almacenAProvincia);

		if(arribosProvincia != NULL){

			//recorre la lista de arribos de la provincia removida
			arribosProvincia->iniciarCursor();

			while(arribosProvincia->avanzarCursor()){

				/*obtiene el arribo actual de la lista de arribos*/
				Arribo* provinciaAProvincia = arribosProvincia->obtenerCursor();

				if(elArriboTieneEstaSemilla(unaSemilla,provinciaAProvincia)){

					/*busca el coste desde almacen hasta la provincia actual
					en la lista de arribos de Almacen*/
					Arribo* candidatoAlmacenAProvincia = buscarEnListaDeArribos(arribosAlmacen,
								provinciaAProvincia, unaSemilla);

					/*si mejoro el coste de la lista de candidatoAlmacenProvincia
					 * promueve el vertice en el heap*/
					if (actualizarDatosListaAdyacencia(almacenAProvincia,
							provinciaAProvincia, candidatoAlmacenAProvincia)){

						heap->promover(candidatoAlmacenAProvincia);

					}
				} //if
			}//while arribosProvincia
		}// if arribosProvincia
	}//while heap

	return arribosAlmacen;
}


/*******//*******/


bool CaminosMinimos::elCosteDeLaSumaEsMenorAlCosteDirecto(Arribo* almacenAProvincia,
		Arribo*provinciaAProvincia, Arribo* candidatoAlmacenAProvincia){

	/*suma los costos desde el almacen hasta la provincia y desde la provincia
	 * hasta la provincia canidata a mejorar*/
	unsigned int sumaAlmacenAProvinciayProvinciaAProvincia =
			(*almacenAProvincia->obtenerCosto()) +
			(*provinciaAProvincia->obtenerCosto());

	unsigned int costeCandidatoAlmacenAProvincia =
			(*candidatoAlmacenAProvincia->obtenerCosto());

	return (sumaAlmacenAProvinciayProvinciaAProvincia <
			costeCandidatoAlmacenAProvincia);

}



Lista<Arribo*>* CaminosMinimos::buscarEnListaDeAdyacencia(Lista<Viaje*>*
		listaDeAdyacencia, Arribo* unArribo){

	bool encontro=false;

	Lista<Arribo*>* arribos=NULL;

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
		Arribo* unArribo, Semilla* unaSemilla){

	bool encontro=false;


	Arribo* arriboADevolver=NULL;

	listaDeArribos->iniciarCursor();

	while(listaDeArribos->avanzarCursor() && !encontro){

		Arribo* unArriboDeLaLista = listaDeArribos->obtenerCursor();

		if( unArriboDeLaLista->obtenerCultivo() == unaSemilla &&
		unArriboDeLaLista->obtenerArribo() == unArribo->obtenerArribo()){

			arriboADevolver = unArriboDeLaLista;
			encontro = true;

		}

	}

	return arriboADevolver;

}



bool CaminosMinimos::actualizarDatosListaAdyacencia(Arribo* almacenAProvincia,
		Arribo* provinciaAProvincia, Arribo* candidatoAlmacenAProvincia){

	bool promover = false;

	if (elCosteDeLaSumaEsMenorAlCosteDirecto(almacenAProvincia,
			provinciaAProvincia, candidatoAlmacenAProvincia)){

		unsigned int nuevoCosto= ((*almacenAProvincia->obtenerCosto()) +
		(*provinciaAProvincia->obtenerCosto()));

		candidatoAlmacenAProvincia->cambiarCosto(nuevoCosto);

		candidatoAlmacenAProvincia->cambiarEscalas
		(almacenAProvincia->obtenerEscalas());

		candidatoAlmacenAProvincia->agregarEscala
		(almacenAProvincia->obtenerArribo());

		promover = true;

	}

	return promover;
}




bool CaminosMinimos::elArriboTieneEstaSemilla(Semilla* unaSemilla,
		Arribo* unArribo){

	return (unArribo->obtenerCultivo() == unaSemilla);

}



