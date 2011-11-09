/*
 * Yatzyfunk.cpp
 *
 *  Created on: 9 nov 2011
 *      Author: christianpettersson
 */
//#include "yatzyheader.h"
#include <iostream>

using namespace std;


struct tarningar {
	   int prickar; // antal prickar pŒ tŠrning
	   bool spara; // True = tŠrningen kastas inte om
	};





int funk_antalspelare(){
	int x;
	cout << "Hur mŒnga spelare? ";
	cin >> x;
	if (x > 5 || x < 1) {
		system("clear");
		cout << "Fel antal spelar, vŠlj mellan 2 och 5: ";
		cin >> x;
	}
	system("clear");

	return (x) ;
};
