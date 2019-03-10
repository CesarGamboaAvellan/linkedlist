#include "Juego.h"
#include "Mazo.h"
#include <iostream>
#include "JugadorGenerico.h"
#include "Dealer.h"
#include "Jugador.h"
#include "Mano.h";
#include "LinkedList.h"
#include <string> 
#include <iostream>



Juego::Juego()
{
	std::cout << "Iniciando Partida de Black Jack" << std::endl;
}


Juego::~Juego()
{
}

void Juego::iniciarPartida() {

	char opcion;
	Mano ManoDelDealer;
	JugadorGenerico* test[8];
	Dealer dealer;
	Jugador jugador1;
	LinkedList mylistadejugadores;
	std::cout << "Bienvenido" << std::endl;
	std::cout << "De cuantos jugadores es la partida? " << std::endl;
	std::cin >> opcion;
	while (!isdigit(opcion)) {
		std::cout << "error, el dato introducido no es numerico, intente de nuevo" <<std::endl;
		std::cout << "De cuantos jugadores es la partida? " << std::endl;
		std::cin >> opcion;
	}
	for (int i = 0; i< (opcion-'0'); i++) {
		char name[30];
		test[i] = new Jugador();
		std::cout << "Cual es el nombre del jugador " << i + 1 << "?" << std::endl;
		std::cin>> name;
		test[i]->setName(name);
		Mano mano;
		test[i]->setMano(mano);
		mylistadejugadores.AddNode(test[i]);
	}
	JugadorGenerico* deal = &dealer;
	test[opcion-'0'] = deal;
	dealer.setName("Dealer");
	deal->setMano(ManoDelDealer);
	
	mylistadejugadores.AddNode(deal);
	// pasar puntero flag aca, para terminar juego
	// pasamos numero de jugadores, para asignar las dos primeras cartas
	mylistadejugadores.ManejoDeNodos(opcion);
}