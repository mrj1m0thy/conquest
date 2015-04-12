/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file defines WinLoss a derived class of type Observer. It is used in the Decorator pattern.
*/

#ifndef WINLOSS_H
#define WINLOSS_H

#include "StatsDecorator.h"

using namespace std;

class Player;

class WinLoss : public StatsDecorator
{
public:
	WinLoss(Statistics* decoStat) : StatsDecorator(decoStat){}		//Constructor
	void Update(Subject* s) { decoStat->Update(s); };
	void Update(Player*);
};

#endif