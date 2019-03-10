#include "Mazo.h"
#include "Carta.h"
#include <iostream>
#include <algorithm>

Mazo::Mazo() {

}
Mazo::~Mazo() {

}
void Mazo::inicializar() {
	// se inicializan los contadores, el valor 2, se debe a que se les asignara el palo de 2 a 14
	int count = 0;
	int picas = 2;
	int corazones = 2;
	int treboles = 2;
	int diamantes = 2;
	for (int numeroDeCartas = 0; numeroDeCartas < cartasDeUnMazo-4; numeroDeCartas++) {
		if (numeroDeCartas < 12) {
			cartas[numeroDeCartas].setPalo("P");			
			// Picas
			cartas[numeroDeCartas].setValor(picas);  // asignamos el valor de la carta, iniciando en 2
			if (picas <10) picas++;
		}
		else if (numeroDeCartas >= 12 && numeroDeCartas < 25) {
			cartas[numeroDeCartas].setPalo("C");			
			// corazones
			cartas[numeroDeCartas].setValor(corazones);  // asignamos el valor de la carta, iniciando en 2
			if (corazones <10) corazones++;
		}
		else if (numeroDeCartas >= 25 && numeroDeCartas < 38) {
			cartas[numeroDeCartas].setPalo("T");  // Trebol
			cartas[numeroDeCartas].setValor(treboles);
			if(treboles<10)	treboles++;
		}
		else if (numeroDeCartas >= 38) {
			cartas[numeroDeCartas].setPalo("D");  // Diamantes
			cartas[numeroDeCartas].setValor(diamantes);
			if(diamantes<10)diamantes++;
		}
	}
	//A Picas
	cartas[48].setPalo("P");	
	cartas[48].setValor(11);  
	//A Corazones
	cartas[49].setPalo("C");
	cartas[49].setValor(11);  
	//A Treboles
	cartas[50].setPalo("T");
	cartas[50].setValor(11);  
	//A Diamantes
	cartas[51].setPalo("D");
	cartas[51].setValor(11);  
	

}
// Nota, por el momento lo puse a recibir un int, para asegurarme que se estan guardando las cartas
Carta Mazo::tomarCarta(int posicionEnElArrayDeLaCarta) {

	return cartas[posicionEnElArrayDeLaCarta];
}
void Mazo::barajar() {
	std::random_shuffle(std::begin(cartas), std::end(cartas));
}