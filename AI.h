#include <iostream>
#include "Player.h"
#ifndef AI_H
#define AI_H

class AI : public Player
{
	public:
		AI();
		AI(int);
		string strat;
		static const string Strategy[3];
		void deterStrat();
};

#endif