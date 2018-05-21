
#ifndef SEMILLA_H_
#define SEMILLA_H_

#include <string>

class Semilla{

	private:

		char nombre;

		int costo;

		int rentabilidad;

		int tiempoCrecimiento;

		int tiempoRecuperacion;

		int consumoAgua;

	public:

		/*
		 * post: instancia de 'Semilla' inicializada
		 */

		Semilla (char nombre, int costo,
				int renta, int tiempoCrecimiento, int tiempoRecuperacion, int agua){

			this -> nombre = nombre;

			this ->costo = costo;

			this ->rentabilidad = renta;

			this->tiempoCrecimiento = tiempoCrecimiento;

			this ->tiempoRecuperacion = tiempoRecuperacion;

			this -> consumoAgua = agua;

		}

		/*
		 * post: devuelve el dato 'nombre'
		 */

		char obtenerNombre(){

			return this -> nombre;
		}

		/*
		 * post: devuelve el dato 'costo'
		 */

		int obtenerCostoSemilla(){

			return this ->costo;

		}

		/*
		 * post: devuelve el dato 'rentabilidad'
		 */

		int obtenerRentabilidad(){

			return this ->rentabilidad;
		}

		/*
		 * post: devuelve el dato 'tiempoRecuperacion'
		 */

		int obtenerTiempoCrecimiento(){
			return this->tiempoCrecimiento;
		}

		int obtenerTiempoRecuperacion(){

			return this ->tiempoRecuperacion;
		}

		/*
		 * post: devuelve el dato 'consumoAgua'
		 */
		int obtenerConsumoAgua(){

			return this -> consumoAgua;
		}
};


#endif /* SEMILLA_H_ */



