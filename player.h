#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "PlayerView.h" 
#include <array>

using namespace std;
 
enum colours { Blue, Red, Yellow, Green, Black, nil };

class Player
{
private:
	int renforcementsThisTurn;
	int armiesOwned;
	int battlesWon;

	string Countries[100];
	string Continents[20];

	colours colour;
	
	Observer observerList[10];		//List of observers attached to the object.

public:
	//Array of owned countries. *Suggestion: Countries might need its own class
	int numOfUnitsPerTurn;		//Increases and decreases depending on board control and Risk cards
	string name;				//Because why not. Will be for interface later
	int playerID;
	bool isComputer = false;
	int getID();
	int color;
	int turnOrder;

	int nextindex = 0;
	
	Player();
	Player(int id);
	Player(string, int, int);

	void SetColour(colours);
	void GetColour(colours);

	void SetCountries(int);
	void GetCountries(int);
	
	void SetContinent(int);
	void GetContinent(int);

	void SetRenforcementsThisTurn(int);
	void GetRenforcementsThisTurn(int);

	void SetArmiesOwned(int);
	void GetArmiesOwned(int);
	
	void SetBattlesWon(int);
	void GetBattlesWon(int);
	
	void SetObserverList(Observer);
	void GetObserverList(Observer);

	void Attach(Observer);		//Attaches an observer to an observable object.	
	void Detach(Observer);		//Detaches an observer from an observable object.	
	void Notify();				//Notifies the observer of a change.
};

#endif