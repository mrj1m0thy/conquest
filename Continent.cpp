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

//set country to a continent
void Continent::addCountry(Country c)
{
	countryArray[numCountries] = new Country(c);
	numCountries++;
}

void Continent::addCountry(Country* newTerritory) {
	this->countryArray[this->numCountries] = newTerritory;
	this->numCountries++;
	return;
}

Player* Continent::getOwningPlayer() {
	if (this->numCountries > 0) {
		Player* owner = this->countryArray[0]->player;
		for (int i = 1; i < this->numCountries; i++) {
			if (owner != this->countryArray[i]->player) {
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