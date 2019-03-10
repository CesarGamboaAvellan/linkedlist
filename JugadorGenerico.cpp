#include "JugadorGenerico.h"
#include "Carta.h"
#include <iostream>
#include <string>


JugadorGenerico::JugadorGenerico() {

}

JugadorGenerico::~JugadorGenerico() {

}
void JugadorGenerico::pedirCarta(Carta* carta) {
	manoJudador.setCartaEnArray(*carta);
}
void JugadorGenerico::setMano(Mano mano) {
	manoJudador = mano;
}
void JugadorGenerico::mostrarMano() {
	manoJudador.imprimirMano();
}
int JugadorGenerico::mostrarTotal() {
	return manoJudador.retornarPuntos();
}
void JugadorGenerico::setName(std::string nombre) {
	nickName = nombre;
}
std::string JugadorGenerico::printName() {
	return nickName;
}