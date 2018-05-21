#include "Terreno.h"

Terreno::Terreno(){
	Parcela crearParcela;
	this->tamanio = TAMANIO_MINIMO;
	this->accesoATerreno = NULL;
	this->terreno = new Parcela* [this->tamanio];
	for (unsigned int a=0; a < this->tamanio; a++){
			this->terreno[a] = new Parcela[this->tamanio];
		}
	for (unsigned int i=0; i<this->tamanio; i++) {
		for (unsigned int j=0; j<this->tamanio; j++) {
			terreno[i][j] = crearParcela;
		}
	}
}

Terreno::Terreno(unsigned int tamanio){
	Parcela crearParcela;
	this->accesoATerreno = NULL;
	this->tamanio = tamanio;
	this->terreno = new Parcela* [this->tamanio];
	for (unsigned int a=0; a < this->tamanio; a++){
			this->terreno[a] = new Parcela[this->tamanio];
		}

	for (unsigned int i=0; i<this->tamanio; i++) {
		for (unsigned int j=0; j<this->tamanio; j++) {
			terreno[i][j] = crearParcela;
		}
	}
}

Parcela Terreno::obtenerParcela(unsigned int posicionFila, unsigned int posicionColumna){
	return this->terreno[posicionFila-1][posicionColumna-1];
}

Parcela* Terreno::modificarTerreno(unsigned int posicionFila, unsigned int posicionColumna){
	this->accesoATerreno = &this->terreno[posicionFila-1][posicionColumna-1];
	return this->accesoATerreno;
}

unsigned int Terreno::obtenerTamanio(){
	return this->tamanio;
}

Terreno::~Terreno(){
	for(unsigned int i = 0; i < this->tamanio; i++)
	   delete [] this->terreno[i];
	delete [] this->terreno;
}
