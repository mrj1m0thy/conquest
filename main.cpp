#include <iostream>
#include <time.h>
#include "gameDriver.h"
#include "AI.h"
#include "Output.h"

//Used in assign 3
#include "Player.h"	
#include "Country.h"
#include "PlayerView.h"
#include "SimpleStats.h"
#include "StatsDecorator.h"
#include "PercentOfWorld.h"
#include "WinLoss.h"

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

		cout << "Welcome to Risk!\n***********************\n" << endl;

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
	}
}
/*
void main(){
	srand(static_cast<int>(time(0)));

	//Assignment 3 example of the builder class for gameDriver.
	//By: Tyler Lauzon
	//ID: 7396708
	//Team: J
	//Note: We have yet to implement cards for the player so i wasn't able to save those.
	gameDriver game;
	
	game.start();


*/
/*
void main() // Used for Nick's Assignment 3
{
const int numberOfPlayers = 3;
const int numCountries = 3;

Player* one = new Player(Red, 4, 10, 8);
Player* two = new Player(Blue, 5, 4, 10);
Player* three = new Player(Green, 2, 1, 2);

Country* Canada = new Country("Canada", Red, 5);	//Instanciate countries for battle.
Country* USA = new Country("USA", Blue, 7);
Country* Mexico = new Country("Mexico", Green, 3);

Observer* stats = new SimpleStats();
Statistics* pow = new SimpleStats();
Statistics* wl = new SimpleStats();

pow = new PercentOfWorld(pow);
wl = new WinLoss(wl);

one->AddCountry(USA);
two->AddCountry(Canada);
three->AddCountry(Mexico);

one->Attach(stats);
two->Attach(stats);
three->Attach(stats);
one->Attach(pow);
two->Attach(pow);
three->Attach(pow);
one->Attach(wl);
two->Attach(wl);
three->Attach(wl);

cout << "STATS" << endl << endl;

one->Notify(one);
two->Notify(two);
three->Notify(three);

system("pause");
}
*/

