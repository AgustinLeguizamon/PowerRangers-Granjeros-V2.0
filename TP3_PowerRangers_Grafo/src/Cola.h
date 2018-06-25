/*
 * Cola.h
 *
 *  Created on: 23 jun. 2018
 *      Author: purrevil
 */

#ifndef COLA_H_
#define COLA_H_

#include "Nodo.h"

template<class T>

class Cola{

	private:

		Nodo<T>* primero;

		Nodo<T>* ultimo;

	public:

		Cola();

		void acolar(int prioridad, T dato);

		T desacolar();

		bool estaVacia();

		T obtenerFrente();

		~Cola();
	};

	template <class T> T Cola<T>::obtenerFrente(){

		return this->primero;

	}


	template <class T> Cola<T>::Cola(){

		this->primero = NULL;

		this->ultimo = NULL;
	}

	template<class T> void Cola<T>::acolar(int prioridad, T dato){

		Nodo<T>* nuevoNodo = new Nodo<T>(prioridad, dato);

		bool intercambio = false;

		if(estaVacia()){

			this->primero = nuevoNodo;

			this->ultimo = nuevoNodo;
		}

		else if(this->primero->obtenerPrioridad()>prioridad){

			nuevoNodo->cambiarSiguiente(this->primero);

			this->primero = nuevoNodo;

		}

		else if(this->ultimo->obtenerPrioridad() <= prioridad){

			this->ultimo->cambiarSiguiente(nuevoNodo);

			this->ultimo = nuevoNodo;
		}

		else{

			Nodo<T> * nodoActual = this->primero;

			while(nodoActual->obtenerSiguiente() != NULL && !intercambio){

				if((nodoActual->obtenerPrioridad() < prioridad) && (nodoActual->obtenerSiguiente()->obtenerPrioridad()> prioridad)){

					nuevoNodo->cambiarSiguiente(nodoActual->obtenerSiguiente());

					nodoActual->cambiarSiguiente(nuevoNodo);

					intercambio = true;
				}

				else{

					nodoActual = nodoActual->obtenerSiguiente();

				}
			}
		}
	}

	template<class T> bool Cola<T>::estaVacia(){

		return this->primero==NULL;
	}

	template<class T> T Cola<T>::desacolar(){

		T dato;

		Nodo<T>* nodoABorrar;

		if(!this->estaVacia()){

			nodoABorrar = this->primero;

			this->primero = nodoABorrar->obtenerSiguiente();

			dato = nodoABorrar->obtenerDato();

			delete nodoABorrar;

		}

		return dato;
	}

	template<class T> Cola<T>::~Cola(){

		Nodo<T>* nodoABorrar;

		while(!estaVacia()){

			nodoABorrar = this->primero;

			this->primero = nodoABorrar->obtenerSiguiente();

			delete nodoABorrar;
		}
	}



#endif /* COLA_H_ */
