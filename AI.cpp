#include "AI.h"

const string AI::Strategy[3] = { "Aggressive", "Defensive", "Random" };

AI::AI(int id)
{
	isComputer = true;
	playerID = id;
	name = "CPU";
}

AI::AI()
{
	isComputer = true;
	name = "CPU";
}

void AI::deterStrat(){
	//TODO: Currently random. Will be replaced with functionality on determining which
	//		Strategy to use.
	//For this to be completed, it will need access to all of the countries owned by this computer
	//to check all of its possible moves to see what his position is.
	strat = Strategy[((rand() % 3))];
}