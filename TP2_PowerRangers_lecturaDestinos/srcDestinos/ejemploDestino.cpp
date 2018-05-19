/*
 * ejemplo.cpp
 *
 *  Created on: May 6, 2018
 *      Author: agustin
 */

#include <string>
#include <iostream>

#include "cargarCatalogoDestinos.h" //para leer el txt y cargar la lista


//jugar
int main() {

	std::string archivoCultivos = "destinos.txt";


	Lista<Destino*>* destinos;

	CargarCatalogoDestinos cargarCatalogo;

	cargarCatalogo.leerArchivo(archivoCultivos);


	destinos = cargarCatalogo.obtenerPunteroAListaDeDestinos();

	destinos->iniciarCursor();


	// solo para ver si la lista cargo bien los datos del txt, no es un uso
	while (destinos->avanzarCursor()){

		Destino* semilla =destinos->obtenerCursor();
		std::cout << semilla->obtenerCultivo() << " " << semilla->obtenerDistancia() << " " << semilla->obtenerNombreDelDestino() << std::endl;


	}

	return 0;
}

