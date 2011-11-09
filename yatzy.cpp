/*
 * Yatzyfunk.cpp
 *
 *  Created on: 9 nov 2011
 *      Author: christianpettersson
 */
//#include <iostream>
//#include "yatzyfunk.cpp"
#include <iostream>
#include "yatzyheader.h"
#include "yatzyfunk.cpp"

using namespace std;

int antal_spelare = 0;

int main() {

	tarningar tarning[4];

	//Startar spelet och ange hur många spelare

	system("clear");

	//cout << "YATZY!!" << endl;


	antal_spelare = funk_antalspelare();



	return 0;
}
