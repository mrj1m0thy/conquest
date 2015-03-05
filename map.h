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
		void getContinents(std::ifstream&);
		void getCountries(std::ifstream&);
		void setCountry(std::string);
		void getCountryList();
		void getContinentsList();

		void loadMap();
		void saveMap();
		~map();

	private:
		int numOfCountries;
		std::string countryList[42];
		Continent continents[6];
		Country countries[42];
};

#endif