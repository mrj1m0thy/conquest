/*
March 9, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #2

This file defines SimpleStats a derived class of type Observer. It is used in the Decorator pattern.
*/

#ifndef SIMPLESTATS_H
#define SIMPLESTATS_H

#include "Statistics.h"

using namespace std;

class Player;

class SimpleStats : public Statistics
{
public:
	SimpleStats();		//Constructor
	virtual void Update(Subject*);
	virtual void Update(Player*);
};

#endif
