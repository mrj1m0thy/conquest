#include "Player.h"
#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy {
	public:
		int getStrategy();
		virtual void execute(Player*);
		virtual int reinforce(Player*);
		virtual void fortification(Player*);
		Strategy();
};

#endif