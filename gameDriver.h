#include "Player.h"
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
	void reinforcementPhase(Player);
	void attackPhase(Player);
	void fortification(Player);

	int numberOfPlayers;
	Player* players;

	Country Canada;
	Country USA;
	Country Mexico;
};

#endif