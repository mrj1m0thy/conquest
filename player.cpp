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

Player::Player(int id, string playername)
{
	name = playername;
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

void Player::AddCountry(Country* c)
{
	_countriesOwned.push_back(c);
}

void Player::RemoveCountry(Country* c)
{
	for (int i = 0; i < int(_countriesOwned.size()); i++)
	{
		if (_countriesOwned[i] == c)
		{
			_countriesOwned.erase(_countriesOwned.begin() + i);
			break;
		}
	}
}

void Player::AddContinent(Continent* c)
{
	_continentsOwned.push_back(c);
}

void Player::RemoveContinent(Continent* c)
{
	for (int i = 0; i < int(_continentsOwned.size()); i++)
	{
		if (_continentsOwned[i] == c)
		{
			_continentsOwned.erase(_continentsOwned.begin() + i);
			break;
		}
	}
}