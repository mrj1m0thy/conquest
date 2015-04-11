#include <string>
#include <fstream>
#include "Continent.h"
#include "Country.h"
#ifndef map_H
#define map_H

class map
{
public:
	map();
	void getFileDetails(ifstream&);
	void getContinents(ifstream&);
	void getCountries(ifstream&);


	void addCountry(string, int, int, string, string);
	void addCountry(Country);
	void addContinent(Continent);
	void getCountryList();
	void getContinentsList();
	string getFilename();
	void createContinents();
	int getNumOfContinents();

	void setAuthor(string);
	void setFilename(string);
	void setImage(string);
	void setWrap(string);
	void setScroll(string);
	void setWarn(string);

	bool isWinner();
	bool continentExists(string);
	Continent getContinent(string);

	void loadMap(string);
	void saveMap(string);
	void createMap();

	Country countries[42];
	Continent continents[6];

	~map();

private:
	int numOfContinents;
	int numOfCountries;
	string countryList[42];
	string author;
	string filename;
	string image;
	string wrap;
	string scroll;
	string warn;
};

#endif