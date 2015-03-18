#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{

}

Player::Player(int id)
{
	playerID = id;
	colour = Blue;
	renforcementsThisTurn = 10;
	armiesOwned = 10;
	battlesWon = 10;
}

int Player::getID()
{
	return playerID;
}

Player::Player(string name, int color, int turnOrder)
{
	this->name = name;
	this->color = color;
	this->turnOrder = turnOrder;
}

void Player::Attach(Observer s)
{
	observerList[nextindex++] = s;
	cout << s.type << " Subscribed" << endl;
}

void Player::Detach(Observer s)
{
	cout << s.type << "Unsubscribed" << endl;
}

void Player::Notify()
{
	cout << "Notify" << endl;

	for each (Observer s in observerList)
	{
		s.Update();
	}
}

void Player::SetColour(colours)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetColour(colours)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::SetCountries(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetCountries(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::SetContinent(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetContinent(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::SetRenforcementsThisTurn(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetRenforcementsThisTurn(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::SetArmiesOwned(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetArmiesOwned(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::SetBattlesWon(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetBattlesWon(int)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::SetObserverList(Observer)
{
	Notify();	//Notify observer that a change has been made.
}

void Player::GetObserverList(Observer)
{
	Notify();	//Notify observer that a change has been made.
}