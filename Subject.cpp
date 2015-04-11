#include "Subject.h"
#include <iostream>
#include <string>


Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::Attach(Observer* s)
{
	_observers.push_back(s);

	//cout << s->type << " Subscribed" << endl;
}

void Subject::Detach(Observer* s)
{
	for (int i = 0; i < _observers.size(); i++) 
	{ 
		if (_observers[i] == s)
		{
			_observers.erase(_observers.begin() + i);
			break;
		}
	} 

	cout << s->type << "Unsubscribed" << endl;
}

void Subject::Notify()
{
	//cout << "Notify" << endl;

	for (int i = 0; i < _observers.size(); i++)
	{
		_observers[i]->Update(this);
	}
}

void Subject::Notify(Subject* s)
{
	//cout << "Notify" << endl;

	for (int i = 0; i < _observers.size(); i++)
	{
		_observers[i]->Update(s);
	}
}