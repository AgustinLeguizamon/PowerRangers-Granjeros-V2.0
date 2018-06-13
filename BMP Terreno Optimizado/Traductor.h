/*
 * Traductor.h
 *
 *  Created on: 20 may. 2018
 *      Author: daniela
 */

#ifndef TRADUCTOR_H_
#define TRADUCTOR_H_

#include <string>
#include <sstream>


class Traductor{

	public:

		/*
		 * post: convierte a enteros el 'valor' recibido
		 */

		int convertirAEntero(std::string array){

			int valor;

			// cambia los string a enteros
			std::istringstream buffer(array);
			valor=0; //si ocurre algo, por defecto pone un 0
			buffer >> valor;

			return valor;

		}

		std::string convertirEnteroAString(int numero){

			std::stringstream stringStreamNumero;
			stringStreamNumero << numero;
			std::string stringNumero = stringStreamNumero.str();

			return stringNumero;
		}

};



#endif /* TRADUCTOR_H_ */
