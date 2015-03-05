#include "player.h"
#include "Battle.h"
using namespace std;
#ifndef gameDriver_H
#define gameDriver_H

class gameDriver
{
public:
	void start();
	gameDriver();
	~gameDriver();

private:
	void startPhase();
	void mainPhase(int);
	void reinforcementPhase(player);
	void attackPhase(player);
	void fortification(player);

	int numberOfPlayers;
	player* players;

	Country Canada;
	Country USA;
	Country Mexico;
};

#endif