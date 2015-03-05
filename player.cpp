#include "Player.h"
#include <string>
Player::Player(){

}

Player::Player(int id){
	playerID = id;
}

int Player::getID(){
	return playerID;
}

Player::Player(string name, int color, int turnOrder) {
	this->name = name;
	this->color = color;
	this->turnOrder = turnOrder;
}