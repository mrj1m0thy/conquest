#include "player.h"

player::player(){

}

player::player(int id){
	playerID = id;
}

int player::getID(){
	return playerID;
}