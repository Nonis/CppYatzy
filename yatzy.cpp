/*
 * Yatzyfunk.cpp
 *
 *  Created on: 9 nov 2011
 *      Author: christianpettersson
 */


#include <iostream>
#include "yatzyheader.h"


using namespace std;


int main() {


	tarningar tarning[5]; //Skapar 5 t�rningar med v�rdet tarning[x].prickar/spara

	//Startar spelet och ange hur m�nga spelare

	system("clear");

	cout << "YATZY!!" << endl;


	antal_spelare = funk_antalspelare(); // H�mtar hur m�nga spelare som ska spela

	cout << "Antal spelare �r: " << antal_spelare;



	return 0;
}
