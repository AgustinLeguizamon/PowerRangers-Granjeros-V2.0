#include "Parcela.h"
#include <string>
#include <iostream>
using namespace std;

Parcela::Parcela(){
	this->cultivo = 'X';
	this->estadoCosecha = false;
	this->estadoRiego = false;
	this->estadoSiembra = false;
	this->tiempoCrecimiento = 0;
	this->tiempoRecuperacion = 0;
	this->cultivoPodrido = false;
	this->cultivoSeco = false;
}

void Parcela::sembrarParcela(char nombreCultivo, Lista<Semilla*>* semillas){
	if (listoParaSembrar()){
		CatalogoSemillas informacionCultivo;
		this->cultivo = nombreCultivo;
		this->tiempoCrecimiento = (informacionCultivo.obtenerInformacionSemilla(semillas, this->cultivo)->obtenerTiempoCrecimiento());
		this->estadoSiembra = true;
	}
	else {
		throw string ("La parcela no esta disponible para siembra");
	}
}

void Parcela::cosecharParcela(Lista<Semilla*>* semillas){
	if (listoParaCosechar()){
		CatalogoSemillas informacionCultivo;
		this->tiempoRecuperacion = (informacionCultivo.obtenerInformacionSemilla(semillas, this->cultivo)->obtenerTiempoRecuperacion());
		this->cultivo = 'X';
		this->estadoCosecha = true;
	}
	else {
		throw string ("La parcela no esta disponible para cosecha");
	}
}

void Parcela::regarParcela(){ //tener en cuenta para restar la unidad de riego
	if (!this->regado()){
		this->estadoRiego = true;
	}
	else {
		throw string ("La parcela ya se encuentra regada");
	}
}

bool Parcela::sembrado(){
	return this->estadoSiembra;
}

bool Parcela::regado(){
	return this->estadoRiego;
}

bool Parcela::cosechado(){
	return this->estadoCosecha;
}

char Parcela::obtenerCultivo(){
	return this->cultivo;
}

bool Parcela::obtenerCultivoPodrido(){
	return this->cultivoPodrido;
}

bool Parcela::obtenerCultivoSeco(){
	return this->cultivoSeco;
}

int Parcela::obtenerTiempoRecuperacion(){
	return this->tiempoRecuperacion;
}

int Parcela::obtenerTiempoCrecimiento(){
	return this->tiempoCrecimiento;
}

void Parcela::pudrirParcela() { //esto se usaria al final del turno de cada jugador
	if (this->listoParaCosechar()) {
		this->cultivoPodrido = true;
		this->cultivo = 'X';
		this->tiempoRecuperacion = this->tiempoRecuperacion / 2;
	}
}

void Parcela::secarParcela() {
	if (!this->regado()){
		cultivoSeco = true;
		this->cultivo = 'X';
	}
}

bool Parcela::listoParaCosechar(){
	return (!this->cosechado() && this->obtenerTiempoCrecimiento()== 0);
}

bool Parcela::listoParaSembrar() {
	return (!this->sembrado() && this->obtenerTiempoRecuperacion() == 0);
}
