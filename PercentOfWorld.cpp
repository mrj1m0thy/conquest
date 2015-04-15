/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file implements the PercentOfWorld class.
*/

#include <iostream>
#include "PercentOfWorld.h"
#include "Player.h"

using namespace std;

void PercentOfWorld::Update(Player* p)
{
	double owned = p->GetNumCountries();

	cout << "Percentage of World Owned: " << (owned/42)*100 << "%" << endl << endl << endl;
}