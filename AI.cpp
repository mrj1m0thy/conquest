#include "AI.h"

AI::AI(int id)
{
	isComputer = true;
	playerID = id;
	name = "CPU";
	strat = Strategy[((rand() % 3))];
}