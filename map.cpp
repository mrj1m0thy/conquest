#include "map.h"
#include "Country.h"
#include "Continent.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

map::map()
{
	numOfCountries = 0; // initialize countries
}

void map::getContinents(ifstream& mapFile) //extract the continents and army values from the .map file
{
	string cont;
	string contdel = "="; //delimeter found on a line

	for (int i = 0; i < 6; i++)
	{
		getline(mapFile, cont);

		continents[i] = Continent(cont.substr(0, cont.find(contdel)), stoi(cont.substr(cont.find(contdel) + 1))); //create a continent
	}
}

void map::getCountries(ifstream& mapFile) //extract countries
{
	string terri; //string that holds each individual line from the file
	string terrdel = ","; //delimeter
	int countListNum = 0; //keeps track the number of countries
	string name; //Country class variable
	int positionX;
	int positionY;
	string continent; //Country class variable
	string surrounding; //Country class variable

	while (!mapFile.eof())
	{
		while (getline(mapFile, terri) && terri != "")
		{
			name = terri.substr(0, terri.find(terrdel)); //parse line with delimeter for (repeated for all fields)
			terri = terri.substr(terri.find(terrdel) + 1);

			positionX = stoi(terri.substr(0, terri.find(terrdel)));
			terri = terri.substr(terri.find(terrdel) + 1);
			positionY = stoi(terri.substr(0, terri.find(terrdel)));

			terri = terri.substr(terri.find(terrdel) + 1);
			continent = terri.substr(0, terri.find(terrdel));
			surrounding = terri.substr(terri.find(terrdel) + 1);

			for (int i = 0; i < 6; i++)
			{
				if (continents[i].getName() == continent)
					continents[i].addCountry(new Country(name, positionX, positionY, continent, surrounding));
			}
			//Country c = Country(name, positionX, positionY, continent, surrounding); //create country/territory from the obtained information
			//countries[countListNum] = c; //add country to list
			countryList[countListNum] = name; // store a list of country name
			countListNum++; //increment country count
		}
	}
}

void map::loadMap()
{
	ifstream mapFile;
	string output;

	mapFile.open("World.map"); //template used to create class

	if (mapFile.is_open())
	{
		cout << "Loading Map!" << endl;

		while (!mapFile.eof())
		{
			getline(mapFile, output);

			if (output == "[Continents]")
			{
				cout << "Getting Continents!" << endl;
				getContinents(mapFile);
			}

			if (output == "[Territories]")
			{
				cout << "Getting Territories!" << endl;
				getCountries(mapFile);
			}
		}

		cout << "Loading Complete!" << endl;
	}
	else
		cout << "Cannot Open File!" << endl;

	mapFile.close();

}

void map::getCountryList()
{
	for (int index = 0; index < sizeof(countryList) / sizeof(countryList[0]); index++)
		cout << "Country " << index + 1 << ": " << countryList[index] << endl;	//output country list to user
}

void map::getContinentsList()
{
	for (int index = 0; index < sizeof(continents) / sizeof(continents[0]); index++)
		cout << continents[index].getName() << endl; //output continent list to user
}

void map::saveMap(string filename, string author, string image, string wrap, string scroll, string warn)
{
	cout << "Saving Map! " << endl;

	ofstream mapFile;
	mapFile.open(filename); //save content to test file

	if (mapFile.is_open())
	{
		mapFile << "[Map]" << endl;
		mapFile << "author=" << author << endl;
		mapFile << "image=" << image << endl;
		mapFile << "wrap=" << wrap << endl;
		mapFile << "scroll=" << scroll << endl;
		mapFile << "warn=" << warn << endl << endl;

		mapFile << "[Continents]" << endl;

		for (int index = 0; index < sizeof(continents) / sizeof(continents[0]); index++)
			mapFile << continents[index].getName() << "=" << continents[index].getArmyNum() << endl;

		mapFile << endl << "[Territories]" << endl;

		for (int index = 0; index < sizeof(countries) / sizeof(countries[0]); index++)
		{
			mapFile << countries[index].getName() << ",";
			mapFile << countries[index].getX() << ",";
			mapFile << countries[index].getY() << ",";
			mapFile << countries[index].getContinent() << ",";
			mapFile << countries[index].getSurrounding() << endl;
		}

		cout << "Saved!" << endl;
	}

	mapFile.close();
}

void map::setCountry(string name, int positionX, int positionY, string continent, string surrounding)
{
	continents[numOfCountries].addCountry(new Country(name, positionX, positionY, continent, surrounding));
	countries[numOfCountries] = Country(name, positionX, positionY, continent, surrounding);
	countryList[numOfCountries] = name;
	numOfCountries++;
}
void map::setContinent(Continent c)
{
	continents[numOfCountries] = Continent(c);
}


map::~map()
{

}