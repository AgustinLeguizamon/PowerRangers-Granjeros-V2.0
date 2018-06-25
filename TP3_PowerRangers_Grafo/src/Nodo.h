/*
 * Nodo.h
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */

#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

#ifndef INF
#define INF 999
#endif


template<class T> class Nodo {

    private:

        T dato;
        int prioridad;

        Nodo<T>* siguiente;

    public:

        /*
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        Nodo(T dato) {

            this->dato = dato;
            this->prioridad = 1;
            this->siguiente = NULL;
        }
        Nodo(int prioridad,T dato){
        	this->dato = dato;
        	this->prioridad = prioridad;
        	this->siguiente = NULL;
        }

        /*
         * post: devuelve el valor del dato.
         */
        T obtenerDato() {

            return this->dato;
        }

        /*
         * post: cambia el valor del dato.
         */
        void cambiarDato(T nuevoDato) {

            this->dato = nuevoDato;
        }

        /*
         * post: devuelve el siguiente Nodo.
         */
        Nodo<T>* obtenerSiguiente() {

            return this->siguiente;
        }

        /*
         * post: cambia el siguiente Nodo por nuevoSiguiente.
         */
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }
        int obtenerPrioridad(){
        	return this->prioridad;
        }
};




#endif /* NODO_H_ */
