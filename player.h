#include <string>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
	//Array of owned countries. *Suggestion: Countries might need its own class
	int numOfUnitsPerTurn;		//Increases and decreases depending on board control and Risk cards
	string name;				//Because why not. Will be for interface later
	int playerID;
	Player();
	Player(int id);
	Player(string, int, int);
	void addCountry();
	void getCountries();
	void placeUnit();
	void moveUnit();
	int getID();
	int color;
	int turnOrder;
};

#endif