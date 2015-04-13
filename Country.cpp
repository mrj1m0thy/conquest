#include "Country.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Country::Country()
{
	posX = 0;
	posY = 0;
	continent = "";
	surrounding = "";
	targetCount = 0;
	name = "Neverland";
	occupied = false;
	occupiedBy = nullptr;
	numberOfPieces = 0;
	diesRolled = 0;
}

Country::Country(string cName)
{
	name = cName;
	occupied = false;
	occupiedBy = nullptr;
	numberOfPieces = 0;
	diesRolled = 0;
}

Country::Country(string cName, Player colour, int pieces)
{
	name = cName;
	occupied = true;
	occupiedBy = &colour;
	numberOfPieces = pieces;
	diesRolled = 0;
}

Country::Country(string n, int positionX, int positionY, string cont, string surround, int playerid, int numOfArmies)
{
	name = n;
	posX = positionX;
	posY = positionY;
	continent = cont;

	adjacentCount = 1;

	for (int s = 0; s < int(surround.size()); s++)
	{
		if (surround[s] == ',')
			adjacentCount++;
	}

	adjacent = new Country*[adjacentCount];

	//for (int i = 0; i < adjacentCount; i++)
	//{
	//	adjacent[i] = Country(surround.substr(0, surround.find(',')));
	//	surround = surround.substr(surround.find(',') + 1);
	//}

	surrounding = surround; //this variable keeps stores nearby territories/territories

	occupiedBy = &Player(playerid, "player "+(playerid));
	numberOfPieces = numOfArmies;
	diesRolled = 0;
}

int Country::getNumberOfPieces()
{
	return numberOfPieces;
}

void Country::addAdjacent(Country* c)
{
	adjacent[adjacentCounter] = c;
	adjacentCounter++;
}

//getters for all local variables
string Country::getName()
{
	return name;
}

int Country::getAdjacentCount()
{
	return adjacentCount;
}

void Country::setContinent(string c)
{
	continent = c;
}

int Country::getX()
{
	return posX;
}

int Country::getY()
{
	return posY;
}

string Country::getContinent()
{
	return continent;
}

Country** Country::getAdjacent()
{
	return adjacent;
}

string Country::getSurrounding()
{
	return surrounding;
	//string adjacentCountries = "";

	//for (int i = 0; i < adjacentCount; i++)
	//	if (i == 0)
	//		adjacentCountries = adjacentCountries + adjacent[i].getName();
	//	else
	//		adjacentCountries = adjacentCountries + "," + adjacent[i].getName();

	//return adjacentCountries;
}

void Country::addTarget(Country* newTarget) {
	this->targetArray[this->targetCount] = newTarget;
	this->targetCount++;
	return;
}

string Country::listTargets(string separator) {
	string output = "";
	if (this->targetCount > 0) {
		for (int i = 0; i < this->targetCount; i++) {
			output += this->targetArray[i]->name;
			if (i < this->targetCount - 1) {
				output += separator;
			}
		}
	}
	else  {
		output = "[NO TARGETS]";
	}
	return output;
}

void Country::conquer(Player* player, int armySize) {
	this->occupiedBy = player;
	this->numberOfPieces = armySize;
}

Country::~Country()
{

}

Country* Country::findAdjacent(string s){
	for (int i = 0; i < adjacentCount; i++)
	{
		if (adjacent[i]->name == s)
			return adjacent[i];
	}
	cout << "Not found.\n\n";
	return nullptr;
}