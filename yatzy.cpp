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


	tarningar tarning[5]; //Skapar 5 tärningar med värdet tarning[x].prickar/spara

	//Startar spelet och ange hur många spelare

	system("clear");

	cout << "YATZY!!" << endl;


	antal_spelare = funk_antalspelare(); // Hämtar hur många spelare som ska spela

	cout << "Antal spelare är: " << antal_spelare;



	return 0;
}
