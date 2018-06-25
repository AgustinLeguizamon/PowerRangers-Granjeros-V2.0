/*
 * Arribo.h
 *
 *  Created on: 22 jun. 2018
 *      Author: purrevil
 */

#ifndef ARRIBO_H_
#define ARRIBO_H_
#include <string>

class Arribo{
private:
	std::string arribo;
	int costo;
	std::string cultivo;
public:

	Arribo(std::string arribo,int costo, std::string cultivo){
		this->arribo = arribo;
		this->costo = costo;
		this->cultivo = cultivo;

	}

	std::string	obtenerArribo(){
		return this->arribo;
	}

	std::string obtenerCultivo(){
		return this->cultivo;
	}

	int obtenerCosto(){
		return this->costo;
	}

};



#endif /* ARRIBO_H_ */
