/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file defines PercentOfWorld a derived class of type Observer. It is used in the Decorator pattern.
*/

#ifndef PERCENTOFWORLD_H
#define PERCENTOFWORLD_H

#include "StatsDecorator.h"

using namespace std;

class Player;

class PercentOfWorld : public StatsDecorator
{
public:
	PercentOfWorld(Statistics* decoStat) : StatsDecorator(decoStat){}		//Constructor
	void Update(Subject* s) { decoStat->Update(s); };
	void Update(Player*);
};

#endif