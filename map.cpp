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
	numOfContinents = 0;
}

void map::getFileDetails(ifstream& mapFile)
{
	string line;
	string delimeter = "=";

	getline(mapFile, line);
	author = line.substr(line.find(delimeter) + 1);

	getline(mapFile, line);
	image = line.substr(line.find(delimeter) + 1);

	getline(mapFile, line);
	wrap = line.substr(line.find(delimeter) + 1);

	getline(mapFile, line);
	scroll = line.substr(line.find(delimeter) + 1);

	getline(mapFile, line);
	warn = line.substr(line.find(delimeter) + 1);

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
	int adjacentCount = 0;
	string continent; //Country class variable
	string surrounding; //Country class variable
	string adjacentCountries;
	int playerid = 0;
	int numOfArmies = 0;

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
			terri = terri.substr(terri.find(terrdel) + 1);
			playerid = stoi(terri.substr(0, terri.find(terrdel)));
			terri = terri.substr(terri.find(terrdel) + 1);
			numOfArmies = stoi(terri.substr(0, terri.find(terrdel)));
			terri = terri.substr(terri.find(terrdel) + 1);
			surrounding = terri.substr(terri.find(terrdel) + 1);

			for (int i = 0; i < 6; i++)
			{
				if (continents[i].getName() == continent)
					continents[i].addCountry(new Country(name, positionX, positionY, continent, surrounding, playerid, numOfArmies));
			}
			Country c = Country(name, positionX, positionY, continent, surrounding, 0, 0); //create country/territory from the obtained information
			countries[countListNum] = c; //add country to list
			countryList[countListNum] = name; // store a list of country name
			countListNum++;
			numOfCountries++; //increment country count
		}
		createContinents();
		assignAdjacentCountries();
	}
}

void map::createContinents()
{
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < numOfCountries; j++){
			if (continents[i].getName() == countries[j].getContinent())
				continents[i].addCountry(&countries[j]);
		}
	}
}

Country* map::getCountry(string name)
{
	for (int index = 0; index < numOfCountries; index++)
	{
		if (countries[index].getName() == name)
			return &countries[index];
	}
	return NULL;
}


string map::getAuthor()
{
	return author;
}


string map::getImage()
{
	return image;
}

string map::getWrap()
{
	return wrap;
}

string map::getScroll()
{
	return scroll;
}

string map::getWarn()
{
	return warn;
}

void map::loadMap(string file)
{
	ifstream mapFile;
	string output;

	if (file != ""){
		this->setFilename(file);
		mapFile.open(file);
	}
	else{
		this->setFilename("World.map");
		mapFile.open("World.map"); //template used to create class
	}


	if (mapFile.is_open())
	{
		cout << "Loading Map!" << endl;

		while (!mapFile.eof())
		{
			getline(mapFile, output);

			if (output == "[Map]")
			{
				cout << "Getting File Details" << endl;
				getFileDetails(mapFile);
			}

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

Country map::getCountryElement(int i)
{
	return countries[i];
}

void map::outputAllCountries()
{
	for (int index = 0; index < sizeof(countryList) / sizeof(countryList[0]); index++)
		cout << "Country " << index + 1 << ": " << countryList[index] << endl;	//output country list to user
}

void map::getContinentsList()
{
	for (int index = 0; index < sizeof(continents) / sizeof(continents[0]); index++)
		cout << continents[index].getName() << endl; //output continent list to user
}

int map::getContinentSize()
{
	return sizeof(continents) / sizeof(continents[0]);
}

int map::getCountrySize()
{
	return sizeof(countries) / sizeof(countries[0]);
}

//void map::saveMap(string filename, string author, string image, string wrap, string scroll, string warn)
void map::saveMap(string file)
{
	cout << "Saving Map! " << endl;

	ofstream mapFile;
	if (file != ""){
		mapFile.open(file); 
	}
	else{
	mapFile.open(filename); //save content to test file
	}

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
			mapFile << countries[index].occupiedBy->getID() << ",";
			mapFile << countries[index].numberOfPieces << ",";
			mapFile << countries[index].getSurrounding() << endl;
		}

		cout << "Saved!" << endl;
	}

	mapFile.close();
}

void map::createMap()
{
	string filename;
	bool quit = false;
	string author;
	string image;
	string wrap;
	string scroll;
	string warn;
	string country;
	string adjacentCountry;
	string continent;
	string answer;
	string posX;
	string posY;

	int numAdjacent;

	ofstream outfile;

	cin.sync();

	cout << "What would you like to name the file ? : ";
	getline(cin, filename);

	cout << "Author: ";
	getline(cin, author);

	cout << "Image File: ";
	getline(cin, image);

	cout << "Wrap? (yes/no): ";
	getline(cin, wrap);

	cout << "Scroll (Horizontal/Vertical):";
	getline(cin, scroll);

	cout << "Warn (yes/no): ";
	getline(cin, warn);


	do
	{
		adjacentCountry = "";
		cin.sync();
		cout << "Country to be added:" << endl;
		cout << "Country:";
		getline(cin, country);

		cout << "Continent it belongs to:";
		getline(cin, continent);

		cout << "Position X: ";
		cin >> posX;	//_x-coordinate
						//_xpos

		cout << "Position Y: ";
		cin >> posY;

		cout << "How many Adjacent Countries are there?: ";
		cin >> numAdjacent;

		int counter = 0;

		do
		{
			cout << "Adjacent Country #" << counter + 1 << ": ";
			//getline(cin, answer);
			cin >> answer;

			if (counter == 0)
				adjacentCountry = adjacentCountry + answer;
			else
				adjacentCountry = adjacentCountry + "," + answer;

			counter++;

		} while (counter < (numAdjacent));

		Country c(country, stoi(posX), stoi(posY), continent, adjacentCountry, 0, 0);
		addCountry(country, stoi(posX), stoi(posY), continent, adjacentCountry);
		c.setContinent(continent);

		Continent con(continent, 0);

		con.addCountry(&c);
		addContinent(con);

		cout << "Are there any other countries you would like to add?: (Y/N)";
		//getline(cin, answer);
		cin >> answer;

		if (toupper(answer[0]) == 'N')
			quit = true;

	} while (!quit);


	outfile.open(filename);
	setFilename(filename);
	setAuthor(author);
	setImage(image);
	setWrap(wrap);
	setScroll(scroll);
	setWarn(warn);
	saveMap("");

	outfile.close();
}

bool map::continentExists(string con)
{
	for (int i = 0; i < sizeof(continents) / sizeof(continents[0]); i++)
		if (continents[i].getName() == con)
			return true;
	return false;
}

Continent* map::getContinent(string con)
{
	for (int i = 0; i < sizeof(continents) / sizeof(continents[0]); i++)
		if (continents[i].getName() == con)
			return &continents[i];
	return NULL;
}

void map::addCountry(string name, int positionX, int positionY, string continent, string surrounding)
{
	continents[numOfCountries].addCountry(new Country(name, positionX, positionY, continent, surrounding, 0, 0));
	countries[numOfCountries] = Country(name, positionX, positionY, continent, surrounding, 0, 0);
	countryList[numOfCountries] = name;
	numOfCountries++;
}

string map::getContinentOutputInfo(int index)
{
	return (continents[index].getName() + "=" + to_string(continents[index].getArmyNum()));
}

string map::getCountryOutputInfo(int index)
{
	return countries[index].getName() + "," + to_string(countries[index].getX()) + "," + to_string(countries[index].getY()) + "," + countries[index].getContinent() + "," + countries[index].getSurrounding();
}


void map::addCountry(Country c)
{
	continents[numOfCountries].addCountry(new Country(c));
	countries[numOfCountries] = c;
	countryList[numOfCountries] = c.getName();
	numOfCountries++;
}
void map::addContinent(Continent c)
{
	continents[numOfContinents] = Continent(c);
	numOfContinents++;
}

void map::setAuthor(string a)
{
	author = a;
}

void map::setFilename(string file)
{
	filename = file;
}

void map::setImage(string i)
{
	image = i;
}

void map::setScroll(string s)
{
	scroll = s;
}

void map::setWarn(string w)
{
	warn = w;
}

void map::setWrap(string w)
{
	wrap = w;
}

void map::Update(Subject* s)
{
	Notify(s);
}

map::~map()
{

}

string map::getFilename(){
	return filename;
}

bool map::isWinner()
{
	Player* winner = countries[0].occupiedBy;

	for (int i = 1; i < numOfCountries; i++)
	{
		if (winner->playerID != countries[i].occupiedBy->playerID)
			return false;
	}
	return true;
}

int map::getNumOfContinents(){
	return numOfContinents;
}

void map::assignAdjacentCountries()
{
	string adjacentCountries;
	int size;
	string* a = nullptr;

	for (int i = 0; i < numOfCountries; i++)
	{

		adjacentCountries = countries[i].getSurrounding();
		size = countries[i].getAdjacentCount();
		a = new string[size];

		for (int j = 0; j < size; j++)
		{
			a[j] = adjacentCountries.substr(0, adjacentCountries.find(','));
			adjacentCountries = adjacentCountries.substr(adjacentCountries.find(',') + 1);
		}

		for (int c = 0; c < size; c++)
		{
			for (int count = 0; count < numOfCountries; count++)
			{
				if (countries[count].getName() == a[c])
				{
					countries[i].addAdjacent(&countries[count]);
					break;
				}
			}
		}
		delete[] a;
		a = NULL;
	}
	delete a;
}