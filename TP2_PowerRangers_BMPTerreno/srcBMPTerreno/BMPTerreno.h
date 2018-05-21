/*
 * BMPTerreno.h
 *
 *  Created on: May 20, 2018
 *      Author: agustin
 */

#ifndef BMPTERRENO_H_
#define BMPTERRENO_H_

#include "EasyBMP.h"
#include "Terreno.h"
#include "Traductor.h"



const float DEFAULT = 5;  /* Este valor es el dividendo base para obtener
	 	 	 	 	 	  el RATIO W y RATIOH */

const float TAMANIO_BMP_PARCELA= 100; //Tamaño del BMP de los cultivos 100 x 100

const float DISTANCIA_ENTRE_PARCELAS = 200;

const float DISTANCIA_BORDE_IMAGEN = 50;


class BMPTerreno {

	public:



	void guardarTerrenoEnBMP(int argc, char* argv[],
							Terreno* Terreno, std::string jugador,
							int numeroDeTerreno);

};



#endif /* BMPTERRENO_H_ */
