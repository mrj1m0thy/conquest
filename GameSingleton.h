#ifndef GAMESINGLETON_H
#define GAMESINGLETON_H

using namespace std;

class GameSingleton
{
private:
	//static bool instanceFlag;
	static GameSingleton *instance;
	GameSingleton() { instance = nullptr; };				//Constructor
public:
	static GameSingleton* getInstance();
	void startGame();
};

#endif