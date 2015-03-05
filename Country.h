/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file defines the Country class and player enum. Instances of this class are sent to the Battle class. 
*/

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

enum Player { Blue, Red, Yellow, Green, Black, nil };

class Country
{
public:
	string countryName;
	Player occupiedBy;		//Keeps track of which player controls this instance of Country.
	bool occupied;
	int numberOfPieces;		//Keeps track of how many pieces are on this instance of Country.
	int diesRolled;			//Keeps track of how many dies rolled per attack. Used in calculations.  

	Country();						//Constructor
	Country(string);				//Constructor
	Country(string, Player, int);	//Constructor
};

#endif