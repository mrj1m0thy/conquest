#include <iostream>
#include <time.h>
#include "map.h"
#include "AI.h"
#include "Output.h"
#include "GameSingleton.h"

using namespace std;

void main()
{
	srand(static_cast<int>(time(0)));

	string option;
	bool quit = false;
	string answer;

	Output output;

	while (!quit)
	{
		output.StartMenu();

		cout << "What would you like to do?:" << endl;
		cout << "1. Start Game with Default Map" << endl;
		cout << "2. Create Map" << endl;
		cout << "Choice: ";
		
		cin >> answer;

		if (answer[0] == '1')
		{
			GameSingleton *game;
			game = GameSingleton::getInstance();
			game->startGame();
		}
		else
		{
			map newMap;
			newMap.createMap();
		}

		cout << "Would you like to quit? (Y/N): ";
		cin >> answer;
	}
}


