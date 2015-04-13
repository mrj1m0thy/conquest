/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file implements the Battle class along with the Die structure. It is used to define the battle phase of risk.
*/

#include <iostream>
#include <ctime>
#include "Battle.h"
#include "Country.h"

using namespace std;

Battle::Battle(Country* attack, Country* defend)
{
	allIn = false;

	cout << "Battle!!!" << endl << endl;
	cout << attack->name << " Vs. " << defend->name << endl << endl;
	cout << "Player " << attack->occupiedBy->name << " Vs. Player " << defend->occupiedBy->name << endl << endl;
	cout << attack->numberOfPieces << " Armies Vs. " << defend->numberOfPieces  << " Armies" << endl << endl;
	
	if (CanBattle(attack, defend))  
	{
		allIn = AllIn();	//Are you all in?
	}

	while (CanBattle(attack, defend)) //Verifies if both have enough armies to continue battling. 
	{
		Roll(attack, defend);

		if (!allIn)	
		{
			if (!WillContinue())	//Continue fight? 
			{
				break;
			}
			else
			{
				allIn = AllIn();	//Are you all in?
			}
		}
	}

	if (IsVictory(attack, defend))	//Did attacker win?
	{
		Conquer(attack, defend);
	}
	else
	{
		cout << "Attacking Player Was Defeated!" << endl << endl;
	}
}

bool Battle::AllIn()
{
	char ans;

	do
	{
		cout << "Are You All In? (Y/N): ";
		cin >> ans;
		cout << endl;

		if (toupper(ans) == 'Y')
		{
			return true;
		}
		else if (toupper(ans) == 'N')
		{
			return false;
		}
	} while (true);
}

bool Battle::CanBattle(Country* attack, Country* defend)
{
	if (attack->numberOfPieces > 1 && defend->numberOfPieces > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Battle::WillContinue()
{
	char ans;

	do
	{
		cout << "Would You Like To Continue? (Y/N): ";
		cin >> ans;
		cout << endl;

		if (toupper(ans) == 'Y')
		{
			return true;
		}
		else if (toupper(ans) == 'N')
		{
			return false;
		}
	} while (true);
}

bool Battle::IsVictory(Country* attack, Country* defend)
{
	if (defend->numberOfPieces == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Battle::Roll(Country* attack, Country* defend)
{
	int attackRoll = 0;
	int defendRoll = 0;
	int tempRoll = 0;

	switch (attack->numberOfPieces) //Depending on the attackers number of pieces he/she get a max amount of die.
	{
		case 2:
			attackRoll = 1;
			break;
		case 3:
			attackRoll = 2;
			break;
		default:
			attackRoll = 3;
	}

	switch (defend->numberOfPieces) //Depending on the defends number of pieces he/she get a max amount of die.
	{
		case 1:
			defendRoll = 1;
			break;
		default:
			defendRoll = 2;
	}

	if (!allIn) //Not all in? How many die do I roll then?
	{
		do
		{
			cout << attack->occupiedBy->name << " Player How Many Die Would You Like To Roll? (1";

			for (int i = 1; i < attackRoll; i++)
			{
				cout << ", " << i + 1;
			}

			cout << "): ";
			cin >> tempRoll;
			cout << endl;
		} while (tempRoll < 1 || tempRoll > attackRoll);

		attackRoll = tempRoll;

		do
		{
			cout << defend->occupiedBy->name << " Player How Many Die Would You Like To Roll? (1";

			for (int i = 1; i < defendRoll; i++)
			{
				cout << ", " << i + 1;
			}

			cout << "): ";
			cin >> tempRoll;
			cout << endl;
		} while (tempRoll < 1 || tempRoll > defendRoll);

		defendRoll = tempRoll;
	}

	srand(static_cast<int>(time(0)));
	
	Die att;
	Die def;

	for (int i = 0; i < attackRoll; i++) //Rolls attackers die.
	{
		att.roles[i] = rand() % 6 + 1;
	}

	for (int i = 0; i < defendRoll; i++) //Rolls defenders die.
	{
		def.roles[i] = rand() % 6 + 1;
	}

	attack->diesRolled = attackRoll;
	defend->diesRolled = defendRoll;

	int attWin = 0;
	int attLoss = 0;
	
	Compare(att, def, attackRoll, defendRoll, attWin, attLoss);
	Casualties(attack, defend, attWin, attLoss);
	Report(attack, defend, attWin, attLoss);
}

void  Battle::Compare(Die& att, Die& def, int attackRoll, int defendRoll, int& attWin, int& attLoss)
{
	
	for (int i = 0; i < attackRoll; i++)	//Sort attackers die, highest to lowest.
	{
		for (int j = 1; j < attackRoll; j++)
		{
			if (att.roles[i] < att.roles[j])
			{
				swap(att.roles[i], att.roles[j]);
			}
		}
	}

	for (int i = 0; i < defendRoll; i++)	//Sort defenders die, highest to lowest.
	{
		for (int j = 1; j < defendRoll; j++)
		{
			if (def.roles[i] < def.roles[j])
				swap(def.roles[i], def.roles[j]);
		}
	}

	for (int i = 0; i < defendRoll; i++)	//Compare pairs of die.
	{
		if (att.roles[i] > def.roles[i])
		{
			attWin++;	//Attack die higher.
		}
		else
		{
			attLoss++;	//Defend die higher or equal.
		}
	}
}

void Battle::Report(Country* attack, Country* defend, int attWin, int attLoss)
{
	cout << "Attacking Player Destroyed " << attWin << " Of The Defending Players Armies And Lost " << attLoss << " Armies!" << endl << endl;
}

void Battle::Casualties(Country* attack, Country* defend, int attWin, int attLoss)
{
	//Losses from the attack are subtracted.
	defend->numberOfPieces -= attWin;
	attack->numberOfPieces -= attLoss;
}

void Battle::Conquer(Country* attack, Country* defend)
{
	int ans;

	cout << "Congradulations Attacking Player You Have Defeated Your Opponent!" << endl << endl;

	if (attack->numberOfPieces > 2)
	{
		do
		{
			cout << "How many armies would you like to move? (min " << attack->diesRolled << ", max " << attack->numberOfPieces - 1 << "): ";
			cin >> ans;
			cout << endl;
		} 
		while (ans < attack->diesRolled || ans > attack->numberOfPieces - 1); //Range min and max of pieces to move. 
		
		//Transfer of ownership.
		attack->numberOfPieces -= ans;
		defend->numberOfPieces += ans;
		defend->occupiedBy->name = attack->occupiedBy->name;
	}
	else	//Attacker only has 2 pieces. One stays the other captures.
	{
		//Transfer of ownership.
		attack->numberOfPieces -= 1;
		defend->numberOfPieces += 1;
		defend->occupiedBy->name = attack->occupiedBy->name;
	}
}