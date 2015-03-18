#include "Player.h"
#include "Battle.h"
#include "AI.h"

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
	void reinforcementPhase(AI);

	void attackPhase(Player);
	void attackPhase(AI);

	void fortification(Player);
	void fortification(AI);


	int numberOfPlayers;
	Player* players;
	AI* computers;

	Country Canada;
	Country USA;
	Country Mexico;
};

#endif