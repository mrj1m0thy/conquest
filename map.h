#include <string>
#include <fstream>
#include "Continent.h"
#include "Country.h"
#ifndef map_H
#define map_H

class map : public Observer, public Subject
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
	void createContinents();
	int getNumOfContinents();
	void assignAdjacentCountries();
	int getAdjacentCount();

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

	bool isWinner();
	bool continentExists(string);
	Continent* getContinent(string);

	string getContinentOutputInfo(int);
	string getCountryOutputInfo(int);
	void outputAllCountries();
	Country getCountryElement(int);
	int getContinentSize();
	int getCountrySize();
	Country* getCountry(string);


	void loadMap(string);
	void saveMap(string);
	void createMap();

	void Update(Subject* s) override;	//Updates the Observer

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