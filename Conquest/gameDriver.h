#ifndef gameDriver_H
#define gameDriver_H

class gameDriver
{
public:
	void start();
	gameDriver();
	~gameDriver();

private:
	int startPhase();
	void mainPhase(int);
	void reinforcementPhase(player);
	void attackPhase(player);
	void fortification(player);

	int numberOfPlayers;
	player players[];
};

#endif