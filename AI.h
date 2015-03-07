#include <iostream>
#include "Player.h"
#ifndef AI_H
#define AI_H

string Strategy[] = { "Aggressive", "Defensive", "Random" };

class AI : public Player
{
	public:
		AI(int);
		string strat;
};

#endif