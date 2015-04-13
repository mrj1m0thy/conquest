#include "defensive.h"
#include <iostream>

void defensive::execute(Player* user){
	vector<Country*> countries = user->GetCountries();
	for (size_t i = 0; i < countries.size(); i++)
	{
		int j;
		Country** a = countries[i]->getAdjacent();
		vector<Country*> attAdj;
		for (j = 0; j < countries[i]->getAdjacentCount(); j++)
		{
			if (a[j]->occupiedBy->name != user->name)
			{
				if (countries[i]->getNumberOfPieces()*0.4 < a[j]->getNumberOfPieces())
				{
					break;
				}
				else
					attAdj.push_back(a[j]);
			}
		}
		if (j == countries[i]->getAdjacentCount()){
			Battle(countries[i], attAdj[rand() % attAdj.size()]);
		}
	}
}

int defensive::reinforce(Player* user)
{
	int max = 0;
	int index = 0;
	vector<Country*> countries = user->GetCountries();
	for (size_t i = 0; i < countries.size(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < countries[i]->getAdjacentCount(); j++)
		{
			Country** a = countries[i]->getAdjacent();
			if ((*a)->occupiedBy->name == user->name)
				tmp++;
		}
		if (tmp > max)
		{
			max = tmp;
			index = i;
		}
	}
	return index;
}