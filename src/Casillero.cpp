/*
 * Casillero.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#include "Casillero.h"

Casillero::Casillero(unsigned int i, unsigned int j) {
	this->posicion.x=i;
	this->posicion.y=j;
	this->celula=new Celula();
}

unsigned int Casillero::getPosicionX(){
	return (this->posicion.x);
}

unsigned int Casillero::getPosicionY(){
	return (this->posicion.y);
}

Celula* Casillero::getCelula(){
	return this->celula;
}

Casillero::~Casillero() {
	// TODO Auto-generated destructor stub
}

