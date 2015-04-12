/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file implements the PlayerView class.
*/

#include <iostream>
#include "PercentOfWorld.h"
#include "Player.h"

using namespace std;

void PercentOfWorld::Update(Player* p)
{
	/*
	cout << "Player: " << p->GetColour() << endl;
	cout << "Countries Controlled: " << p->GetCountriesOwned() << endl;
	cout << "Armies Owned: " << p->GetArmiesOwned() << endl;
	cout << "Cards in Hand: " << p->GetHandSize() << endl << endl << endl;
	*/

	double owned = p->GetNumCountries();

	cout << "Percentage of World Owned: " << (owned/3)*100 << "%" << endl << endl << endl;
}