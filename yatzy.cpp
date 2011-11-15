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




	//Startar spelet och ange hur många spelare

	system("clear");

	funk_logga();


	antal_spelare = funk_antalspelare(); // Hämtar hur många spelare som ska spela
	aktivspelare = 1;


	cout << "Antal spelare är: " << antal_spelare << endl;

	funk_kasta_tarning(omgang,aktivspelare);



	return 0;
}
