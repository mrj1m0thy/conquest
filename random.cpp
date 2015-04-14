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

void random::fortification(Player* user)
{
	vector<Country*> countries = user->GetCountries();
	vector<Country*> temp;
	int max;
	int index;
	for (size_t i = 0; i < countries.size(); i++)
	{
		Country** a = countries[i]->getAdjacent();

		for (int j = 0; j < countries[i]->getAdjacentCount(); j++)
		{
			if (a[j]->occupiedBy->name == user->name)
			{
				temp.push_back(a[j]);
			}
		}
	}

	max = 0;
	index = 0;
	Country** country = NULL;
	if (temp.size() > 0)
	{
		for (int k = 0; k < temp.size(); k++)
		{
			int tmp = 0;
			for (int j = 0; j < temp[k]->getAdjacentCount(); j++)
			{
				Country** a = countries.at(k)->getAdjacent();
				if ((*a)->occupiedBy->name != user->name)
				{
					tmp++;
					country = a;
				}

			}
			if (tmp > max)
			{
				max = tmp;
				index = k;
			}
		}

		temp[index]->numberOfPieces = (*country)->numberOfPieces - 1;
		(*country)->numberOfPieces = 1;
	}
}