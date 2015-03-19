#ifndef map_H
#define map_H

#include <string>
#include <fstream>
#include "Continent.h"
#include "Country.h"
#include "Subject.h"

class map : public Subject
{
public:
	map();
	void getContinents(std::ifstream&);
	void getCountries(std::ifstream&);
	void setCountry(string, int, int, string, string);
	void setContinent(Continent);
	void getCountryList();
	void getContinentsList();

	void loadMap();
	void saveMap(string, string, string, string, string, string);
	~map();

private:
	int numOfCountries;
	std::string countryList[42];
	Continent continents[6];
	Country countries[42];
};

#endif