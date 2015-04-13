#include "GameSingleton.h"
#include "gameDriver.h"
#include <string>

using namespace std;

GameSingleton* GameSingleton::instance = NULL;

GameSingleton* GameSingleton::getInstance()
{
	if (!instance)
	{
		instance = new GameSingleton();
		return instance;
	}
	else
		return instance;
}

void GameSingleton::startGame()
{
	gameDriver game;
	game.start();
}