/*
Game Driver by Tyler Lauzon

Thought process:
First thing is first, a general idea of the process that the game driver needs has been given so
all thats needs to be done is for it to be converted to code.
The functions were written down for each phase, then from there it was seeing how they were
going to be linked together and what kind of information will be passed back and forth.
The design of the driver was inspired simply from the phases and their ordering. I was aiming
for a simple yet sturdy base to the upcoming project.
Game rules:
The rules for the driver are simple. Each player gets his/her turn to go through all the phases of the game.
Each player has their chance to place new units at the beginning of his/her turn followed by
an attack on adjacent countries. Then finally they can move their units around to fortify certain positions.

Players however will not be given any individual benefits unless they are earned (posession of
a continent or Risk card) in order to keep the games equal for all.
*/

#include "gameDriver.h"
#include "Player.h"
#include <iostream>
#include "aggressive.h"
#include <fstream>

using namespace std;

gameDriver::gameDriver()
{
	myMap.loadMap("myMap.map"); //load contents from sample file downloaded from given website
	whosTurn = 0;
	phaseNum = 0;

	Canada = Country("Canada", Red, 5);	//Instanciate countries for battle.
	USA = Country("USA", Blue, 7);
	Mexico = Country("Mexico", Green, 3);
}

gameDriver::gameDriver(map myMap, Player* players, AI* computers, int numberOfPlayers, int whosTurn, int phaseNum)
{
	this->myMap = myMap;
	this->players = players;
	this->computers = computers;
	this->numberOfPlayers = numberOfPlayers;
	this->whosTurn = whosTurn;
	this->phaseNum = phaseNum;
}

gameDriver::~gameDriver()
{
}

void gameDriver::startMenu(){
	int response;

	clearScreen();
	cout << "Welcome to the game of Risk\n"
		<< "----------------------------------------\n"
		<< "0: Start a new game\n"
		<< "1: Load a game\n\n"
		<< "What would you like to do? ";
	cin >> response;

	if (response == 1)
	{
		string in;

		clearScreen();
		cout << "Saved Games\n"
			<< "--------------------\n";
		system("dir /b saves");
		cout << "\n\nWhich game would you like to load? ";
		cin.ignore();
		getline(cin, in);
		loadGame(in);
	}
}

void gameDriver::start()
{
	startMenu();
	if (phaseNum == 0)
		startPhase();
	mainPhase();
}

//1) startup phase
//(where the number of players and map are chosen, and the countries are randomly assigned to the players);
void gameDriver::startPhase()
{
	clearScreen();
	cout << "This is the beginning of the start phase\n"
		 << "--------------------------------------------\n\n";

	do{
		cout << "How many players will be participating in this game? (max: 6)";
		cin >> numberOfPlayers;
	} while (numberOfPlayers > 6 || numberOfPlayers < 2);

	computers = new AI[6 - numberOfPlayers]();
	for (int i = 0; i < 6 - numberOfPlayers; i++)
	{
		computers[i] = AI(i + 1);
	}

	players = new Player[numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = Player(i + 1);
	}

	phaseNum++;
	//randomly assign countries (Probably something that will have to be done in maps section...)
}

/*
the main play phase (a round-robin turn-based phase where the players are allowed to reinforce, attack and
move). The sub-phases of the main phase are:
*/
void gameDriver::mainPhase()
{
	clearScreen();
	cout << "This is the beginning of the main phase\n"
		 << "-----------------------------------------\n\n";
	system("pause");

	end = false;

	while (end == false){
		if (whosTurn < numberOfPlayers){
			for (int id = whosTurn; id < numberOfPlayers; id++, whosTurn++){
				cout << "\nPlayer " << players[id].getID() << " turn\n";
				cout << "------------------------------------------\n";

				switch (phaseNum){
				case 1:
					reinforcementPhase(players[id]);
					phaseNum++;
				case 2:
					attackPhase(players[id]);
					//add break somewhere here if the player wins
					phaseNum++;
				case 3:
					fortification(players[id]);
					phaseNum = 1;
				}
			}
		}
		for (int id = (whosTurn-numberOfPlayers); id < 6 - numberOfPlayers; id++, whosTurn++){
			cout << "\nComputer " << computers[id].getID() << " turn\n";
			cout << "------------------------------------------\n";

			switch (phaseNum){
			case 1:
				reinforcementPhase(computers[id]);
				phaseNum++;
			case 2:
				attackPhase(computers[id]);
				//add break somewhere here if the computer wins
				phaseNum++;
			case 3:
				fortification(computers[id]);
				phaseNum = 1;
			}
		}

		whosTurn = 0;
		end = true;	//For testing
		clearScreen();
		cout << "Game is over!\n\n";
	}
}

//a) reinforcement phase (where a player is given some armies and places them on some if the countries he owns)
void gameDriver::reinforcementPhase(Player user){
	clearScreen();
	cout << "This is the reinforcement phase for player " << user.getID() << endl;
	cout << "---------------------------------------------------------\n\n";
	mainMenu();
}

void gameDriver::reinforcementPhase(AI comp){
	clearScreen();
	cout << "This is the reinforcement phase for computer " << comp.getID() << endl;
	cout << "---------------------------------------------------------\n\n";
	mainMenu();
}

//b) attack phase(where a player may declare a series of attacks	from one of his countries to one of its adjacent countries owned by another player)
void gameDriver::attackPhase(Player user){
	clearScreen();

	cout << "This is the attack phase for player " << user.getID() << endl;
	cout << "---------------------------------------------------------\n\n";
	Battle battle1(USA, Mexico);		//Instancies battles to be carried out.
	Battle battle2(Canada, USA);
	Battle battle3(Mexico, USA);
	mainMenu();
}

void gameDriver::attackPhase(AI comp){
	clearScreen();

	cout << "This is the attack phase for computer " << comp.getID() << " using the " << comp.stratType << " strategy." << endl;
	cout << "--------------------------------------------------------------------------\n\n";
	
	comp.strat->execute();

	//These battles will have to become dynamic before the strategies can be used.
	Battle battle1(USA, Mexico);		//Instancies battles to be carried out.
	Battle battle2(Canada, USA);
	Battle battle3(Mexico, USA);
	mainMenu();
}

//c) fortification phase (where a player may move some armies from one of his countries to another of his countries)
void gameDriver::fortification(Player user){
	clearScreen();
	cout << "This is the fortification phase for player " << user.getID() << endl;
	cout << "---------------------------------------------------------\n\n";
	mainMenu();
}

void gameDriver::fortification(AI comp){
	clearScreen();
	cout << "This is the fortification phase for computer " << comp.getID() << endl;
	cout << "---------------------------------------------------------\n\n";
	mainMenu();
}

void gameDriver::mainMenu()
{
	int response;
	cout << "Main Menu\n"
		<< "-----------------------------------------------------\n"
		<< "0: Exit game\t"
		<< "1: Save gamestate\t"
		<< "2: Continue\n"
		<< "-----------------------------------------------------\n";
	cin >> response;

	if (response == 0)
		exit(0);
	else if (response == 1){
		string save;

		clearScreen();
		cout << "What would you like to save it as?\n";
		cin.ignore();
		getline(cin, save);
		system("pause");
		saveGame(save);
		exit(0);
	}
}

void gameDriver::clearScreen(){
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void gameDriver::saveGame(string save){
	ofstream outStream;
	outStream.open("saves/"+save, ios_base::trunc);

	outStream << "map=" << myMap.getFilename() << endl
		<< "numberOfPlayers=" << numberOfPlayers << endl
		<< "whosTurn=" << whosTurn << endl
		<< "phaseNum=" << phaseNum << endl
		<< "computers=";
	for (int i = 0; i < 6 - numberOfPlayers; i++)
		outStream << computers[i].stratType << ",";

	outStream.close();
}

void gameDriver::loadGame(string load){
	ifstream inStream;
	inStream.open("saves/" + load);

	if (inStream.is_open())
	{
		string line;
		string thisMap;
		int numberOfPlayers;
		int whosTurn;
		int phaseNum;
		AI* comps;

		getline(inStream, line);
		thisMap = line.substr(line.find('=') + 1);

		getline(inStream, line);
		numberOfPlayers = stoi(line.substr(line.find('=') + 1));

		comps = new AI[6-numberOfPlayers];

		getline(inStream, line);
		whosTurn = stoi(line.substr(line.find('=') + 1));

		getline(inStream, line);
		phaseNum = stoi(line.substr(line.find('=') + 1));

		getline(inStream, line);
		line = line.substr(line.find('=') + 1);
		for (int i = 0; i < 6-numberOfPlayers; i++){
			comps[i] = AI(i+1, line.substr(0, line.find(',')));
			line = line.substr(line.find(',') + 1);
		}
		
		inStream.close();


		*this = gameDriver::Builder().setMap(thisMap).setNumberOfPlayers(numberOfPlayers).setWhosTurn(whosTurn).setPhaseNum(phaseNum).setComputers(comps).build();

	}
	else
	{
		clearScreen();
		cout << "Cannot open gamesave!\n";
		inStream.close();
		system("pause");
		startMenu();
	}
}

gameDriver::Builder::Builder(): numberOfPlayers(defaultNumberOfPlayers), whosTurn(defaultWhosTurn), phaseNum(defaultPhaseNum)
{
	if (computers == nullptr){
		computers = new AI[6 - numberOfPlayers]();
		for (int i = 0; i < 6 - numberOfPlayers; i++)
		{
			computers[i] = AI(i + 1);		//
		}
	}

	players = new Player[numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = Player(i + 1); //TODO: Required player parameters 
	}

}

gameDriver::Builder& gameDriver::Builder::setComputers(AI* computers){
	this->computers = computers;
	return *this;
}

gameDriver::Builder& gameDriver::Builder::setPlayers(Player* players){
	this->players = players;
	return *this;
}

gameDriver::Builder& gameDriver::Builder::setMap(string file){
	this->builderMap.loadMap(file);
	return *this;
}

gameDriver::Builder& gameDriver::Builder::setNumberOfPlayers(int numOfPlayers){
	this->numberOfPlayers = numOfPlayers;
	return *this;
}

gameDriver::Builder& gameDriver::Builder::setPhaseNum(int phaseNum){
	this->phaseNum = phaseNum;
	return *this;
}

gameDriver::Builder& gameDriver::Builder::setWhosTurn(int whosTurn){
	this->whosTurn = whosTurn;
	return *this;
}

gameDriver gameDriver::Builder::build(){
	return gameDriver(builderMap, players, computers, numberOfPlayers, whosTurn, phaseNum);
}