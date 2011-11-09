/*
 * Yatzyfunk.cpp
 *
 *  Created on: 9 nov 2011
 *      Author: christianpettersson
 */
//#include "yatzyheader.h"
#include <iostream>

using namespace std;

/*
 * funktionen ger antal spelare
 */
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
