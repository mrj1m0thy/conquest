#include <iostream>
#include <string>

#include "Hand.h"

using namespace std;

void Hand::AddCard(Card* c)
{
	_hand.push_back(c);

	//Notify(this);
}

void Hand::RemoveCard(Card* c)
{
	for (int i = 0; i < _hand.size(); i++)
	{
		if (_hand[i] == c)
		{
			_hand.erase(_hand.begin() + i);
			break;
		}
	}

	//Notify(this);
}

void Hand::ViewHand()
{
	if (!IsEmpty())
	{
		for (int i = 0; i < _hand.size(); i++)
		{
			cout << "[Card " << i + 1 << "]: ";

			_hand[i]->Print();

			cout << endl;
		}
	}
	else
	{
		cout << "You have no cards" << endl;
	}
}

bool Hand::TradeIn()
{
	int InfantryCards = 0;
	int CavalryCards = 0;
	int ArtilleryCards = 0;
	int WildCards = 0;

	int trades[3] = {};

	bool goodTrade = false;

	string trade = "";

	if (!IsEmpty())
	{
		for (int i = 0; i < _hand.size(); i++)
		{
			cout << "[Card " << i + 1 << "]: ";

			_hand[i]->Print();

			cout << endl;
		}

		cout << "Select 3 cards to trade in (";

		for (int i = 0; i < _hand.size(); i++)
		{
			if (i != 0)
			{
				cout << ", ";
			}

			cout << i + 1;
		}

		cout << "): ";
		
		getline(cin, trade);

		for (int i = 0; i < 3; i++)
		{
			trades[i] = stoi(trade.substr(0, trade.find(" ")));
			trade = trade.substr(trade.find(" ") + 1);
		}

		if (_hand[trades[0]] == _hand[trades[1]] && _hand[trades[1]] == _hand[trades[2]])
		{
			goodTrade = true;
		}

		else if (_hand[trades[0]] != _hand[trades[1]] && _hand[trades[0]] != _hand[trades[2]] && _hand[trades[1]] != _hand[trades[2]])
		{
			goodTrade = true;
		}

		else if (_hand[trades[0]]->GetFaceValue() == Wild || _hand[trades[1]]->GetFaceValue() == Wild && _hand[trades[2]]->GetFaceValue() == Wild)
		{
			goodTrade = true;
		}

		else
		{
			cout << "Invlaid Trade" << endl; 

			return false; //Trade not accepted.
		}

		if (goodTrade)
		{
			for (int i = 0; i < 3; i++)
			{
				RemoveCard(_hand[trades[0]]);
			}

			return true; //Trade accepted.
		}
	}
	else
	{
		cout << "You have no cards" << endl;

		return false; //Trade not accepted.
	}
}