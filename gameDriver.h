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
	gameDriver(map, vector<Player>, vector<AI>, int, int, int);
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
	vector<Player> players;
	vector<AI> computers;

	Country Canada;
	Country USA;
	Country Mexico;
};

class gameDriver::Builder{
	private:
		map builderMap;
		vector<Player> players;
		vector<AI> computers;
		int numberOfPlayers;
		int whosTurn;
		int phaseNum;

	public:
		static const int defaultNumberOfPlayers = 2;
		static const int defaultWhosTurn = 1;
		static const int defaultPhaseNum = 1;

		Builder();

		Builder& setMap(const string);
		Builder& setPlayers(vector<Player>);
		Builder& setComputers(vector<AI>);
		Builder& setNumberOfPlayers(const int);
		Builder& setWhosTurn(const int);
		Builder& setPhaseNum(const int);

		gameDriver build();
};
#endif