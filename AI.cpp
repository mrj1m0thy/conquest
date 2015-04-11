#include "AI.h"
#include "strategy.h"
#include "aggressive.h"
#include "defensive.h"
#include "random.h"

AI::AI(int id)
{
	isComputer = true;
	playerID = id;
	name = "CPU"+to_string(id);

	int num = strat->getStrategy();

	switch (num)
	{
	case 0:
		strat = new aggressive();
		stratType = "aggressive";
		break;
	case 1:
		strat = new defensive();
		stratType = "defensive";
		break;
	case 2:
		strat = new random();
		stratType = "random";
		break;
	}
}

AI::AI(int id, string inStrat)
{
	int result;
	isComputer = true;
	playerID = id;
	name = "CPU"+to_string(id);

	if (inStrat == "aggressive")
		result = 0;
	else if (inStrat == "defensive")
		result = 1;
	else
		result = 2;


	switch (result)
	{
	case 0:
		strat = new aggressive();
		stratType = "aggressive";
		break;
	case 1:
		strat = new defensive();
		stratType = "defensive";
		break;
	case 2:
		strat = new random();
		stratType = "random";
		break;
	}
}

AI::AI()
{
	isComputer = true;
	name = "CPU";

	int num = strat->getStrategy();

	switch (num)
	{
	case 0:
		strat = new aggressive();
		break;
	case 1:
		strat = new defensive();
		break;
	case 2:
		strat = new random();
		break;
	}
}