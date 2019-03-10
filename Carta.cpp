#include "Carta.h"
#include <iostream>

Carta::Carta() {

}
Carta::~Carta() {

}
 std::string Carta::getPalo() {
	return palo;;
}
 int Carta::getValor() {
	 return valor;
}

 void Carta::voltear() {
	 bocaAbajo = true;
 }
 void Carta::setValor(int val) {
	 valor = val;
 }

 void Carta::setPalo(std::string tipoCarta) {
	 palo = tipoCarta;
 }