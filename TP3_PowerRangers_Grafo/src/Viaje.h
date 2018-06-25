/*
 * Viaje.h
 *
 *  Created on: 22 jun. 2018
 *      Author: purrevil
 */

#ifndef VIAJE_H_
#define VIAJE_H_

#include "Arribo.h"
#include "Lista.h"

class Viaje{

	private:

		std::string salida;

		Lista<Arribo*>* arribos;

	public:

		/*
		 * post: instancia de 'Viaje' inicializada
		 */

		Viaje(std::string salida);


		/*
		 * post: devuelve el dato 'nombreDelDestino'
		 */

		std::string obtenerSalidaDelViaje();


		/*
		* post: devuelve el dato 'distancia'
		*/

		Lista<Arribo*>* obtenerArribos();


		void agregarArribo(Arribo* arribo);

		Viaje(std:: string salida, Arribo* arribo);
		~Viaje();

};



#endif /* VIAJE_H_ */
