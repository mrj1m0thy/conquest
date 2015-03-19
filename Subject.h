/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file defines the base Subject class.
*/

#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include <vector>
#include "Observer.h"

using namespace std;


class Subject
{
private:
	vector<Observer*> _observers;	//List of observers attached to the object.

public:
	Subject();
	~Subject();
	virtual void Attach(Observer*);		//Attaches an observer to an observable object.	
	virtual void Detach(Observer*);		//Detaches an observer from an observable object.	
	virtual void Notify();				//Notifies the observer of a change.
};

#endif