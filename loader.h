#include "basics.h"
#include <iostream>

bool askYN(){
	char answer = ' ';
	bool positive = false;
	bool negative = false;

	while (!positive || !negative){
		cin >> answer;
		positive = answer == 'y' || answer == 'Y';
		negative = answer == 'n' || answer == 'N';	
	}

	if (positive)
		return true;
	else 
		return false;

}


void readRace(Game g){
	Race newRace;
	
	cout << "Race name:" << endl;
	cin >> newRace.name; 
	
	int featureNum;
	cout << "How many racial features does it have?" << endl;
	cin >> featureNum;

	for (int i = 1; i<=featureNum; i++){
		raceFeat f;
		cout << "Name of feature #" << i << ':' << endl;
		cin >> f.name;
		cout << "Text: " << endl;
		cin >> f.text;
		cout << "Does it have a number of uses? [y/n]" << endl;
		if ( askYN() ){
			cout << "How many uses per rest?" << endl;
			cin >> f.uses;
			cout << "Short rest? [y/n]" << endl;
			f.longRest = askYN(); 
		}
	}

	

}

