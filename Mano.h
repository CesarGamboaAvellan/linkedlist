#pragma once
#include "Carta.h"
class Mano {
private:
	Carta mano[10];
	int cartasEnMano=0;
public: 
	Mano();
	~Mano();
	void setCartaEnArray(Carta carta);
	void imprimirMano();
	int retornarPuntos();
};