/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file defines the Battle class along with the Die structure. It is used to define the battle phase of risk.
*/

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "Country.h"

using namespace std;

struct Die			//Holds the roll data.
{
	int roles[3];
};

class Battle
{ 	
private:
	 
public:
	bool allIn;

	Battle(Country&, Country&);						//Constructor
	bool CanBattle(Country, Country);				//Checks if there are enough armies for a battle.
	bool IsVictory(Country, Country);				//Verifies if the attacker won if there are not enough armies for a battle.
	void Roll(Country&, Country&);					//Sets up and rolls the die. 
	void Compare(Die&, Die&, int, int, int&, int&);	//Sorts then compares the resulst of the dice rolls.
	void Report(Country, Country, int, int);		//Subtracts the losses of each country.
	void Casualties(Country&, Country&, int, int);	//Outputs the outcome of the attack.
	bool WillContinue();							//Asks player if they would like to continue fighting.
	bool AllIn();									//Asks player if they would like to use the max amount of die.
	void Conquer(Country&, Country&);				//Asks how many armies the attacker want to move to their new concuered country.
};

#endif