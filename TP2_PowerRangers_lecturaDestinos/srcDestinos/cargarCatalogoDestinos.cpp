/*
 * lectura.cpp
 *
 *  Created on: May 6, 2018
 *      Author: agustin
 */

#include <fstream>
#include <sstream>
#include "cargarCatalogoDestinos.h"



CargarCatalogoDestinos::CargarCatalogoDestinos(){


	this -> destinos = new Lista <Destino*>;

}



void CargarCatalogoDestinos::leerArchivo(std::string rutaEntrada) {

	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	std::string stringLinea;

	while (! entrada.eof()) {

		std::getline(entrada, stringLinea);


		this -> cargarStringADestino(stringLinea);

	}

	entrada.close();

}



void CargarCatalogoDestinos::cargarStringADestino(std::string getLinea){

	int i=0;

	Traductor Traductor;

	//crea un vector para almacenar cada dato del txt.
	std::string vectorDeStrings[3];

	//carga el vector con los datos de la linea
	for (int j=0; j<= 2; j++){ //
		while(getLinea[i] != ',' && getLinea[i]!= '\0'){
			vectorDeStrings[j] =  vectorDeStrings[j] + getLinea[i];
			i++;
		}
		i++;
	}


	Destino* ptrADestino;


	std::string destino = vectorDeStrings[0];

	int distancia= Traductor.convertirAEntero(vectorDeStrings[1]);

	std::string cultivo=vectorDeStrings[2];


	ptrADestino = new Destino(destino, distancia, cultivo);

	this->destinos->agregar(ptrADestino);


	return;
}




Lista<Destino*>* CargarCatalogoDestinos::obtenerPunteroAListaDeDestinos(){

	return this ->destinos;
}




CargarCatalogoDestinos::~CargarCatalogoDestinos(){

	destinos->iniciarCursor();

	while (destinos->avanzarCursor()){
		Destino* PtrABorrar = destinos->obtenerCursor();

		delete PtrABorrar;
	}

	delete this ->destinos;

}
