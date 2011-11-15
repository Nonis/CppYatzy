/*
 * Yatzyfunk.cpp
 *
 *  Created on: 9 nov 2011
 *      Author: christianpettersson
 */

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

void funk_spara_tarning(int kast, int aktivspelare);
int funk_rakna_poang(int omgang,int aktivspelare);




struct tarningar {
	   int prickar; // antal prickar på tärning
	   bool spara; // True = tärningen kastas inte om
	   bool anvand; // true = tarningen är redan räknad som poäng

	};


tarningar tarning[5]; //Skapar 5 tärningar med värdet tarning[x].prickar/spara




/*
 * Skriver ut loggan
 */
void funk_logga(){
system("clear");
cout<<"##    ##    ###    ######## ######## ##    ## " << endl;
cout<<" ##  ##    ## ##      ##         ##   ##  ##  " << endl;
cout<<"  ####    ##   ##     ##        ##     ####   " << endl;
cout<<"   ##    ##     ##    ##       ##       ##    " << endl;
cout<<"   ##    #########    ##      ##        ##    " << endl;
cout<<"   ##    ##     ##    ##     ##         ##    " << endl;
cout<<"   ##    ##     ##    ##    ########    ##    " << endl <<endl;


}



/*
 * funktionen ger antal spelare
 */
int funk_antalspelare(){
	int x;
	cout << "Hur många spelare? ";
	cin >> x;
	if (x > 5 || x < 2) {
		system("clear");
		cout << "Fel antal spelar, välj mellan 2 och 5: ";
		cin >> x;
	}
	system("clear");

	return (x) ;
};


/*
 * funktionen kastar tarningarna
 */
	void funk_kasta_tarning(int omgang,int aktivspelare){


	srand(time(0));  // Initialize random number generator.

	int x=0;
	for(x=0; x<5;x++){ // gör så att alla tärningar kastas på första kastet
		tarning[x].spara = false;
		tarning[x].anvand = false;
	}

	int z;
	for(z=0; z<2; z++){ // Kastar alla tärningar 2 ggr, och anropar funk_spara_tarning för att välja vilka tarningar som ska kastas om

		int x=0;
		for(x=0; x < 5; x++){
			if (tarning[x].spara == false){ //om tarningen inte ska sparas slumpas nya prickar

				tarning[x].prickar = int(rand() % 6 + 1);
			}


		}

		funk_spara_tarning(z, aktivspelare); // anropar funktionen för att välja vilka tarningar som ska sparas



	}

	for(x=0; x < 5; x++){  //slumpar dom tarningarna som är kvar: kast nr3
		if (tarning[x].spara == false){
			tarning[x].prickar = int(rand() % 6 + 1);
		}

	}


	//Visar vilka tarningar som skall räknas in i poänget
	system("clear");
	cout << "Dina tärningar är:" << endl;
	cout <<"[" << tarning[0].prickar<<"]  ["<<tarning[1].prickar<<"]  ["<<tarning[2].prickar<<"]  ["<<tarning[3].prickar<<"]  ["<<tarning[4].prickar<<"]"<<endl;
	omgang = 13;
	aktivspelare = 1;

	funk_rakna_poang(omgang, aktivspelare);



}

void funk_spara_tarning(int kast, int aktivspelare){
	int kast_nummer = kast;
	/*
	 * visa tarningarna på skärmen
	 */
	int z=0 ;
	char s[5];


		system("clear");
		cout << "Spelare: " << aktivspelare << " Kast nummer: " << (kast_nummer + 1)<< endl;

		cout << "Välj vilka tarningar du vill spara:" << endl;

		cout <<"[" << tarning[0].prickar<<"]  ["<<tarning[1].prickar<<"]  ["<<tarning[2].prickar<<"]  ["<<tarning[3].prickar<<"]  ["<<tarning[4].prickar<<"]"<<endl;

		cout << endl << "Vilka tärningar vill du spara? ( Svara: j/n ex. 'jjnnj' ) "<<endl;
		cin >> s;

		for(z=0; z<5; z++ ){


			if( s[z]=='j'){
				tarning[z].spara = true;
			}
			else {
				tarning[z].spara = false;
			}
		}

}

int funk_rakna_poang(int omgang, int aktivspelare){
	int poangtemp=0;
	int x, z, y, c;
	int par;
	int parpoang[3];

	switch(omgang){

	case 1 : // sparar ettor
		poangtemp = 0;

		for(x=0;x<5;x++){
			if(tarning[x].prickar == 1 && tarning[x].anvand==false){
				tarning[x].anvand = true;
				poangtemp+=tarning[x].prickar;
			}
		}
		break;

	case 2 :// sparar tvåor
		poangtemp = 0;

		for(x=0;x<5;x++){
					if(tarning[x].prickar == 2 && tarning[x].anvand==false){
						tarning[x].anvand = true;
						poangtemp+=tarning[x].prickar;
					}
				}
		break;

	case 3  : // sparar treor
		poangtemp = 0;

		for(x=0;x<5;x++){
					if(tarning[x].prickar == 3 && tarning[x].anvand==false){
						tarning[x].anvand = true;
						poangtemp+=tarning[x].prickar;
					}
				}
		break;

	case 4 : // sparar fyror
		poangtemp = 0;

		for(x=0;x<5;x++){
					if(tarning[x].prickar == 4 && tarning[x].anvand==false){
						tarning[x].anvand = true;
						poangtemp+=tarning[x].prickar;
					}
				}
		break;

	case 5 : // sparar femmor
		poangtemp = 0;

		for(x=0;x<5;x++){
					if(tarning[x].prickar == 5 && tarning[x].anvand==false){
						tarning[x].anvand = true;
						poangtemp+=tarning[x].prickar;
					}
				}
		break;

	case 6 : // sparar sexor
		poangtemp = 0;

		for(x=0;x<5;x++){
			if(tarning[x].prickar == 6 && tarning[x].anvand==false){
				tarning[x].anvand = true;
				poangtemp+=tarning[x].prickar;
			}
		}
		break;

	case 7 : // sparar det högsta paret


		poangtemp = 0;
		par=0;
		parpoang[0]=0;
		parpoang[1]=0;
		parpoang[2]=0;

		for(x=0;x<5;x++){
			for(z=0;z<5;z++){
				if(tarning[x].prickar == tarning[z].prickar && z!=x && tarning[x].anvand == false && tarning[z].anvand == false){
					tarning[x].anvand = true;
					tarning[z].anvand = true;
					parpoang[par]+=tarning[x].prickar;
					parpoang[par]+=tarning[z].prickar;
					par++;
				}
			}
		}

		if(par == 1){
			for(x=0;x<5;x++){
				poangtemp = parpoang[0];
			}
		}else if(par == 2){
			if(parpoang[0]>parpoang[1]){
				poangtemp = parpoang[0];
			}
			else{
				poangtemp = parpoang[1];
			}
		}

		break;

	case 8 : //sparar två par

		poangtemp = 0;
		par=0; //antal par
		parpoang[0]=0;
		parpoang[1]=0;
		parpoang[2]=0;

		for(x=0;x<5;x++){
			for(z=0;z<5;z++){
				if(tarning[x].prickar == tarning[z].prickar && z!=x && tarning[x].anvand == false && tarning[z].anvand == false){
					tarning[x].anvand = true;
					tarning[z].anvand = true;
					parpoang[par]+=tarning[x].prickar;
					parpoang[par]+=tarning[z].prickar;
					par++;
				}
			}
		}


		 if(par == 2){

			poangtemp += parpoang[0];

			poangtemp += parpoang[1];
		}

		break;

	case 9 : // sparar triss

		poangtemp = 0;
				y=0; //antal par
				parpoang[0]=0;
				parpoang[1]=0;
				parpoang[2]=0;

				for(x=0;x<5;x++){
					for(z=0;z<5;z++){
						for(y=0;z<5;z++){

							if(tarning[x].prickar == tarning[z].prickar && tarning[z].prickar == tarning[y].prickar && z!=x && x!=y && tarning[x].anvand == false && tarning[z].anvand == false && tarning[y].anvand == false){
							tarning[x].anvand = true;
							tarning[z].anvand = true;
							tarning[y].anvand = true;
							poangtemp+=tarning[x].prickar;
							poangtemp+=tarning[z].prickar;
							poangtemp+=tarning[y].prickar;
							}
						}
					}
				}

		break;

	case 10 : //sparar fyrtal

			poangtemp = 0;

			for(x=0;x<5;x++){
				for(z=0;z<5;z++){
					for(y=0;z<5;z++){
						for(c=0;c<5;c++){
							if(tarning[x].prickar == tarning[z].prickar && tarning[z].prickar == tarning[y].prickar && tarning[z].prickar == tarning[c].prickar && z!=x && x!=y && x!=c  && tarning[x].anvand == false && tarning[z].anvand == false && tarning[y].anvand == false && tarning[c].anvand == false){
								tarning[x].anvand = true;
								tarning[z].anvand = true;
								tarning[y].anvand = true;
								tarning[c].anvand = true;
								poangtemp+=tarning[x].prickar;
								poangtemp+=tarning[z].prickar;
								poangtemp+=tarning[y].prickar;
								poangtemp+=tarning[c].prickar;
							}
						}
					}
				}
			}

		break;

	case 11 : // liten stege

		poangtemp = 0;
		y=0;
		c=0;

		for(y=1;y<6;y++){
			for(x=0;x<5;x++){
				if(tarning[x].prickar == y && tarning[x].anvand==false){
					tarning[x].anvand = true;
					c++;
					break;
				}
			}
		}

		if(c==5){
			for(x=0;x<5;x++){
				poangtemp+=tarning[x].prickar;
			}

		}

		break;

	case 12 : //stor stege

		poangtemp = 0;
		y=0;
		c=0;

		for(y=2;y<7;y++){
			for(x=0;x<5;x++){
				if(tarning[x].prickar == y && tarning[x].anvand==false){
					tarning[x].anvand = true;
					c++;
					break;
				}
			}
		}
		cout << endl << c << endl;

		if(c==5){
			for(x=0;x<5;x++){
				poangtemp+=tarning[x].prickar;
			}

		}


		break;

	case 13 : // Kåk FIXA

				poangtemp = 0;
				y=0;
				par=0;
				bool ettpar;
				ettpar = false;
				parpoang[0]=0;
				parpoang[1]=0;
				parpoang[2]=0;

				for(x=0;x<5;x++){
					for(z=0;z<5;z++){
						for(y=0;z<5;z++){

							if(tarning[x].prickar == tarning[z].prickar && tarning[z].prickar == tarning[y].prickar && z!=x && x!=y && tarning[x].anvand == false && tarning[z].anvand == false && tarning[y].anvand == false){
 /*FIXA*/					tarning[x].anvand = true;
							tarning[z].anvand = true;
							tarning[y].anvand = true;
							par++;
							break;
							}
						}
					}
				}


				for(x=0;x<5;x++){
					for(z=0;z<5;z++){
						if(tarning[x].prickar == tarning[z].prickar && z!=x && tarning[x].anvand == false && tarning[z].anvand == false && ettpar == false){
							tarning[x].anvand = true;
							tarning[z].anvand = true;
							ettpar=true;
							par++;
							par++;
							par++;
							par++;
							break;
						}
					}
				}

			if(par==5){
				for(x=0;x<5;x++){
					poangtemp+=tarning[x].prickar;
				}

			}
				cout << endl << poangtemp << endl;

		break;

	case 14 :

		break;

	case 15 :

		break;

	case 16 :

		break;
	}


}

