#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{

}

Player::Player(Colours colour, string playername)
{
	colour = colour;
	name = playername;
}

Player::Player(int id)
{
	playerID = id;
	_colour = Blue;
	_renforcements = 10;
	_armiesOwned = 10;
	_battlesWon = 10;
}

Player::Player(string name, int color, int turnOrder)
{
	this->name = name;
	this->color = color;
	this->turnOrder = turnOrder;
}

int Player::getID()
{ 
	return playerID;
}

void Player::AddCountry(string* c)
{
	_countriesOwned.push_back(c);
}

void Player::RemoveCountry(string* c)
{	
	for (int i = 0; i < _countriesOwned.size(); i++)
	{
		if (_countriesOwned[i] == c)
		{
			_countriesOwned.erase(_countriesOwned.begin() + i);
			break;
		}
	}
}

void Player::AddContinent(string* c)
{
	_continentsOwned.push_back(c);
}
 
void Player::RemoveContinent(string* c)
{
	for (int i = 0; i < _continentsOwned.size(); i++)
	{
		if (_continentsOwned[i] == c)
		{
			_continentsOwned.erase(_continentsOwned.begin() + i);
			break;
		}
	}
}
