/*
Game Driver by Tyler Lauzon

Thought process:
First thing is first, a general idea of the process that the game driver needs has been given so
all thats needs to be done is for it to be converted to code.
The functions were written down for each phase, then from there it was seeing how they were
going to be linked together and what kind of information will be passed back and forth.
The design of the driver was inspired simply from the phases and their ordering. I was aiming
for a simple yet sturdy base to the upcoming project.
Game rules:
The rules for the driver are simple. Each player gets his/her turn to go through all the phases of the game.
Each player has their chance to place new units at the beginning of his/her turn followed by
an attack on adjacent countries. Then finally they can move their units around to fortify certain positions.

Players however will not be given any individual benefits unless they are earned (posession of
a continent or Risk card) in order to keep the games equal for all.
*/

#include "gameDriver.h"
#include "player.h"
#include <iostream>
using namespace std;

gameDriver::gameDriver()
{
	Canada = Country("Canada", Red, 5);	//Instanciate countries for battle.
	USA = Country("USA", Blue, 7);
	Mexico = Country("Mexico", Green, 3);
}

gameDriver::~gameDriver()
{
}

void gameDriver::start()
{
	startPhase();
	mainPhase(numberOfPlayers);
}

//1) startup phase
//(where the number of players and map are chosen, and the countries are randomly assigned to the players);
void gameDriver::startPhase()
{
	cout << "This is the beginning of the start phase\n\n\n";
	system("pause");

	cout << "How many players will be participating in this game?";
	cin >> numberOfPlayers;

	players = new player[numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = player(i); //TODO: Required player parameters 
	}
	
	//TODO: Call to maps section for available maps and once chosen, a returned map.

	//randomly assign countries (Probably something that will have to be done in maps section...)
}

/*
the main play phase (a round-robin turn-based phase where the players are allowed to reinforce, attack and
move). The sub-phases of the main phase are:
*/
void gameDriver::mainPhase(int num)
{
	cout << "This is the beginning of the main phase\n\n\n";
	system("pause");

	bool end = false;
	//Passing player to the functions for their phase
	
	while (end == false){

		for (int id = 0; id < num; id++){
			cout << "\nPlayer " << players[id].getID() << " turn\n";
			cout << "------------------------------------------\n";
			reinforcementPhase(players[id]);

			attackPhase(players[id]);
			//add break somewhere here if the player wins
			fortification(players[id]);
		}
		
		end = true;	//For testing
		cout << "Game is over!\n\n";
	}
}

//a) reinforcement phase (where a player is given some armies and places them on some if the countries he owns)
void gameDriver::reinforcementPhase(player user){
	//TODO: Details are for assignment 2
	cout << "This is the reinforcement phase for player " << user.getID() << endl;
	system("pause");

}

//b) attack phase(where a player may declare a series of attacks	from one of his countries to one of its adjacent countries owned by another player)
void gameDriver::attackPhase(player user){
	//TODO: Details are for assignment 2
	cout << "This is the attack phase for player " << user.getID() << endl;
	Battle battle1(USA, Mexico);		//Instancies battles to be carried out.
	Battle battle2(Canada, USA);
	Battle battle3(Mexico, USA);
	system("pause");
}

//c) fortification phase (where a player may move some armies from one of his countries to another of his countries)
void gameDriver::fortification(player user){
	//TODO: Details are for assignment 2
	cout << "This is the fortification phase for player " << user.getID() << endl;
	system("pause");
}
