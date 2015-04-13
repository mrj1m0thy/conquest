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

void defensive::fortification(Player* user)
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