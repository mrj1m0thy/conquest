#include "strategy.h"
#include "Player.h"
#include "Country.h"
#include "Battle.h"
#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

class aggressive : public Strategy
{
public:
	virtual void execute(Player*);
	virtual int reinforce(Player*);
	virtual void fortification(Player*);
};

#endif