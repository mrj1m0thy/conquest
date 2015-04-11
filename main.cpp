#include <iostream>
#include <time.h>
#include "gameDriver.h"
#include "AI.h"
; using namespace std;

void main(){
	srand(static_cast<int>(time(0)));


	//Assignment 3 example of the builder class for gameDriver.
	//By: Tyler Lauzon
	//ID: 7396708
	//Team: J
	//Note: We have yet to implement cards for the player so i wasn't able to save those.
	gameDriver game;
	
	game.start();


}