/*
 * nodo.h
 *
 *  Created on: Apr 29, 2018
 *      Author: agustin
 */

#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif


template <class T> class  Nodo{

	private:

		T dato;

		Nodo<T>* siguiente;

	public:

		/* pre:
		 * post: El nodo resulta inicizalizado con el dato dado y
		 * sin un Nodo siguiente
		 */

		Nodo(T dato){

			this -> dato = dato;

			this -> siguiente = NULL;
		};


		/*
		 * pre:
		 * post: devuelve el valor del dato
		 */

		T obtenerDato(){

			return this -> dato;
		}


		/*
		 * post: cambia el valor "dato" por "nuevoDato"
		 */

		void cambiarDato(T nuevoDato){

			this -> dato = nuevoDato;
		}


		/*
		 * pre:
		 * post: devuelve la direccion de memoria del "siguiente" nodo
		 */

		Nodo<T>* obtenerSiguiente(){

			return this -> siguiente;
		}


		/*pre:
		 * post: cambia la direccion de memoria que apunta "siguiente"
		 */

		void cambiarSiguiente(Nodo<T>* nuevoSiguiente){

			this-> siguiente = nuevoSiguiente;
		}

};



#endif /* NODO_H_ */
