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
	armySize = 0;
	name = "Neverland";
	occupied = false;
	occupiedBy = nil;
	numberOfPieces = 0;
	diesRolled = 0;
}

Country::Country(string cName)
{
	name = cName;
	occupied = false;
	occupiedBy = nil;
	numberOfPieces = 0;
	diesRolled = 0;
}

Country::Country(string cName, Player colour, int pieces)
{
	name = cName;
	occupied = true;
	occupiedBy = colour;
	numberOfPieces = pieces;
	diesRolled = 0;
}

Country::Country(string n, int positionX, int positionY, string cont, string surround)
{
	name = n;
	posX = positionX;
	posY = positionY;
	continent = cont;
	surrounding = surround; //this variable keeps stores nearby territories/territories
}

//getters for all local variables
string Country::getName()
{
	return name;
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

string Country::getSurrounding()
{
	return surrounding;
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
	this->player = player;
	this->armySize = armySize;
}

Country::~Country()
{

}