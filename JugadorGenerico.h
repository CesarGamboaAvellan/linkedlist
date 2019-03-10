#pragma once
#include "Carta.h"
#include "Mano.h"
#include <iostream>
class JugadorGenerico {
private:
	std::string nickName;
	Mano manoJudador;
	
public:
	JugadorGenerico();
	~JugadorGenerico();
	void setName(std::string nombre);
	void pedirCarta(Carta*);
	void setMano(Mano mano);
	void mostrarMano();
	int mostrarTotal();
	std::string printName();
};