/*
 *
 *  Created on: May 12, 2018
 *      Author: agustin
 */

#ifndef CARGARCATALOGOCULTIVOS_H_
#define CARGARCATALOGOCULTIVOS_H_

#include "Cultivo.h"
#include "Lista.h"
#include "Traductor.h"

class CargarCatalogoCultivos{

	private:


		Lista<Cultivo*>* cultivos;


	public:

		/*
		 * post: crea una lista de punteros a clase Cultivo y
		 * la asigna a 'cultivos'
		 */
		CargarCatalogoCultivos();


		/*
		 * post: lee el archivo .txt a recibido por 'rutaEntrada'
		 */
		void leerArchivo(std::string rutaEntrada);


		/*
		 * pre:
		 * post: recibe un string tipo getline del metodo leerArchivo
		 * cargar los datos en un vector, los convierte a enteros y se los pasa
		 * al constructor Cultivo y los agrega a la lista 'cultivos'
		 */
		void cargarStringACultivo(std::string stringLinea);


		/*
		 * post: devuelve el atributo 'cultivos'
		 */
		Lista<Cultivo*>* obtenerPunteroAListaDeCultivos();


		/*
		 * post: libera cada puntero a cultivo que se fueron agregando
		 * como datos a la lista
		 */
		~CargarCatalogoCultivos();


};


#endif /* CARGARCATALOGOCULTIVOS_H_ */
