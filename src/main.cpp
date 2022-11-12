/*
 * main.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */
#include <iostream>
#include "Tablero.h"
int main(){
	Tablero * tablero=new Tablero(10, 10);
	tablero->setCasillero(1, 1);
	tablero->setCasillero(1, 3);
	tablero->setCasillero(1, 2);
	tablero->setCasillero(2, 1);
	tablero->setCasillero(3, 2);
	tablero->setCasillero(2, 3);
	//tablero->setCasillero(5, 1);
	//tablero->setCasillero(5, 10);
	tablero->mostrarTablero();
	tablero->cargarVecinos();
	int j=1;
	Celula* aux=tablero->getCasillero(j, j)->getCelula();
	std::cout<<"Celulas vecinas vivas en la posicion ("<<j<<","<<j<<")."<<std::endl;
	for (int i=0; i<8; i++){
		if (aux->mostrarCelulasVecinas(i)==vivo){
			std::cout<<"vivo-";
		}else{
			std::cout<<"muerto-";
		}
	}
	std::cout<<std::endl;
	tablero->setCasillero(3, 1);
	tablero->setCasillero(3, 3);
	tablero->mostrarTablero();
	std::cout<<"Celulas vecinas vivas en la posicion ("<< j <<","<< j <<")."<<std::endl;
	for (int i=0; i<8; i++){
		if (aux->mostrarCelulasVecinas(i)==vivo){
			std::cout<<"vivo-";
		}else{
			std::cout<<"muerto-";
		}
	}
	//tablero->actualizarTablero(1);
	//tablero->mostrarTablero();
	return 0;
}


