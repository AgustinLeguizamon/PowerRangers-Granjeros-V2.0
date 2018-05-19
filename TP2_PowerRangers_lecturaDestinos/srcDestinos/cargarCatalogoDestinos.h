/*
 * agendaEstelar.h
 *
 *  Created on: May 12, 2018
 *      Author: agustin
 */

#ifndef CARGARCATALOGODESTINOS_H_
#define CARGARCATALOGODESTINOS_H_

#include "Destino.h"
#include "Lista.h"
#include "Traductor.h"

class CargarCatalogoDestinos{

	private:

		Lista<Destino*>* destinos; // TAL VEZ NO


	public:

		/*
		 * post: crea una lista de punteros a clase Destino y
		 * se la asigna a 'destinos'
		 */
		CargarCatalogoDestinos();


		/*
		 * post: lee el archivo .txt a recibido por 'rutaEntrada'
		 *
		 */
		void leerArchivo(std::string rutaEntrada);


		/*
		 * post: recibe un string tipo getline del metodo leerArchivo
		 * cargar los datos en un vector, los convierte a enteros y se los pasa
		 * al constructor Destino y los agrega a la lista 'destinos'
		 */

		void cargarStringADestino(std::string stringLinea);



		Lista<Destino*>* obtenerPunteroAListaDeDestinos();


		/*
		 * post: libera cada puntero a Destino que se fueron agregando
		 * como datos a la lista
		 */
		~CargarCatalogoDestinos();


};


#endif /* CARGARCATALOGODESTINOS_H_ */
