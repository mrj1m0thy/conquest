/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file implements the SimpleStates class.
*/

#include <iostream>
#include "SimpleStats.h"
#include "Player.h"

using namespace std;

SimpleStats::SimpleStats()
{
	type = "SimpleStats";
}

void SimpleStats::Update(Player* p)
{
	cout << "Player: " << p->playerID		<< endl;
	cout << "Countries Controlled: " << p->GetNumCountries() << endl;
	cout << "Armies Owned: " << p->GetArmiesOwned()	<< endl;
	cout << "Cards in Hand: " << p->HandSize() << endl << endl << endl;
}

void SimpleStats::Update(Subject* s)
{
	cout << "You are in stats" << endl;
}