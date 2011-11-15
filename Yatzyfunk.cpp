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
void funk_rakna_poang(int omgang,int aktivspelare);




struct tarningar {
	   int prickar; // antal prickar p� t�rning
	   bool spara; // True = t�rningen kastas inte om
	   bool anvand; // true = tarningen �r redan r�knad som po�ng

	};


tarningar tarning[5]; //Skapar 5 t�rningar med v�rdet tarning[x].prickar/spara




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
	cout << "Hur m�nga spelare? ";
	cin >> x;
	if (x > 5 || x < 2) {
		system("clear");
		cout << "Fel antal spelar, v�lj mellan 2 och 5: ";
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
	for(x=0; x<5;x++){ // g�r s� att alla t�rningar kastas p� f�rsta kastet
		tarning[x].spara = false;
		tarning[x].anvand = false;
	}

	int z;
	for(z=0; z<2; z++){ // Kastar alla t�rningar 2 ggr, och anropar funk_spara_tarning f�r att v�lja vilka tarningar som ska kastas om

		int x=0;
		for(x=0; x < 5; x++){
			if (tarning[x].spara == false){ //om tarningen inte ska sparas slumpas nya prickar

				tarning[x].prickar = int(rand() % 6 + 1);
			}


		}

		funk_spara_tarning(z, aktivspelare); // anropar funktionen f�r att v�lja vilka tarningar som ska sparas



	}

	for(x=0; x < 5; x++){  //slumpar dom tarningarna som �r kvar: kast nr3
		if (tarning[x].spara == false){
			tarning[x].prickar = int(rand() % 6 + 1);
		}

	}


	//Visar vilka tarningar som skall r�knas in i po�nget
	system("clear");
	cout << "Dina t�rningar �r:" << endl;
	cout <<"[" << tarning[0].prickar<<"]  ["<<tarning[1].prickar<<"]  ["<<tarning[2].prickar<<"]  ["<<tarning[3].prickar<<"]  ["<<tarning[4].prickar<<"]"<<endl;
	aktivspelare = 1;

	funk_rakna_poang(omgang, aktivspelare);



}

void funk_spara_tarning(int kast, int aktivspelare){
	int kast_nummer = kast;
	/*
	 * visa tarningarna p� sk�rmen
	 */
	int z=0 ;
	char s[5];


		system("clear");
		cout << "Spelare: " << aktivspelare << " Kast nummer: " << (kast_nummer + 1)<< endl;

		cout << "V�lj vilka tarningar du vill spara:" << endl;

		cout <<"[" << tarning[0].prickar<<"]  ["<<tarning[1].prickar<<"]  ["<<tarning[2].prickar<<"]  ["<<tarning[3].prickar<<"]  ["<<tarning[4].prickar<<"]"<<endl;

		cout << endl << "Vilka t�rningar vill du spara? ( Svara: j/n ex. 'jjnnj' ) "<<endl;
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


void funk_rakna_poang(int omgang, int aktivspelare){
	int x,y,poangtemp=0,par, antaltarningar[6] = {0,0,0,0,0,0};

	for(x=0;x<5;x++){
		y=tarning[x].prickar-1;
		antaltarningar[y]++;
	}

switch(omgang){


	case 1: //ettor tv�or treor fyror femmor sexor
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		poangtemp = antaltarningar[omgang-1]*omgang;
		break;




	case 7: // ett par
		for(x=5;x>=0;x--){
			if(antaltarningar[x]>=2){
				poangtemp+= 2 * (x+1);
				break;
			}
		}
		break;



	case 8: // tv� par
		par=0;

		for(x=5;x>=0;x--){

			if(antaltarningar[x]>=4){

				poangtemp+= 4 * (x+1);
				par=2;
				break;

			}else if(antaltarningar[x]>=2){
				poangtemp+= 2* (x+1);
				par++;
			}

		}

		if(par<2){
			poangtemp=0;
		}
		break;





	case 9: //Triss
	case 10: // fyrtal
		for(x=5;x>=0;x--){

			if(antaltarningar[x]>=omgang-6){
				poangtemp+= (omgang-6) * (x+1);
				break;
			}
		}
		break;




	case 11://liten stege
	case 12://stor stege
		y=0;
		for(x=omgang-7;x>=omgang-11;x--){

					if(antaltarningar[x]==1){
						y++;
					}
				}

		if(y==5){

			if(omgang==11){

				poangtemp=15;

			}else if(omgang==12){

				poangtemp=25;

			}
		}
		break;



	case 13: //k�k
		y=0;
		for(x=5;x>=0;x--){

			if(antaltarningar[x]==3){
				poangtemp+= 3 * (x+1);
				y++;
				break;
			}
		}


		for(x=5;x>=0;x--){
			if(antaltarningar[x]==2){
				poangtemp+= 2 * (x+1);
				y++;
				break;
			}
		}

		if(y!=2){
			poangtemp=0;
		}
		break;



	case 14: // Chans

		for(x=5;x>=0;x--){
			poangtemp+= antaltarningar[x]*(x+1);
		}
		break;




	case 15: // YATZY!!!!
		for(x=5;x>=0;x--){
			if(antaltarningar[x]==5){
				poangtemp=50;
				break;

			}
		}


	break;


	}



cout << endl<<endl<<endl << poangtemp << endl;



}
