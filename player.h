
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
public:
	//Array of owned countries. *Suggestion: Countries might need its own class
	int numOfUnitsPerTurn;		//Increases and decreases depending on board control and Risk cards
	string name;				//Because why not. Will be for interface later
	int playerID;
	bool isComputer = false;
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