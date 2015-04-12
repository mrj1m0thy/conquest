#include <string>
#ifndef Country_H
#define Country_H

#include "Player.h"
using namespace std;

class Country
{
public:
	Country();
	Country(string, int, int, string, string, int, int);
	Country(string);				//Constructor
	Country(string, Player, int);	//Constructor

	string getName();
	int getX();
	int getY();
	string listTargets(string);
	string getContinent();
	string getSurrounding();
	int getAdjacentCount();

	void addAdjacent(Country*);
	void setContinent(string);
	void addTarget(Country*);
	void conquer(Player*, int);

	string name;
	Player occupiedBy;		//Keeps track of which player controls this instance of Country.
	bool occupied;
	int numberOfPieces;		//Keeps track of how many pieces are on this instance of Country.
	int diesRolled;			//Keeps track of how many dies rolled per attack. Used in calculations.  

	~Country();

private:
	int posX;
	int posY;
	int targetCount;
	int armySize;
	int adjacentCount;
	string continent;
	int adjacentCounter = 0;

	Country** adjacent;
	string surrounding;
	Country* targetArray[20];
};

#endif