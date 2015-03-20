#include <iostream>
#include <time.h>
#include "gameDriver.h"
#include "AI.h"
#include <fstream>
#include "Continent.h"
#include "map.h"

using namespace std;

void main()
{
	srand(static_cast<int>(time(0)));

	string option;
	bool quit = false;
	string answer;

	while (!quit)
	{
		cout << "Welcome to Online Risk!\n***********************\n" << endl;

		cout << "What would you like to do?:" << endl;
		cout << "1. Start Game with Default Map" << endl;
		cout << "2. Create Map" << endl;
		cout << "Choice: ";
		cin >> answer;

		if (answer[0] == '1')
		{
			gameDriver game;
			game.start();
		}
		else
		{
			map newMap;
			newMap.createMap();
		}

		cout << "Would you like to quit? (Y/N): ";
		cin >> answer;

		if (toupper(answer[0]) == 'Y')
		{
			quit = true;
			cout << "Thank You for Playing!" << endl;

			system("pause");
		}
		system("cls");
	}
}

