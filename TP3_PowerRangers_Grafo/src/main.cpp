/*
 * main.cpp
 *
 *  Created on: 12 may. 2018
 *      Author: daniela
 */
#include <iostream>
#include <string>

#include "Cola.h"
#include "AdministradorDeCatalogoDeDestinos.h"

using namespace std;

int main (int argc, char* argv[]){

	Cola<Arribo*> cola;

	AdministradorDeCatalogoDestinos catalogo;

	catalogo.leerArchivo("destinos.txt");

	Lista<Viaje*>* viajes = catalogo.obtenerListaDeDestinos();
	viajes->iniciarCursor();
	viajes->avanzarCursor();

	Viaje* viaje = viajes->obtenerCursor();

	Lista<Arribo*>* listaDestinos = viaje->obtenerArribos();

	listaDestinos->iniciarCursor();
	while(listaDestinos->avanzarCursor()){
		cola.acolar(listaDestinos->obtenerCursor()->obtenerCosto(), listaDestinos->obtenerCursor());
	}

	while(!cola.estaVacia()){
		Arribo* eliminado;
		eliminado = cola.desacolar();
		cout << eliminado->obtenerCosto() << endl;
	}


	return 0;
}



