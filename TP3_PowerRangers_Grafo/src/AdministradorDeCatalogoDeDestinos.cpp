/*
 * CargarCatalogoDestinos.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

// cambiar nombre

#include <fstream>
#include <sstream>

#include "AdministradorDeCatalogoDeDestinos.h"


AdministradorDeCatalogoDestinos::AdministradorDeCatalogoDestinos(){

	this -> destinos = new Lista<Viaje*>;

}

void AdministradorDeCatalogoDestinos::leerArchivo(std::string rutaEntrada) {

	std::ifstream archivo;
	archivo.open(rutaEntrada.c_str());

	std::string linea;

	while (getline(archivo,linea)) {

		this->cargarStringADestino(linea);
		}



	archivo.close();
}

void AdministradorDeCatalogoDestinos::cargarStringADestino(std::string getLinea){

	int i=0;
	bool encontro = false;

	Traductor Traductor;

	//crea un vector para almacenar cada dato del txt.
	std::string vectorDeStrings[4];

	//carga el vector con los datos de la linea
	for (int j=0; j<= 3; j++){
		while(getLinea[i] != ',' && getLinea[i]!= '\0'){
			vectorDeStrings[j] =  vectorDeStrings[j] + getLinea[i];
			i++;
		}
		i++;
	}




	std::string puntoSalida = vectorDeStrings[0];

	std::string puntoLlegada = vectorDeStrings[1];

	int costo = Traductor.convertirAEntero(vectorDeStrings[2]);

	std::string cultivo=vectorDeStrings[3];

	Arribo* arribo  = new Arribo(puntoLlegada, costo, cultivo);
	
	// nuevo metodo
	if(!destinos->estaVacia()){
		destinos->iniciarCursor();
		while(destinos->avanzarCursor() && !encontro){
			Viaje* viaje = destinos->obtenerCursor();
			if(viaje->obtenerSalidaDelViaje() == puntoSalida){
				viaje->agregarArribo(arribo);
				encontro = true;
			}
		}
		if(!encontro){
			this->destinos->agregar(new Viaje(puntoSalida, arribo));
		}
	}
	else{
		this->destinos->agregar(new Viaje(puntoSalida, arribo));
	}



}




Lista<Viaje*>* AdministradorDeCatalogoDestinos::obtenerListaDeDestinos(){

	return this ->destinos;
}




AdministradorDeCatalogoDestinos::~AdministradorDeCatalogoDestinos(){

	destinos->iniciarCursor();

	while (destinos->avanzarCursor()){
		Viaje* viaje = destinos->obtenerCursor();

		Lista<Arribo*>* arribos = viaje->obtenerArribos();
		arribos->iniciarCursor();
		while(arribos->avanzarCursor()){
			Arribo* arribo = arribos->obtenerCursor();

			delete arribo;
		}

		delete viaje;
	}

	delete this ->destinos;

}



