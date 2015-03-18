#include <iostream>
#include <time.h>
#include "gameDriver.h"
#include "AI.h"
#include <fstream>
#include "Continent.h"
#include "map.h"

using namespace std;

void createMap();

void main()
{
	srand(static_cast<int>(time(0)));
	
	string option;
	bool quit = false;
	string answer;

	gameDriver game;
	game.start();

	while (!quit)
	{
		cout << "Welcome to Online Risk!\n***********************\n" << endl;
		cout << "Create a map." << endl;
		createMap();

		cout << "Would you like to continue? (Y/N): ";
		cin >> answer;

		if (toupper(answer[0]) == 'N')
		{
			quit = true;
			cout << "Thank You for Playing!" << endl;
		}
		system("cls");
	}

	system("pause");
}

void createMap()
{
	map m;
	string filename;
	bool quit = false;
	string author;
	string image;
	string wrap;
	string scroll;
	string warn;
	string country;
	string surrounding1;
	string surrounding2;
	string continent;
	string answer;
	string posX;
	string posY;

	ofstream outfile;

	cout << "What would you like to name the file ? : ";
	cin >> filename;

	cout << "Author: ";
	cin >> author;

	cout << "Image File: ";
	cin >> image;

	cout << "Wrap? (yes/no): ";
	cin >> wrap;

	cout << "Scroll (Horizontal/Vertical):";
	cin >> scroll;

	cout << "Warn (yes/no): ";
	cin >> warn;

	cout << filename << " " << author << " " << image << " " << wrap << " " << scroll << " " << warn << endl;

	do
	{
		cout << "Country to be added:" << endl;
		cout << "Country:";
		cin >> country;

		cout << "Continent it belongs to:";
		cin >> continent;

		cout << "Position X: ";
		cin >> posX;

		cout << "Position Y: ";
		cin >> posY;


		cout << "Adjacent countries (Include them seperatly on each line): ";
		cin >> surrounding1;
		cin >> surrounding2;

		Country c(country, stoi(posX), stoi(posY), continent, surrounding1 + "," + surrounding2);
		m.setCountry(country, stoi(posX), stoi(posY), continent, surrounding1 + "," + surrounding2);
		c.setSurrounding(surrounding1 + "," + surrounding2);
		c.setContinent(continent);

		Continent con(continent, 0);

		con.setCountry(c);
		m.setContinent(con);
		//m.setCountry(country, stoi(posX), stoi(posY), continent, surrounding1 + surrounding2);

		cout << "Are there any other countries you would like to add?: (Y/N)";
		cin >> answer;

		if (answer == "N")
			quit = true;

	} while (!quit);


	outfile.open(filename);

	m.saveMap(filename, author, image, wrap, scroll, warn);

	outfile.close();
}
