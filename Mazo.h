#pragma once
#include "Carta.h"

class Mazo {
private:
	const int cartasDeUnMazo = 52;
	Carta cartas[52];
public:
	Mazo();
	~Mazo();
	void inicializar();
	void barajar();
	Carta tomarCarta(int);
};