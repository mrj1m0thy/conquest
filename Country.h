#include <string>
#ifndef Country_H
#define Country_H

#include "Player.h"
using namespace std;

enum Eplayer { Blue, Red, Yellow, Green, Black, nil };

class Country
{
public:
	Country();
	Country(string, int, int, string, string);
	Country(string);				//Constructor
	Country(string, Player, int);	//Constructor
	string getName();
	int getX();
	int getY();
	string getContinent();
	string getSurrounding();
	Player* player;
	void addTarget(Country*);
	string listTargets(string);
	void conquer(Player*, int);
	~Country();
	string name;
	Player occupiedBy;		//Keeps track of which player controls this instance of Country.
	bool occupied;
	int numberOfPieces;		//Keeps track of how many pieces are on this instance of Country.
	int diesRolled;			//Keeps track of how many dies rolled per attack. Used in calculations.  

private:
	int posX;
	int posY;
	int targetCount;
	int armySize;
	string continent;
	string surrounding;
	Country* targetArray[20];
};

#endif