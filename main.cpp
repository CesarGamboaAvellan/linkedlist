#include "Mazo.h"
#include <iostream>
#include "Juego.h"
#include <time.h>

int main() {

	srand(time(NULL));
	Juego partidaNueva;
	partidaNueva.iniciarPartida();

	return 0;
}