/*
 * BMPTerreno.cpp
 *
 *  Created on: May 20, 2018
 *      Author: agustin
 */



#include "BMPTerreno.h"


void BMPTerreno::guardarTerrenoEnBMP(int argc, char* argv[], Terreno* terreno,
									std::string jugador, int numeroDeTerreno){

	/* lee el terreno base*/
	BMP TerrenoActual;
	TerrenoActual.ReadFromFile("Terreno.bmp");

	/*creo una copia que va a sobreescribir el 'TerrenoActual' a partir del
	parametro 'terreno'*/
	BMP TerrenoActualizado;
	TerrenoActualizado.SetSize( TerrenoActual.TellWidth() , TerrenoActual.TellHeight() );
	TerrenoActualizado.SetBitDepth( 16 );


	//copio el BMP TerrenoActual a TerrenoActualizado
	RangedPixelToPixelCopy( TerrenoActual, 0, TerrenoActualizado.TellWidth()-1,
			TerrenoActualizado.TellHeight()-1 , 0,
			TerrenoActualizado, 0,0 );


	/* modifica el tamaño de cada parcela segun la cantidad de filas y columnas
	 * que tenga el terreno
	*/

	/*****DEBERIA DECLARARSE EN OTRO LADO*****/
	int M = 5; //columnas de la matriz
	int N = 5; //filas de la matriz
	/*****DEBERIA DECLARARSE EN OTRO LADO*****/

	float RATIOW = DEFAULT/ M; /*Ratio Width: divide el caso base
								por la cant de columnas*/
	float RATIOH = DEFAULT / N; /* Ratio Height*/



	BMP BmpParcela; /*la clase BMP usada para leer el .BMP correspondiente
					al estado de la parcela*/

	BMP BmpParcelaRiego;/* la clase BMP usada para leer EN EL CASO
						QUE CORRESPONDA el BMP de parcela
						regada (TransparentParcelaRegada) */

	//Recorre el terreno
	for(int i=1; i<=M; i++){
		for (int j=1; j<=N; j++){

			/* obtiene el puntero a la parcela
			 * TUVE QUE UTILIZAR modificarTerreno para obtener el puntero*/
			Parcela* punteroParcela;
			punteroParcela = terreno->modificarTerreno(j,i);

			/*Segun el estado del cultivo que devuelva True, la clase BmpParcela
			 * utiliza el metodo ReadFromFile para cargar el bmp correspondiente*/
			if(punteroParcela->obtenerCultivoSeco()){

				BmpParcela.ReadFromFile("ParcelaSeca.bmp");

			}

			else if (punteroParcela->sembrado()){

				BmpParcela.ReadFromFile("ParcelaSembrada.bmp");

			}

			else if (punteroParcela->obtenerTiempoCrecimiento()!=0){
				/*A falta de metodo estaCreciendo, veo si ya tiene un tiempo
				 * de crecimiento != 0*/

				BmpParcela.ReadFromFile("CultivoCreciendo.bmp");

			}

			else if (punteroParcela->obtenerTiempoCrecimiento()==0){
				/*A falta de metodo PUBLICO estaMaduro, veo si el tiempo
				 * de crecimiento es 0*/

				BmpParcela.ReadFromFile("CultivoMaduro.bmp");

			}

			else if (punteroParcela->obtenerCultivoPodrido()){

				BmpParcela.ReadFromFile("CultivoPodrido.bmp");

			}

			else if (punteroParcela->obtenerTiempoRecuperacion()!= 0){
				/*A falta de metodo PUBLICO estaRecuperandose, veo si el tiempo
				 * de recuperacion es != 0*/

				BmpParcela.ReadFromFile("ParcelaRecuperandose.bmp");

			}

/////////////////////
			//else if....
			/*puede ser que sea mejor poner solo ifs pero no se que pasa
			 * si llamo varias veces al mismo metodo y
			 * soobrescribo el readfile anterior
			 * va a depender de como se manejen los chicos*/
///////////////////

			/* Rescala si el tamaño del terreno no es de 5 x 5*/
			if (RATIOH!=1 && RATIOW!=1){
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
			if(punteroParcela->sembrado()){

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

	/*Utiliza el metodo de la clase Traductor para convertir el numero a un puntero a char* */
	std::string stringNumeroTerreno =
					traductor.convertirEnteroAPunteroChar(numeroDeTerreno);


	/*Concatena el string "Terreno" con el nombre del 'jugador' y la posicion
	 * del terreno 'numTerreno' en la lista de Terreno*/
	std::string ConcatenarDatosTerreno = "Terreno" + stringNumeroTerreno
										+ jugador + ".bmp";


	const char* nombreBMPTerrenoNumeroJugador = ConcatenarDatosTerreno.c_str();


	/*Sobreescibe el BMP del Terreno (TerrenoActual) recibido
	con el TerrenoActualizado*/

	TerrenoActualizado.WriteToFile(nombreBMPTerrenoNumeroJugador);

	/*en la carpeta debería aparecer la imagen con los datos del terreno
	 * actualizados*/

}
