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




	//Startar spelet och ange hur m�nga spelare

	system("clear");

	funk_logga();


	antal_spelare =2; //funk_antalspelare(); // H�mtar hur m�nga spelare som ska spela
	aktivspelare = 1;



	cout << "Antal spelare �r: " << antal_spelare << endl;
	omgang = 15;
	funk_kasta_tarning(omgang,aktivspelare);





	return 0;
}
