#include "random.h"
#include <iostream>

void random::execute(Player* user){
	vector<Country*> countries = user->GetCountries();
	for (size_t i = 0; i < countries.size(); i++)
	{
		Country** a = countries[i]->getAdjacent();
		for (int j = 0; j < countries[i]->getAdjacentCount(); j++)
		{
			if (a[j]->occupiedBy->name != user->name)
			{
				if (countries[i]->getNumberOfPieces() > a[j]->getNumberOfPieces())
				{
					if (rand() % 1){
						Battle battle(countries[i], a[j]);
					}
				}
			}
		}
	}
}

int random::reinforce(Player* user)
{
	return rand()%user->GetCountries().size();
}