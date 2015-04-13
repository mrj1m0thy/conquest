#include "strategy.h"
#include <iostream>
#include "aggressive.h"
#include "defensive.h"
#include "random.h"

Strategy::Strategy(){

}

void Strategy::execute(Player* user){
	std::cout << "No strategy selected.\n";
}

int Strategy::getStrategy(){
	return ((rand() % 3));

	
}

int Strategy::reinforce(Player* user) 
{
	return rand() % user->GetCountries().size();
}

void Strategy::fortification(Player* user){
	std::cout << "No strategy selected.\n";
}