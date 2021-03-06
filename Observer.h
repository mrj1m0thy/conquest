/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file defines the base Obsever class.
*/

#ifndef OBSERVER_H
#define OBSERVER_H

using namespace std;

class Subject;
class Player;

class Observer
{
public:
	string type = "";

	Observer();				//Constructor
	virtual void Update(Subject* s);	//Updates the Observer
	virtual void Update(Player*) {};
};

#endif