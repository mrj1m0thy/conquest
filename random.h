#include "strategy.h"
#include "Country.h"
#include "Battle.h"
#ifndef RANDOM_H
#define RANDOM_H

class random : public Strategy
{
public:
	virtual void execute(Player*);
	
	virtual int reinforce(Player*);
	virtual void fortification(Player*);

};

#endif