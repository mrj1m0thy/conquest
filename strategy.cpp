#include "strategy.h"
#include <iostream>
#include "aggressive.h"
#include "defensive.h"
#include "random.h"

Strategy::Strategy(){

}

void Strategy::execute(){
	std::cout << "No strategy selected.\n";
}

int Strategy::getStrategy(){
	return ((rand() % 3));

	
}