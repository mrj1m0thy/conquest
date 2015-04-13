#include "strategy.h"
#include "Country.h"
#include "Battle.h"
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

class defensive : public Strategy
{
public:
	virtual void execute(Player*);
	virtual int reinforce(Player*);
	virtual void fortification(Player*);

};

#endif