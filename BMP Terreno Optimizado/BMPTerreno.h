/*
 * BMPTerreno.h
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#ifndef BMPTERRENO_H_
#define BMPTERRENO_H_

#include "EasyBMP.h"
#include "Terreno.h"
#include "Traductor.h"


const float DEFAULT = 5;  /* Dividendo base para obtener
	 	 	 	 	 	  el RATIO W y RATIOH */

const float TAMANIO_BMP_PARCELA= 50; //Tamaño del BMP de los cultivos 100 x 100

const float DISTANCIA_ENTRE_PARCELAS = 100;

const float DISTANCIA_BORDE_IMAGEN = 25;


class BMPTerreno {

	public:

	//post: crea imagen en BMP del terreno
	void guardarTerrenoEnBMP(int argc, char* argv[], Terreno* Terreno, std::string jugador, int numeroDeTerreno);

};



#endif /* BMPTERRENO_H_ */
