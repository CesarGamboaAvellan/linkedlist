#include "Mano.h";
#include <iostream>

Mano::Mano() {

}
Mano::~Mano() {

}
void Mano::setCartaEnArray(Carta carta) {
	mano[cartasEnMano] = carta;
	cartasEnMano++;
}
void Mano::imprimirMano() {
	for (int i = 0; i < cartasEnMano; i++) {
		if (retornarPuntos() > 21) {
			for (int j = 0; j < cartasEnMano; j++)if (mano[j].getValor() == 11) { mano[j].setValor(1); j = cartasEnMano; }
		}
		std::cout << mano[i].getPalo();
		std::cout << mano[i].getValor() <<std::endl;
		
	}
}
	
int Mano::retornarPuntos(){
	int puntos = 0;
	// retorna los puntos en la mano de cada jugador
	for (int i = 0; i < cartasEnMano; i++) {
		puntos = puntos + mano[i].getValor();
		mano[i].getValor();
		mano[i].getPalo();
	}
	return puntos;
}
