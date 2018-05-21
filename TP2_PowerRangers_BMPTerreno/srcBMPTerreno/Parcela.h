#ifndef PARCELA_H_
#define PARCELA_H_

#include "CatalogoSemillas.h"
#include "Lista.h"

class Parcela {
	private:
		char cultivo;
		bool estadoSiembra;
		bool estadoRiego;
		bool estadoCosecha;
		int tiempoRecuperacion;
		int tiempoCrecimiento;
		bool cultivoPodrido;
		bool cultivoSeco;

	public:

		//POST: crea una parcela con los valores inicializados
		Parcela();

		//PRE: la parcela debe estar sin sembrar
		//POST: siembra la parcela actualizando los valores de 'cultivo', 'tiempoCrecimiento' y 'estadoSiembra'
		void sembrarParcela(char semilla, Lista<Semilla*>* semillas);

		//PRE: la parcela debe estar sin cosechar
		//POST: cosecha la parcela actualizando los valores de 'cultivo', 'estadoCosecha' y 'tiempoRecuperacion'
		void cosecharParcela(Lista<Semilla*>* semillas);

		//PRE: la parcela debe estar sin regar
		//POST: riega la parcela actualizando 'estadoRiego'
		void regarParcela();

		//POST: devuelve si la parcela esta sembrada
		bool sembrado();

		//POST: devuelve si la parcela esta regada
		bool regado();

		//POST: devuelve si la parcela fue cosechada
		bool cosechado();

		//POST: devuelve el nombre del cultivo
		char obtenerCultivo();

		//POST: devuelve si el cultivo se echo a perder por falta de cosecha
		bool obtenerCultivoPodrido();

		//POST: devuelve si el cultivo se seco por falta de riego
		bool obtenerCultivoSeco();

		//POST: devuelve el tiempo de recuperacion de la parcela para poder ser sembrada
		int obtenerTiempoRecuperacion();

		//POST: devuele el tiempo de crecimiento de la semilla para poder ser cosechada
		int obtenerTiempoCrecimiento();

	private:

		//POST: echa a perder la parcela por no cosechar a tiempo
		void pudrirParcela();

		//POST: seca la parcela por falta de riego
		void secarParcela();

		//POST: devuelve si la parcela esta lista para cosechar o no
		bool listoParaCosechar();

		//POST: devuelve si la parcela esta lista para sembrar o no
		bool listoParaSembrar();
};



#endif /* PARCELA_H_ */

