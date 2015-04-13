#include <vector>

#include "Card.h"

using namespace std;

#ifndef HAND_H
#define HAND_H

class Hand
{
private:
	vector<Card*> _hand;	//List of Cards in the Player's hand.

public:
	Hand() {};
	~Hand() {};
	void AddCard(Card*);
	void RemoveCard(Card*);
	//vector<Card*> GetHand() { return _hand; }
	
	int Size() { return _hand.size(); }

	bool IsFull() { return (_hand.size() < 5); }
	bool IsEmpty() { return (_hand.size() == 0); }

	void ViewHand();

	bool TradeIn(bool);
	bool isNumber(string);
};

#endif
