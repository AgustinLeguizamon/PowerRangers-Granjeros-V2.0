#ifndef CATALOGOSEMILLAS_H_
#define CATALOGOSEMILLAS_H_

#include "Lista.h"
#include "Semilla.h"

class CatalogoSemillas{

	public:

		/*
		 *
		 */
		Semilla* obtenerInformacionSemilla(Lista <Semilla*>* semillas, char nombreSemillaSeleccionada); //CLASE DISTINTA Y LE PASO LA LISTA, COMO EN ASTRONOMOS

};


#endif /* CATALOGOSEMILLAS_H_ */
