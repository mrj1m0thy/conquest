#ifndef player_H
#define player_H
#include <string>

class player
{
	public:
		player();
		addCountry();
		getCountries();
		placeUnit();
		moveUnit();
	private:
		//Array of owned countries. *Suggestion: Countries might need its own class
		int numOfUnitsPerTurn;		//Increases and decreases depending on board control and Risk cards
		string name;				//Because why not. Will be for interface later
}

#endif