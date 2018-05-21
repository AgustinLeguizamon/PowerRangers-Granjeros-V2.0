
#include "BMPTerreno.h"


//void crearBMPTerreno(int argc, char* argv[]);

int main( int argc, char* argv[] ){


	BMPTerreno bmp; //constructor clase BMPTerreno

	/// estos datos los proveen ustedes
	Terreno* terreno;

	std::string jugador;

	int numeroDeTerreno;
	////

	bmp.guardarTerrenoEnBMP(argc, argv,terreno, jugador, numeroDeTerreno);

	/*ignoren el warning de numeroDeTerreno, solo se convierte en un string
	 * y se usa para el nombre del bmp generado*/

	return 0;
}






