/*
 * Tablero.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int x, unsigned int y) {
	this->columnas=x;
	this->filas=y;
	this->tablero=new Lista<Lista<Casillero*>*>();
	for (unsigned int i=1; i<=x; i++){
		Lista<Casillero*>* columna=new Lista<Casillero*>();
		for (unsigned int j=1; j<=y; j++){
			Casillero* fila=new Casillero(i,j);
			columna->add(fila);
		}
		this->tablero->add(columna);
	}
}

void Tablero::setCasillero(int x, int y){
	int i=1, j=1;
	this->tablero->reiniciarCursor();
	while (i<=x){
		this->tablero->avanzarCursor();
		this->tablero->getCursor()->reiniciarCursor();
		if (i==x){
			while (this->tablero->getCursor()->avanzarCursor() && j<=y){
				if (j==y){
					this->tablero->getCursor()->getCursor()->getCelula()->setCelulaViva();
				}
				j++;
			}
		}
		i++;
	}
}

void Tablero::iniciarTablero(){
	this->tablero->reiniciarCursor();
	this->tablero->avanzarCursor();
	for (unsigned int i=1; i<=this->columnas; i++){
		this->tablero->getCursor()->reiniciarCursor();
		this->tablero->getCursor()->avanzarCursor();
		this->tablero->avanzarCursor();
	}
}

Casillero * Tablero::getCasillero(unsigned int x, unsigned int y){//corregir
	Casillero* aux;
	bool encontrado=false;
	iniciarTablero();
	while (!encontrado && this->tablero->getCursor()->getCursor()->getPosicionX()<=x){
		if (this->tablero->getCursor()->getCursor()->getPosicionX()==x){
			while (!encontrado && this->tablero->getCursor()->getCursor()->getPosicionY()<=y){
				if (this->tablero->getCursor()->getCursor()->getPosicionY()==y){
					encontrado=true;
					aux=this->tablero->getCursor()->getCursor();
				}else{
					this->tablero->getCursor()->avanzarCursor();
				}
			}
		}else{
			this->tablero->avanzarCursor();
		}
	}
	return aux;
}

unsigned int Tablero::getColumnas(){
	return this->columnas;
}

unsigned int Tablero::getFilas(){
	return this->filas;
}

void Tablero::mostrarTablero(){
	iniciarTablero();
	for(unsigned int i=1; i<=this->filas; i++){
		for(unsigned int j=1; j<=this->columnas; j++){
			if(this->tablero->getCursor()->getCursor()->getCelula()->getEstado()==vivo){
				std::cout<<"[0]";
			}else{
				std::cout<<"[ ]";
			}
			this->tablero->getCursor()->avanzarCursor();
			this->tablero->avanzarCursor();
		}
		std::cout<<std::endl;
	}
}

bool Tablero::compararPosiciones(unsigned int x, unsigned int y){
	if (this->tablero->getCursor()->getCursor()->getPosicionX()==x){
		if (this->tablero->getCursor()->getCursor()->getPosicionY()==y){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void Tablero::analizarFilas(Celula* aux, int &i, unsigned int x, unsigned int y){
	this->tablero->getCursor()->retrocederCursor();
	aux->setCelulaVecina(this->tablero->getCursor()->getCursor()->getCelula(), i);
	this->tablero->getCursor()->avanzarCursor();
	if (!compararPosiciones(x, y)){
		i++;
		aux->setCelulaVecina(this->tablero->getCursor()->getCursor()->getCelula(), i);
	}
	this->tablero->getCursor()->avanzarCursor();
	i++;
	aux->setCelulaVecina(this->tablero->getCursor()->getCursor()->getCelula(), i);
}

void Tablero::analizarColumnas(Celula* aux, unsigned int x, unsigned int y){
	int k=0;
	while (k<8){
		if (k==0){
			this->tablero->retrocederCursor();
		}else{
			this->tablero->avanzarCursor();
		}
		analizarFilas(aux, k, x, y);
		k++;
	}
	this->tablero->retrocederCursor();
}

void Tablero::cargarVecinos(){
	iniciarTablero();
	for(unsigned int i=1; i<=this->columnas; i++){
		for(unsigned int j=1; j<=this->filas; j++){
			Celula* aux=this->tablero->getCursor()->getCursor()->getCelula();
			analizarColumnas(aux, i, j);
		}
		this->tablero->avanzarCursor();
	}
}
/*
void Tablero::actualizarTablero(int valor){

}*/

Tablero::~Tablero() {
}

