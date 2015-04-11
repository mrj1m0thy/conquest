#include "Player.h"
#include "Battle.h"
#include "map.h"
#include "AI.h"
using namespace std;
#ifndef gameDriver_H
#define gameDriver_H

class gameDriver
{
public:
	void start();
	gameDriver();
	gameDriver(map, Player*, AI*, int, int, int);
	~gameDriver();
	class Builder;

private:
	void startPhase();
	void mainPhase();

	void reinforcementPhase(Player);
	void reinforcementPhase(AI);

	void attackPhase(Player);
	void attackPhase(AI);

	void fortification(Player);
	void fortification(AI);

	void saveGame(string);
	void loadGame(string);

	void mainMenu();
	void startMenu();
	void clearScreen();
	void gameOver();
	void updatePlayerContinents();
	map myMap;
	int whosTurn;
	int phaseNum;
	int numberOfPlayers;
	Player* players;
	AI* computers;
};

class gameDriver::Builder{
	private:
		map builderMap;
		Player* players;
		AI* computers;
		int numberOfPlayers;
		int whosTurn;
		int phaseNum;

	public:
		static const int defaultNumberOfPlayers = 2;
		static const int defaultWhosTurn = 1;
		static const int defaultPhaseNum = 1;

		Builder();

		Builder& setMap(const string);
		Builder& setPlayers(Player*);
		Builder& setComputers(AI*);
		Builder& setNumberOfPlayers(const int);
		Builder& setWhosTurn(const int);
		Builder& setPhaseNum(const int);

		gameDriver build();
};
#endif