#ifndef Country_H
#define Country_H

#include <string>
#include "Player.h"

using namespace std;

class Country: public Subject
{
private:
	int posX;
	int posY;
	int targetCount;
	int armySize;
	int adjacentCount;
	string continent;

	Country* adjacent;
	string surrounding;
	Country* targetArray[20];
public:
	Country();
	Country(string, int, int, string, string);
	Country(string, int, int, string, string, int, int);
	Country(string);				//Constructor
	Country(string, Player, int);	//Constructor
	Player* player;

	string getName();
	int getX();
	int getY();
	string listTargets(string);
	string getContinent();
	string getSurrounding();

	void addAdjacent(Country);
	void setContinent(string);
	void addTarget(Country*);
	void conquer(Player*, int);

	string name;
	Player* occupiedBy;		//Keeps track of which player controls this instance of Country.
	bool occupied;
	int numberOfPieces;		//Keeps track of how many pieces are on this instance of Country.
	int diesRolled;			//Keeps track of how many dies rolled per attack. Used in calculations.  

	~Country();
};
#endif