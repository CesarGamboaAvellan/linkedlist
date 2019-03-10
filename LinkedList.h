#pragma once
#pragma once
#include "JugadorGenerico.h"
#include "Mazo.h";

class LinkedList {
public:
	LinkedList();
	void AddNode(JugadorGenerico* addData);
	bool contadorDePuntos(int);
	void ManejoDeNodos(int);
	void imprimirResultados(int);

private:
	// mazo que se va a utilizar para repartir cartas
	// cada vez que se recorra la lista
	int i = 0;
	Mazo mazo;
	bool ganador = false;
	typedef  struct node {
		JugadorGenerico data;
		node* next;
	}*nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;
};