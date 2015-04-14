#include "random.h"
#include <iostream>

//Unlike the other strategies this one will only go through the countries and attack or not 
//with each only once because if it was to continue till there was no more places to attack 
//would be exactly the same as the aggressive strategy
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