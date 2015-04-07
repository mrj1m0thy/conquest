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
	gameDriver game;
	
	game.start();


	system("pause");
}