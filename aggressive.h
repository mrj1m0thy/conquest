#include "strategy.h"
#include "Player.h"
#include "Country.h"
#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

class aggressive : public Strategy
{
public:
	virtual void execute();
	virtual int reinforce(Player*);

};

#endif