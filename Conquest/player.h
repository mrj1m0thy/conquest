#include <string>
using namespace std;
#ifndef player_H
#define player_H


class player
{
	//Array of owned countries. *Suggestion: Countries might need its own class
	int numOfUnitsPerTurn;		//Increases and decreases depending on board control and Risk cards
	string name;				//Because why not. Will be for interface later
	int playerID;
public:
	player();
	player(int id);
	void addCountry();
	void getCountries();
	void placeUnit();
	void moveUnit();
	int getID();
};

#endif