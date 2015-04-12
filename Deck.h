#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
	Card theDeck[44];
	int currentCard;
public:
	Deck();	 // Build a proper deck, 42 marked and 2 wild cards.
	
	void Print();	// Print the cards remaining in the Deck.
	
	void Shuffle();	// Must use time as the random generator seed. Shuffle resets the deck to full.
	
	bool EmptyDeck();	// Is the deck empty?
	
	Card DealACard();	 // Pre-condition: The deck is not empty.
};

#endif
