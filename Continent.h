#include <string>
#include "Country.h"
#ifndef Continent_H
#define Continent_H
using namespace std;

class Continent: public Subject
{
public:
	Continent();
	Continent(string, int);

	string getName();
	int getArmyNum();
	int getNumCountries();
	void addCountry(Country*);
	Player* getOwningPlayer();
	string getOwnerName();
	Country* countryArray[42];
	~Continent();

private:
	string name;
	int armyNum;
	int numCountries;
	

};

#endif