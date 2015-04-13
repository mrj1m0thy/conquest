#include "strategy.h"
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

class defensive : public Strategy
{
public:
	virtual void execute();
	virtual int reinforce(Player*);
	virtual int fortification(Player*);

};

#endif