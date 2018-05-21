/*
 * Lista.h
 *
 *  Created on: May 5, 2018
 *      Author: agustin
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"


template <class T> class Lista{

	private:

		Nodo<T>* primero;

		unsigned int tamanio;

		Nodo<T>* cursor;


	public:

		/*
		 * post: Lista vacía
		 */
		Lista();

		/*
		 * post: Lista que tiene los mismo elemento que otraLista.
		 * La instancia resulta en una copia de otraLista.
		 */

		Lista(Lista<T>& otraLista); //otraLista del tipo clase Lista con template

		/*
		 * post: indica si la Lista tiene algun elemento;
		 */

		bool estaVacia();


		/*
		 * post: devuelve la cantidad de elementos que tiene la Lista
		 */

		unsigned int contarElementos();

		/*
		 * post: agrega el elemento al final de la Lista, en la posicion
		 * contarElementos() + 1
		 */

		void agregar(T elemento);

		/*
		 * pre: posicion pertence al intervalo: [1...contarElementos()]
		 * post: agrega el elemento en la posicion indicada
		 */

		void agregar (T elemento, unsigned int posicion);



		/*
		 * post:agrega todos los elementos de otraLista a partir de la
		 * 		posicion contarELementos() + 1
		 */

		void agregar (Lista<T> &otraLista);


		/*
		 * pre: posicion pertenece al intervalo: [1...contarElementos()]
		 * post: devuelve el elemento en la posicion indicada
		 */

		T obtener (unsigned int posicion);

		/*
		 * pre: posicion pertenece al intervalo: [1...contarElementos()]
		 * post: cambia el elemento en la posicion indicada por el elemento dado.
		 */

		void asignar(T elemento, unsigned int posicion);

		/*
		 * pre: posicion pertenece al intervalo: [1...contarElementos()]
		 * post: remueve de la Lista el elemento en la posicion indicada
		 */

		void remover(unsigned int posicion);

		/*
		 * post: deja el cursor de la Lista preparado para hacer un nuevo
		 * recorrido sobre sus elementos
		 */

		void iniciarCursor();

		/*
		 * pre: se ha iniciado un recorrido (invocando el metodo inciarCUrsor())
		 * 		y desde entonces no se han agregado ni removido elementos
		 * 		de la Lista.
		 *
		 * post: mueve el cursor y lo posiciona en el siguiente elemento del recorrido
		 * 		 El valor de retorno indica si el cursor quedo posicionado
		 * 		 sobre un elemento o no ( en caso de que la Lista este vacia o
		 * 		 no existan mas elemento por recorrer.)
		 */

		bool avanzarCursor();

		/*
		 * pre: el cursor esta posicionado sobre un elemento de la Lista
		 * 		(fue invocado el metodo avanzarCursor()) y devolvio True.
		 * post: devuelve el elemento en la posicion del cursor.
		 */
		T obtenerCursor();

		/*
		 * post: libera los recursos asociados a la Lista.
		 */

		~Lista();


	private:

		/*
		 * pre: posicion pertenece al intervalo: [1...contarElementos()]
		 * post: devuelve el nodo en la posicion indicada
		 */

		Nodo<T>* obtenerNodo(unsigned int posicion); //Nota: primitiva privada

};

/*
 * Excepción que representa el intento de acceder a un elemento
 * que no existe dentro de la Lista
 *
 */

class ExcepcionElementoInexistente{

	private:

		unsigned int posicion;

	public:

		/*
		 * post: Excpeción creada a partir de la posicion invalida a la que
		 * se intennto acceder
		 */

		ExcepcionElementoInexistente(unsigned int posicion){

			this -> posicion = posicion;

		}

		/*
		 * post: devuelve la posicion invalida a la que se intento acceder
		 */

		unsigned int obtenerPosicionInvalida(){

			return this-> posicion;
		}

};



//Implementacion de las funciones

template <class T> Lista<T>::Lista(){

	this -> primero = NULL;

	this -> tamanio = 0;

	this -> cursor = NULL;
}

template <class T> Lista<T>::Lista(Lista<T>& otraLista){

	this -> primero = NULL;

	this -> tamanio = 0;

	this -> cursor = NULL;

	// copia los elelemntos de otraLista
	this ->agregar(otraLista);

}


template <class T> bool Lista<T>::estaVacia(){

	return (this -> tamanio == 0);

}


template <class T> unsigned int Lista<T>::contarElementos(){

	return(this-> tamanio);
}


template <class T> void Lista<T>::agregar(T elemento){

	this -> agregar(elemento, this -> tamanio +1);

}

template <class T> void Lista<T>::agregar(T elemento, unsigned int posicion){


	if ((posicion > 0) && (posicion <= this->tamanio+1)){

		Nodo<T>* nuevoNodo = new Nodo<T> (elemento);

		if (posicion == 1){

			nuevoNodo->cambiarSiguiente(this -> primero);
			this -> primero = nuevoNodo;

		}
		else{

			Nodo<T>* anterior = this->obtenerNodo(posicion-1);
			nuevoNodo->cambiarSiguiente(anterior ->obtenerSiguiente());
			anterior ->cambiarSiguiente(nuevoNodo);
		}

		this -> tamanio++;

		/* cualquier recorrido actual queda invalidado */
		this -> iniciarCursor();

	} else {

		throw ExcepcionElementoInexistente(posicion);
	}


}


template <class T> void Lista<T>::agregar(Lista<T>& otraLista){

	otraLista.iniciarCursor();

	while (otraLista.avanzarCursor()){
		this ->agregar(otraLista.obtenerCursor());
	}

}


template <class T> T Lista<T>::obtener(unsigned int posicion){

	T elemento;

	if (posicion > 0 && posicion <= this->contarElementos()){

		elemento = this -> obtenerNodo(posicion) ->obtenerDato();

	} else {

		throw ExcepcionElementoInexistente(posicion);
	}

	return elemento;
}


template <class T> void Lista<T>::asignar(T elemento, unsigned int posicion){

	if (posicion > 0 && posicion <= this->contarElementos()){

		this -> obtenerNodo(posicion) -> cambiarDato(elemento);

	} else {

		throw ExcepcionElementoInexistente(posicion);
	}


}


template <class T> void Lista<T>::remover(unsigned int posicion){

	if (posicion > 0 && posicion <= this->contarElementos()){

		Nodo<T>* nodoAntiguo;

		if (posicion == 1){

			nodoAntiguo = this -> primero;
			this -> primero = nodoAntiguo -> obtenerSiguiente();

		}

		else{

			Nodo<T>* nodoAnterior = this -> obtenerNodo(posicion -1);
			nodoAntiguo = nodoAnterior ->obtenerSiguiente();
			nodoAnterior ->cambiarSiguiente(nodoAntiguo->obtenerSiguiente());
		}


		delete nodoAntiguo;

		this -> tamanio--;

		/* cualquier recorrido actual queda invalidado*/

		this ->iniciarCursor();

	} else {

		throw ExcepcionElementoInexistente(posicion);
	}

}

template <class T> void Lista<T>::iniciarCursor(){

	this -> cursor = NULL;

}

template <class T> bool Lista<T>::avanzarCursor(){

	if (this -> cursor == NULL){

		this -> cursor = this -> primero;
	}

	else{

		this -> cursor = this -> cursor ->obtenerSiguiente();

	}

	/*pudo avanzar si el cursor ahora apunta  un nodo*/

	return (this -> cursor != NULL);

}


template <class T> T Lista<T>::obtenerCursor(){

	T elemento;

	if (this -> cursor != NULL){
		elemento = this -> cursor ->obtenerDato();

	} else {

		throw ExcepcionElementoInexistente(0);

	}

	return (elemento);

}

template <class T> Lista<T>::~Lista(){

	while (this -> primero != NULL){

		Nodo<T>* aBorrar = this -> primero;
		this -> primero = this -> primero->obtenerSiguiente();

		delete aBorrar;
	}

}

template <class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion){

	Nodo<T>* actual = this -> primero;

	for (unsigned int i=1; i < posicion; i++ ){

		actual = actual -> obtenerSiguiente();

	}

	return actual;

}


#endif /* LISTA_H_ */
