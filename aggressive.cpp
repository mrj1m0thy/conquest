#include "aggressive.h"
#include <iostream>

void aggressive::execute(){
	std::cout << "Aggressive strategy executed!\n";
}

int aggressive::reinforce(Player* user)
{
	int max = 0;
	int index = 0;
	vector<Country*> countries = user->GetCountries();
	for (size_t i = 0; i < countries.size(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < countries[i]->getAdjacentCount(); j++)
		{
			Country** a = countries.at(i)->getAdjacent();
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

int aggressive::fortification(Player* user)
{
	int max = 0;
	int index = 0;
	vector<Country*> countries = user->GetCountries();
	for (size_t i = 0; i < countries.size(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < countries[i]->getAdjacentCount(); j++)
		{
			Country** a = countries.at(i)->getAdjacent();
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