#include "gameDriver.h"
#include "player.h"
#include <iostream>
using namespace std;

gameDriver::gameDriver()
{
}

gameDriver::~gameDriver()
{
}

void gameDriver::start()
{
	numberOfPlayers = startPhase();
	mainPhase(numberOfPlayers);
}

//1) startup phase
//(where the number of players and map are chosen, and the countries are randomly assigned to the players);
int gameDriver::startPhase()
{
	cout << "How many players will be participating in this game?";
	cin >> numberOfPlayers;

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = player(); //TODO: Required player parameters 
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
	bool end = false;
	//Passing player to the functions for their phase
	while (end == false){

		for (int id = 0; id < num; id++){
			reinforcementPhase(players[id]);

			attackPhase(players[id]);
			//add break somewhere here if the player wins
			fortification(players[id]);
		}

	}
}

//a) reinforcement phase (where a player is given some armies and places them on some if the countries he owns)
void gameDriver::reinforcementPhase(player user){
	//TODO: Details are for assignment 2
}

//b) attack phase(where a player may declare a series of attacks	from one of his countries to one of its adjacent countries owned by another player)
void gameDriver::attackPhase(player user){
	//TODO: Details are for assignment 2
}

//c) fortification phase (where a player may move some armies from one of his countries to another of his countries)
void gameDriver::fortification(player user){
	//TODO: Details are for assignment 2
}
