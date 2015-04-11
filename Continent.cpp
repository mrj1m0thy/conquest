#include "Continent.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Continent::Continent() //contructor 
{
	name = "";
	armyNum = 0;
	numCountries = 0;
}

Continent::Continent(string n, int number) //overloading (if the name and army number is given)
{
	name = n;
	armyNum = number;
	numCountries = 0;
}

string Continent::getName()
{
	return name;
}

int Continent::getArmyNum()
{
	return armyNum;
}

int Continent::getNumCountries(){
	return numCountries;
}

void Continent::addCountry(Country* newTerritory) {
	countryArray[numCountries] = newTerritory;
	numCountries++;
}

Player* Continent::getOwningPlayer() {
	if (this->numCountries > 0) {
		Player* owner = this->countryArray[0]->occupiedBy;
		for (int i = 1; i < this->numCountries; i++) {
			if (owner != this->countryArray[i]->occupiedBy) {
				return NULL;
			}
		}
		return owner;
	}
	else  {
		return NULL;
	}
}

string Continent::getOwnerName() {
	Player* owner = this->getOwningPlayer();
	if (owner == NULL) {
		return "nobody";
	}
	else {
		return owner->name;
	}
}

Continent::~Continent()
{

}