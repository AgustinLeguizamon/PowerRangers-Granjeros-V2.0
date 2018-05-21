#include "CatalogoSemillas.h"

Semilla* CatalogoSemillas::obtenerInformacionSemilla(Lista<Semilla*>* semillas, char nombreSemillaSeleccionada){


	Semilla* semilla=NULL;
	bool semillaEncontrada = false;

	semillas->iniciarCursor();

	while(semillas->avanzarCursor() && !semillaEncontrada){
		semilla = semillas->obtenerCursor();

		if(semilla->obtenerNombre() == nombreSemillaSeleccionada){
			semillaEncontrada = true;
		}
	}

	return semilla;

}
