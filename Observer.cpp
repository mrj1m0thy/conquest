/*
February 1, 2015
Nicholas Sabelli
COMP 345 Section SI
Assignement #1

This file implements the Battle class along with the Die structure. It is used to define the battle phase of risk.
*/

#include <iostream>

#include "Observer.h"

using namespace std;

Observer::Observer()
{
	type = "Observer";
}

void Observer::Update()
{
	cout << "Observable has changed!" << endl; 
}