#include "Player.h"
#include "Country.h"
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

Player::Player(Colours c, int r, int a, int b)
{
	_colour = c;
	_renforcements = r;
	_armiesOwned = a;
	_battlesWon = b;
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

	Notify(this);
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

	Notify(this);
}

void Player::AddContinent(Continent* c)
{
	_continentsOwned.push_back(c);

	Notify(this);
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

	Notify(this);
}

void Player::Notify(Player* p)
{
	//cout << "Notify" << endl;

	for (size_t i = 0; i < _observers.size(); i++)
	{
		//TODO check if observer is of type player.
		_observers[i]->Update(p);
	}
}

bool Player::hasCountry(string country){
	for (size_t i = 0; i < _countriesOwned.size(); i++){
		
		if (_countriesOwned[i]->getName() == country)
			return true;
	}
	return false;
}

bool Player::canPlay(){
	for (int i = 0; i < _countriesOwned.size(); i++)
	{
		if (_countriesOwned[i]->numberOfPieces > 1)
			return true;
	}
	return false;
}