#include <iostream>
#include "Player.h"
#include "strategy.h"
#ifndef AI_H
#define AI_H

class AI : public Player
{
	public:
		Strategy* strat;
		string stratType;
		AI();
		AI(int);
		
};

#endif