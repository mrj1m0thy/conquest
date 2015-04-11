/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1
This file defines the Player class. It is an observabled object, extending the Subject class.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <array>
#include <list>
#include <vector>
#include "Subject.h"

using namespace std;

enum Colours { Blue, Red, Yellow, Green, Black, nil };

class Country;
class Continent;

class Player : public Subject
{
private:
	int _renforcements = 0; //Number of renforcements for a given turn.
	int _armiesOwned = 0;
	int _battlesWon = 0;

	Colours _colour;

	vector<Country*> _countriesOwned;		//List of Countires occupied by the Player object.
	vector<Continent*> _continentsOwned;	//List of Continents controled by the Player object.

	void updateContinents();

public:
	string name = "";
	int playerID;
	bool isComputer = false;
	int getID();
	int color;
	int turnOrder;

	Player();
	Player(Colours, string);
	Player(int, string);
	Player(string, int, int);


	void GetCountry(); //The string is the name of the country and not the country itself.

	void AddCountry(Country*); //The string is the name of the country and not the country itself.
	void RemoveCountry(Country*);
	vector<Country*> GetCountries() { return _countriesOwned; }

	void AddContinent(Continent*); //The string is the name of the continent and not the continent itself.
	void RemoveContinent(Continent*);
	vector<Continent*> GetContinents() { return _continentsOwned; }

	void SetColour(Colours c) { _colour = c; Notify(); }
	Colours GetColour(Colours) { return _colour; }

	void SetRenforcements(int r) { _renforcements = r; Notify(); }
	int GetRenforcements() { return _renforcements; }

	void SetArmiesOwned(int a) { _armiesOwned = a; Notify(); }
	int GetArmiesOwned() { return _armiesOwned; }

	void SetBattlesWon(int b) { _battlesWon = b; Notify(); }
	int GetBattlesWon() { return _battlesWon; }
};

#endif