#ifndef TERRENO_H_
#define TERRENO_H_

const int TAMANIO_MINIMO = 2;

#include "Parcela.h"

class Terreno {

	private:
		unsigned int tamanio;
		Parcela** terreno;
		Parcela* accesoATerreno;

	public:

		//POST: crea la matriz 'terreno' de TAMANIO_MINIMO filas y TAMANIO_MINIMO columnas
		Terreno();

		//POST: crea la matriz 'terreno' de tamanio filas y tamanio columnas
		Terreno(unsigned int tamanio);

		//POST: devuelve la parcela que se encuentra en la posicionFila y posicionColumna del terreno
		Parcela obtenerParcela(unsigned int posicionFila, unsigned int posicionColumna);

		//POST: accede a la parcela que se encuentra en la posicionFila y posicionColumna del terreno
		Parcela* modificarTerreno(unsigned int posicionFila, unsigned int posicionColumna);

		//POST: devuelve la cantidad de filas y columnas de la matriz 'terreno'
		unsigned int obtenerTamanio();

		~Terreno();
};


#endif /* TERRENO_H_ */
