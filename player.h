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
#include <vector>

#include "Subject.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
 
enum Colours { Blue, Red, Yellow, Green, Black, Pink, nil };

class Country;
class Continent;

class Player : public Subject
{
private:
	int _renforcements = 0; //Number of renforcements for a given turn.
	int _armiesOwned = 0;
	int _battlesWon = 0;
	int _battlesLost = 0;
	
	Colours _colour;

	Hand _hand;

	//vector<Card*> _hand;	//List of Cards in the Player's hand.
	vector<Country*> _countriesOwned;	//List of Countires occupied by the Player object.
	vector<Continent*> _continentsOwned;	//List of Continents controlled by the Player object.

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

	Player(Colours, int, int, int);
	
	void AddCountry(Country*); 
	bool hasCountry(string);
	void RemoveCountry(Country*);
	vector<Country*> GetCountries() { return _countriesOwned; }
	int GetNumCountries() { return _countriesOwned.size(); }

	void AddContinent(Continent*); 
	void RemoveContinent(Continent*);
	vector<Continent*> GetContinents() { return _continentsOwned; }

	void SetColour(Colours c) { _colour = c; Notify(this); }
	Colours GetColour() { return _colour; }

	/*
	void AddCard(Card*); 
	void RemoveCard(Card*);
	vector<Card*> GetHand() { return _hand; }	
	*/
	int HandSize() { return _hand.Size(); }
	Hand GetHand() { return _hand; }

	void SetRenforcements(int r) { _renforcements = r; Notify(this); }
	int GetRenforcements() { return _renforcements; }

	void SetArmiesOwned(int a) { _armiesOwned = a; Notify(this); }
	int GetArmiesOwned() { return _armiesOwned; }

	void SetBattlesWon(int b) { _battlesWon = b; Notify(this); }

	int GetBattlesWon() { return _battlesWon; }

	void SetBattlesLost(int b) { _battlesLost = b; Notify(this); }
	int GetBattlesLost() { return _battlesLost; }

	virtual void Notify(Player*);				//Notifies the observer of a change.
};

#endif