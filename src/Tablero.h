/*
 * Tablero.h
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casillero.h"

class Tablero {
private:
	unsigned int columnas;
	unsigned int filas;
	Lista<Lista<Casillero*>*>* tablero;
public:
	Tablero(unsigned int x, unsigned int y);
	void  setCasillero(int x, int y);
	void iniciarTablero();
	Casillero * getCasillero(unsigned int x, unsigned int y);
	unsigned int getColumnas();
	unsigned int getFilas();
	void mostrarTablero();
	bool compararPosiciones(unsigned int x, unsigned int y);
	void analizarFilas(Celula* aux, int &i, unsigned int x, unsigned int y);
	void analizarColumnas(Celula* aux, unsigned int x, unsigned int y);
	void cargarVecinos();
	void actualizarTablero(int valor);
	virtual ~Tablero();
};

#endif /* TABLERO_H_ */
