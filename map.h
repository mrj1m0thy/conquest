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
	Country getCountryElement(int);
	void getContinentsList();
	void outputAllCountries();
	void assignAdjacentCountries();

	void setAuthor(string);
	void setFilename(string);
	void setImage(string);
	void setWrap(string);
	void setScroll(string);
	void setWarn(string);

	string getAuthor();
	string getFilename();
	string getImage();
	string getWrap();
	string getScroll();
	string getWarn();

	Country getCountry(string);
	bool continentExists(string);
	Continent getContinent(string);
	int getContinentSize();
	int getCountrySize();
	string getContinentOutputInfo(int);
	string getCountryOutputInfo(int);

	void loadMap(string);
	void saveMap(string);
	void createMap();

	~map();

private:
	int numOfCountries;
	string countryList[42];
	Continent continents[6];
	Country countries[42];
	string author;
	string filename;
	string image;
	string wrap;
	string scroll;
	string warn;
};

#endif