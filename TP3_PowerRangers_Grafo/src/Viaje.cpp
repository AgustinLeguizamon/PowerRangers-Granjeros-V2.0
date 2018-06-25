/*
 * Viaje.cpp
 *
 *  Created on: 22 jun. 2018
 *      Author: purrevil
 */


#include "Viaje.h"
Viaje::Viaje(std::string salida){

	this -> salida = salida;

	this-> arribos = new Lista<Arribo*>;




}

std::string Viaje::obtenerSalidaDelViaje(){

	return this ->salida;

}

Lista<Arribo*>* Viaje::obtenerArribos(){

	return this -> arribos;
}


void Viaje::agregarArribo(Arribo* arribo){

	this->arribos->agregar(arribo);
}


Viaje::Viaje(std:: string salida, Arribo* arribo){

	this->salida  = salida;

	this-> arribos = new Lista<Arribo*>;

	this-> agregarArribo(arribo);

}
Viaje::~Viaje(){
	delete this->arribos;
}

