/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file implements the Country class and player enum. Instances of this class are sent to the Battle class.
*/

#include <string>
#include "Country.h"

using namespace std;


Country::Country()
{
	countryName = "Neverland";
	occupied = false;
	occupiedBy = nil;
	numberOfPieces = 0;
	diesRolled = 0;
}

Country::Country(string name)
{
	countryName = name;
	occupied = false;
	occupiedBy = nil;
	numberOfPieces = 0;
	diesRolled = 0;
}

Country::Country(string name, Player colour, int pieces)
{
	countryName = name;
	occupied = true;
	occupiedBy = colour;
	numberOfPieces = pieces;
	diesRolled = 0;
}