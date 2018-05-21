/*
 * Traductor.h
 *
 *  Created on: May 18, 2018
 *      Author: agustin
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

char* convertirEnteroAPunteroChar(int numero){

	char* punteroAChar;

	std::stringstream stringTerreno;
	stringTerreno << numero;
	std::string temp_str = stringTerreno.str();

	punteroAChar = (char*) temp_str.c_str();

	return punteroAChar;
}


};


#endif /* TRADUCTOR_H_ */
