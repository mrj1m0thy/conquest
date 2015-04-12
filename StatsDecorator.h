/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file defines StatsDecorator a derived class of type Observer. It is used in the Decorator pattern.
*/

#ifndef STATSDECORATOR_H
#define STATSDECORATOR_H

#include "Statistics.h"

using namespace std;

class StatsDecorator : public Statistics
{
protected:
	Statistics* decoStat;
public:
	StatsDecorator(Statistics* decoStat) { this->decoStat = decoStat; };		//Constructor
	void Update(Subject* s) { decoStat->Update(s); };
	void Update(Player* p) { decoStat->Update(p); };
};

#endif