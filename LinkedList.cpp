#include <cstdlib>
#include <iostream>
#include "JugadorGenerico.h"
#include "LinkedList.h"
#include "Mano.h";
#include <fstream>

LinkedList::LinkedList() {
	head = NULL;
	curr = NULL;
	temp = NULL;
	mazo.inicializar();
	mazo.barajar();
}
void LinkedList::AddNode(JugadorGenerico* addData) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = *addData;
	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
	// si no hay ningun elemento en la lista
	else {
		head = n;
	}
}

void LinkedList::ManejoDeNodos(int numeroDeJugadores) {
	char opcionesDeJuego = 't';
	curr = head;
	int num = 0;
	// Entregar las dos primeras cartas del juego
	while (curr != NULL) {
			curr->data.pedirCarta(&mazo.tomarCarta(num));
			curr->data.pedirCarta(&mazo.tomarCarta(num+1));
			curr = curr->next;
			num = num+2;
		}
	int i = num;
	// que se les de una oportunidad de agregar carta
	// el contador se incrementa al final del ciclo
	int counter = 0;
	int puntosDelDealer = 0;
	// while thereIsAWin != true, do this
	while (!ganador && (opcionesDeJuego != 's') && (counter<1)) {
		
		std::cout << std::endl;
		curr = head;
		while (curr != NULL) {
			if (curr->data.printName() == "Dealer") {
				// asignamos los puntos del dealer a una variable
				// para luego calcular si se gano o perdio la partida para
				// los jugadores
				puntosDelDealer = puntosDelDealer + curr->data.mostrarTotal();
				curr = curr->next;
			}
			else {
				do {
					std::cout << "------------------" << std::endl;
					std::cout << curr->data.printName() << std::endl;
					curr->data.mostrarMano();
					std::cout << "Total: " << curr->data.mostrarTotal() << std::endl;

					// ganador si tiene 21

					std::cout << "------------------" << std::endl;
					std::cout << std::endl;

					std::cout << "Opciones de Juego" << std::endl;
					std::cout << std::endl;
					std::cout << "(D)eme Carta  ";
					std::cout << "(P)asar ";
					std::cout << "(G)uardarPartida ";
					std::cout << "(S)alir ";
					std::cout << std::endl;

					std::cin >> opcionesDeJuego;

					if (opcionesDeJuego == 'd') {
						if (i <= 52) {
							curr->data.pedirCarta(&mazo.tomarCarta(i));
							i++;
						}
						else
						{
							std::cout << "no quedan mas cartas en el mazo" << std::endl;
						}
						
					}
					if (opcionesDeJuego == 'p') {
						curr = curr->next;
					}
					if (opcionesDeJuego == 'g') {
						std::cout << "Partida Guardada" << std::endl;
						std::ofstream outfile;
						outfile.open("partidaGuardada");
						outfile << curr->data.printName();
						outfile << "Total de puntos: "<<curr->data.mostrarTotal();
						outfile.close();
					}
					if (opcionesDeJuego == 's') {
						std::cout << "Saliendo" << std::endl;
						opcionesDeJuego = 's';
						exit(1);;
					}
				}while (opcionesDeJuego != 's' || opcionesDeJuego != 'p');
			}
		}
		counter++;
	}
	system("CLS");
	imprimirResultados(puntosDelDealer);
}
bool LinkedList::contadorDePuntos(int puntos) {
	if (puntos == 21) {
		return true;
	}
	else return false;
}
void LinkedList::imprimirResultados(int puntosDealer) {
	std::cout << "-----Mostrando Resultados de la partida------" << std::endl;
	std::cout << "Puntos del Dealer: " << puntosDealer << std::endl;
	std::cout << std::endl;
	curr = head;
	while (curr != NULL) {
		if (puntosDealer == 21) {
			std::cout <<  curr->data.printName() << " ha perdido. La casa tiene 21";
		}
		if (curr->data.mostrarTotal() == 21) {
			std::cout <<  curr->data.printName() << " ha ganado la partida. Tiene 21!";
			std::cout << std::endl;
		}
		if ((curr->data.mostrarTotal() < puntosDealer) && (puntosDealer< 21)) {
			std::cout << curr->data.printName() << " ha perdido la partida!";
			std::cout << std::endl;
		}
		if ((curr->data.mostrarTotal() < 21) && (puntosDealer > 21)) {
			std::cout << curr->data.printName() << " ha ganado ";
			std::cout << "la casa se paso de 21";
			std::cout << std::endl;
		}
		if ((curr->data.mostrarTotal() == puntosDealer)) {
			std::cout << "La partida termino en empate";
		}
		else {
			std::cout << curr->data.printName();
			std::cout << "Puntos totales en mano: ";
			std::cout << curr->data.mostrarTotal();
		}
		curr = curr->next;
	}

}
