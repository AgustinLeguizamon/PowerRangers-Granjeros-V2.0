/*
 * BMPTerreno.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: daniela
 */

#include "BMPTerreno.h"

void BMPTerreno::guardarTerrenoEnBMP(int argc, char* argv[], Terreno* terreno,
									std::string jugador, int numeroDeTerreno){

	BMP TerrenoActualizado;


	/*Lee el terreno base*/
	TerrenoActualizado.ReadFromFile("Terreno.bmp");

	int columnas = terreno->obtenerColumnas();
	int filas = terreno->obtenerFilas();

	float RATIOW = DEFAULT/ columnas; /*Ratio Width: divide el caso base
								por la cant de columnas*/
	float RATIOH = DEFAULT / filas; /* Ratio Height*/



	BMP BmpParcela; /*la clase BMP usada para leer el .BMP correspondiente
					al estado de la parcela*/



	//Recorre el terreno
	for(int i=1; i<=columnas; i++){
		for (int j=1; j<=filas; j++){

			/* obtiene el puntero a la parcela */
			Parcela* punteroParcela;
			punteroParcela = terreno->modificarParcela(j,i);
			/*Segun el estado del cultivo que devuelva True, la clase BmpParcela
			 * utiliza el metodo ReadFromFile para cargar el bmp correspondiente*/
			if(punteroParcela->listoParaSembrar()){

				BmpParcela.ReadFromFile("ParcelaSeca.bmp");

			}

			else if (punteroParcela->sembrado()){

				BmpParcela.ReadFromFile("ParcelaSembrada.bmp");

			}

			else if (punteroParcela->estaCreciendo()){

				BmpParcela.ReadFromFile("CultivoCreciendo.bmp");

			}

			else if (punteroParcela->listoParaCosechar()){

				BmpParcela.ReadFromFile("CultivoMaduro.bmp");

			}

			else if (punteroParcela->estaPodrido()){

				BmpParcela.ReadFromFile("CultivoPodrido.bmp");

			}

			else if (punteroParcela->estaRecuperandose()){


				BmpParcela.ReadFromFile("ParcelaRecuperandose.bmp");

			}

			/* Rescala si el tamanio del terreno no es de 5 x 5*/
			if (RATIOH!=1 || RATIOW!=1){
				Rescale( BmpParcela, 'W' , RATIOW*TAMANIO_BMP_PARCELA);
				Rescale( BmpParcela, 'H' , RATIOH*TAMANIO_BMP_PARCELA);
			}

			/*El bmp de la parcela seleccioanda se coloca en la posicion del BMP Terreno
			 * segun la fila y columna de Terreno->obtenerParcela(j,i)*/
			RangedPixelToPixelCopy( BmpParcela, 0, (TAMANIO_BMP_PARCELA*RATIOW),
			0, (TAMANIO_BMP_PARCELA*RATIOH), TerrenoActualizado,
			(DISTANCIA_BORDE_IMAGEN+(DISTANCIA_ENTRE_PARCELAS*(i-1)))*RATIOW
			,(DISTANCIA_BORDE_IMAGEN+(DISTANCIA_ENTRE_PARCELAS*(j-1)))*RATIOH);



			/*Fuera de la cadena de else if,ve si la parcela esta regada
			 * Esto es independiente de los varios estados de la parcela
			 * */
			if(punteroParcela->regado()){

				BMP BmpParcelaRiego;/* la clase BMP usada para leer EN EL CASO
									QUE CORRESPONDA el BMP de parcela
									regada (TransparentParcelaRegada) */

				BmpParcelaRiego.ReadFromFile("TransparentParcelaRegada.bmp");

				RangedPixelToPixelCopyTransparent( BmpParcelaRiego, 0, TAMANIO_BMP_PARCELA*RATIOW,
				0, TAMANIO_BMP_PARCELA*RATIOH, TerrenoActualizado,
				(DISTANCIA_BORDE_IMAGEN+(DISTANCIA_ENTRE_PARCELAS*(i-1)))*RATIOW,
				(DISTANCIA_BORDE_IMAGEN+(DISTANCIA_ENTRE_PARCELAS*(j-1)))*RATIOH,
				*BmpParcelaRiego(0,0) );

			}


		}//for

	}//for


	Traductor traductor;


	/*Concatena el string "Terreno" con el nombre del 'jugador' y la posicion
	 * del terreno 'numTerreno' en la lista de Terreno*/
	std::string StringDatosTerreno = "Terreno" + traductor.convertirEnteroAString(numeroDeTerreno)
										+ jugador + ".bmp";


	/*castea como puntero char el nombre que tendra el terreno en el bmp*/
	const char* nombreBMPTerrenoNumeroJugador = StringDatosTerreno.c_str();


	/*Escribe el BMP con el nombre y numero de terreno recibido,
	 * si este ya existe lo sobreescribe
	 */

	TerrenoActualizado.WriteToFile(nombreBMPTerrenoNumeroJugador);

}


