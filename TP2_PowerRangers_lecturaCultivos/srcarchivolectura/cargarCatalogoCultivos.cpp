/*
 * lectura.cpp
 *
 *  Created on: May 6, 2018
 *      Author: agustin
 */


#include <fstream>
#include <sstream>
#include "cargarCatalogoCultivos.h"


CargarCatalogoCultivos::CargarCatalogoCultivos(){


	this -> cultivos = new Lista <Cultivo*>;

}



void CargarCatalogoCultivos::leerArchivo(std::string rutaEntrada) {


	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	//declara un string
	std::string getLinea;


	/* lee el resto del archivo */
	while (! entrada.eof()) {


		std::getline(entrada, getLinea);

		//clase funcion que haga todos lo de bajo

		this -> cargarStringACultivo(getLinea);


	} // while
	/* cierra el archivo, liberando el recurso */
	entrada.close();

}


void CargarCatalogoCultivos::cargarStringACultivo(std::string getLinea){

	int i=0;

	Traductor Traductor;

	//crea un vector para almacenar cada dato del txt.
	std::string vectorDeStrings[6];

	//carga el vector con los datos de la linea
	for (int j=0; j<= 5; j++){ //
		while(getLinea[i] != ',' && getLinea[i]!= '\0'){
			vectorDeStrings[j] =  vectorDeStrings[j] + getLinea[i];
			i++;
		}
		i++;
	}


	Cultivo* punteroCultivo;

	std::string cultivo = vectorDeStrings[0];

	int costoSemilla= Traductor.convertirAEntero(vectorDeStrings[1]);

	int tiempoCosecha=Traductor.convertirAEntero(vectorDeStrings[2]);

	int rentabilidad=Traductor.convertirAEntero(vectorDeStrings[3]);

	int tiempoRecuperacion=Traductor.convertirAEntero(vectorDeStrings[4]);

	int aguaTurno=Traductor.convertirAEntero(vectorDeStrings[5]);

	/*asigno un espacio en el heap para un puntero a una Estrella*/
	punteroCultivo = new Cultivo(cultivo, costoSemilla, tiempoCosecha,
			 rentabilidad, tiempoRecuperacion, aguaTurno);

	this->cultivos->agregar(punteroCultivo);


	return;
}



Lista<Cultivo*>* CargarCatalogoCultivos::obtenerPunteroAListaDeCultivos(){

	return this ->cultivos;
}



CargarCatalogoCultivos::~CargarCatalogoCultivos(){

	cultivos->iniciarCursor();

	while (cultivos->avanzarCursor()){
		Cultivo* PtrABorrar = cultivos->obtenerCursor();

		delete PtrABorrar;
	}

	delete this ->cultivos;

}
