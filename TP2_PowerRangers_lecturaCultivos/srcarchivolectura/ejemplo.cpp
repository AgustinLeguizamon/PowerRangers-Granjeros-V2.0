/*
 * ejemplo.cpp
 *
 *  Created on: May 6, 2018
 *      Author: agustin
 */

#include <string>
#include <iostream>

#include "cargarCatalogoCultivos.h" //para leer el txt y cargar la lista
#include "CatalogoCultivos.h" // para utilizar el catalogo una vez cargado


//jugar
int main() {

	std::string archivoCultivos = "cultivos.txt";

	//creo un puntero que apunta a listaCultivos
	Lista <Cultivo*>* cultivos;

	CargarCatalogoCultivos cargarCatalogo;//(cultivos);

	cargarCatalogo.leerArchivo(archivoCultivos);

	//testeo

	cultivos = cargarCatalogo.obtenerPunteroAListaDeCultivos();

	CatalogoCultivos catalogo;

	Cultivo* cultivo = catalogo.obtenerCultivo(cultivos,"A");

	std::cout << cultivo->obtenerRentabilidad() << std::endl;

	cultivos->iniciarCursor();


	// solo para ver si la lista cargo bien los datos del txt, no es un uso
	while (cultivos->avanzarCursor()){

		Cultivo* semilla =cultivos->obtenerCursor();
		std::cout << semilla->obtenerCultivo() << " " << semilla->obtenerCostoSemilla() << " " << semilla->obtenerTiempoCosecha()<< " "
				<< semilla->obtenerRentabilidad() << " " << semilla->obtenerTiempoRecuperacion() << " " << semilla->obtenerAguaPorTurno() << std::endl;


	}

	return 0;
}


