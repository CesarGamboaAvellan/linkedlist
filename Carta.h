#pragma once
#include <string>
class Carta {
	std::string palo;
	int valor;
	bool bocaAbajo = false;
public:
	Carta();
	~Carta();
	int getValor();
	void setValor(int val);
	void setPalo(std::string);
	std::string getPalo();
	void voltear();
};