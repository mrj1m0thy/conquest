#include <string>
#include "Country.h"
#ifndef Continent_H
#define Continent_H
using namespace std;

class Continent
{
	public:
		Continent();
		Continent(string, int);

		string getName();
		int getArmyNum();
		void setCountry(Country);
		void addCountry(Country*);
		Player* getOwningPlayer();
		string getOwnerName();

		~Continent();

	private:
		string name;
		int armyNum;
		int numCountries;
		Country* countryArray[42];
		
};

#endif