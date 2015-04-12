#include <iostream>
#include <ctime>

#include "Deck.h"

using namespace std;

Deck :: Deck()
{
	int current = 0;

		for (FaceValue f = Infantry; f <= Artillery; f = (FaceValue)(f + 1))
		{
			for (int i = 0; i < 13; i++)
			{
				theDeck[current].SetFaceValue(f);
				current++;
			}
		}

		FaceValue f = Wild; 

		for (int i = 0; i < 2; i++)
		{
			theDeck[current].SetFaceValue(f);
			current++;
		}

		currentCard = -1;
}

void Deck :: Print()
{
	
	theDeck[currentCard].Print();
	
}

void Deck :: Shuffle()
{
	int randomNumber1;
	int randomNumber2;
	int current = 0;

	Card temp;

	srand ((unsigned int)time(NULL));

	if (EmptyDeck() == false)
	{
		do
		{
			randomNumber1 = rand() % 52; //Place in function.
			randomNumber2 = rand() % 52; //Generates Random number.

			temp = theDeck[randomNumber1];
			theDeck[randomNumber1] = theDeck[randomNumber2];
			theDeck[randomNumber2] = temp;
			current++; //Used to stop the loop
		}
		while(current < 520); //So that it doesn't go forever but it suffles more then once.
	}
}

bool Deck :: EmptyDeck()
{
	if (currentCard == 43)
	{
		return (true);
	}
	else 
	{
		return (false);
	}
}

Card Deck :: DealACard()
{
	currentCard++;
	return(theDeck[currentCard]);
}