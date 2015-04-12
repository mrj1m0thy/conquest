/*
April 8, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #3

This file defines an abstract class Statistics a derived class of type Observer. This file is used as part of a Decorator pattern.
*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include "Observer.h"

using namespace std;

class Statistics : public Observer
{
public:
	Statistics() {};		//Constructor
	virtual void Update(Subject* s) = 0;	//Updates the Observer
	virtual void Update(Player* p) = 0;	//Updates the Observer
};

#endif