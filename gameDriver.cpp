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
#include <string>
#include <fstream>

using namespace std;

gameDriver::gameDriver()
{
	myMap.loadMap("myMap.map"); //load contents from sample file downloaded from given website
	whosTurn = 0;
	phaseNum = 0;
}

gameDriver::gameDriver(map myMap, Player** players, AI** computers, int numberOfPlayers, int whosTurn, int phaseNum)
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
	//getline(cin, response);

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
		//getline(cin, numberOfPlayers);
	} while (numberOfPlayers > 6 || numberOfPlayers < 2);

	vector<int> countryRefs;

	for (int i = 0; i < sizeof(myMap.countries) / sizeof(myMap.countries[0]); i++){
		countryRefs.push_back(i);
	}

	computers = new AI*[6 - numberOfPlayers];

	for (int i = 0; i < 6 - numberOfPlayers; i++)
	{
		int infantry = 13;
		computers[i] = new AI(i + 1);
		for (int j = 0; j < 7; j++){
			int rng = rand() % countryRefs.size();
			myMap.countries[countryRefs[rng]].occupiedBy = computers[i];
			if (j != 6){
				myMap.countries[countryRefs[rng]].numberOfPieces += rand() % infantry;
				infantry -= myMap.countries[countryRefs[rng]].numberOfPieces;
			}
			else
				myMap.countries[countryRefs[rng]].numberOfPieces += infantry;
			computers[i]->AddCountry(&myMap.countries[countryRefs[rng]]);
			countryRefs.erase(countryRefs.begin() + rng);
		}
	}

	for (int i = 0; i < 6 - numberOfPlayers; i++)
	{
		for (int j = 0; j < computers[i]->GetCountries().size(); j++)
		{
			computers[i]->GetCountries()[j]->numberOfPieces++;
		}
	}
	players = new Player*[numberOfPlayers];

	for (int i = 0; i < numberOfPlayers; i++)
	{
		int infantry = 13;
		players[i] = new Player((i + 1), "player " + to_string(i + 1));
		for (int j = 0; j < 7; j++){
			int rng = rand() % countryRefs.size();
			myMap.countries[countryRefs[rng]].occupiedBy = players[i];

			if (j != 6){
				myMap.countries[countryRefs[rng]].numberOfPieces += rand() % infantry;
				infantry -= myMap.countries[countryRefs[rng]].numberOfPieces;
			}
			else
				myMap.countries[countryRefs[rng]].numberOfPieces += infantry;

			players[i]->AddCountry(&myMap.countries[countryRefs[rng]]);
			countryRefs.erase(countryRefs.begin() + rng);
		}
	}
	for (int i = 0; i < numberOfPlayers; i++)
	{
		for (int j = 0; j < players[i]->GetCountries().size(); j++)
		{
			players[i]->GetCountries()[j]->numberOfPieces++;
		}
	}

	phaseNum++;

	//Create the deck.
	_deck = new Deck(); 
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

	while (true){
		if (whosTurn < numberOfPlayers){
			for (int id = whosTurn; id < numberOfPlayers; id++, whosTurn++){
				cout << "\nPlayer " << players[id]->getID() << " turn\n";
				cout << "------------------------------------------\n";

				switch (phaseNum){
				case 1:
					reinforcementPhase(players[id]);
					phaseNum++;
				case 2:
					attackPhase(players[id]);
					if (myMap.isWinner())
						gameOver();
					phaseNum++;
				case 3:
					fortification(players[id]);
					phaseNum = 1;
				}
			}
		}
		for (int id = (whosTurn-numberOfPlayers); id < 6 - numberOfPlayers; id++, whosTurn++){
			cout << "\nComputer " << computers[id]->getID() << " turn\n";
			cout << "------------------------------------------\n";

			switch (phaseNum){
			case 1:
				reinforcementPhase(computers[id]);
				phaseNum++;
			case 2:
				attackPhase(computers[id]);
				if (myMap.isWinner())
					gameOver();
				phaseNum++;
			case 3:
				fortification(computers[id]);
				phaseNum = 1;
			}
		}

		whosTurn = 0;
		clearScreen();
	}
}

void gameDriver::gameOver(){
	cout << "Congratulations " << myMap.countries[0].occupiedBy->name << " you are the winner!\n\n";

	cout << "Game is over!\n\n";

	system("pause");
	exit(0);
}

//a) reinforcement phase (where a player is given some armies and places them on some if the countries he owns)
void gameDriver::reinforcementPhase(Player* user){
	int total = 0;
	clearScreen();
	updatePlayerContinents();

	if (int(user->GetCountries().size() / 3) > 3)
		user->SetRenforcements(user->GetCountries().size() / 3);
	else
		user->SetRenforcements(3);

	for (size_t i = 0; i < user->GetContinents().size(); i++)
		total += user->GetContinents().at(i)->getArmyNum();

	if (user->GetHand().Size() > 3){
		string input;
		do{
			cout << "Do you want to trade in some cards for units? (" << cardReturns << " available) Y/N: ";
			cin.ignore();
			getline(cin, input);
			cout << endl;
			for (size_t i = 0; i < input.length(); i++)
				input[i] = toupper(input[i]);
		} while (input != "Y" || input != "N");
		clearScreen();
		if (input == "Y")
		if (user->GetHand().TradeIn(user->isComputer))
			total += getCardUnits();
	}
	user->SetRenforcements(user->GetRenforcements() + total);

	
	cout << "This is the reinforcement phase for player " << user->getID() << endl;
	cout << "---------------------------------------------------------\n\n";
	
	int remaining = user->GetRenforcements();
	int countryNum;
	int armyNum;
	while (remaining > 0){
		clearScreen();
		cout << "Remaining armies: " << remaining << endl;

		output.PlayerStats(*user);
		do{
			cout << "\n\nWhere would you like to place your armies? (Must be between 1 and " << user->GetCountries().size() << ") ";
			//(cin, countryNum);
			cin >> countryNum;
		} while (countryNum > int(user->GetCountries().size()));

		do{
			cout << "\n\nHow many armies would you like to place here? (Must be less than " << remaining << ") ";
			//getline(cin, armyNum);
			cin >> armyNum;
		} while (armyNum > remaining);

		user->GetCountries()[countryNum-1]->numberOfPieces += armyNum;
		remaining -= armyNum;
	}

	mainMenu();
}

void gameDriver::reinforcementPhase(AI* comp){
	int total = 0;
	clearScreen();
	updatePlayerContinents();

	if (int(comp->GetCountries().size() / 3) > 3)
		comp->SetRenforcements(comp->GetCountries().size() / 3);
	else
		comp->SetRenforcements(3);

	for (size_t i = 0; i < comp->GetContinents().size(); i++)
		total += comp->GetContinents().at(i)->getArmyNum();

	if (comp->GetHand().Size() > 2){
		if (comp->GetHand().TradeIn(comp->isComputer))
			total += getCardUnits();
	}

	if (comp->GetHand().TradeIn(comp->isComputer))
		total += getCardUnits();

	comp->SetRenforcements(comp->GetRenforcements() + total);



	cout << "This is the reinforcement phase for computer " << comp->getID() << endl;
	cout << "---------------------------------------------------------\n\n";

	int remaining = comp->GetRenforcements();
	
		clearScreen();

	comp->GetCountries()[comp->strat->reinforce(comp)]->numberOfPieces += (int)floor(remaining*0.75);
	remaining -= (int)floor(remaining*0.75);

	while (remaining > 0)
	{
		comp->GetCountries()[rand() % comp->GetCountries().size()]->numberOfPieces++;
		remaining--;
	}

	mainMenu();
}

//b) attack phase(where a player may declare a series of attacks	from one of his countries to one of its adjacent countries owned by another player)
void gameDriver::attackPhase(Player* user){
	string response = "Y";
	while (response == "Y"){
		clearScreen();

		cout << "This is the attack phase for player " << user->getID() << endl;
		cout << "---------------------------------------------------------\n\n";
		cin.ignore();
		output.PlayerStats(*user);

		do{
			cout << "Do you want to attack? (Y or N) ";

			getline(cin, response);
			for (size_t i = 0; i < response.length(); i++)
				response[i] = toupper(response[i]);
		} while (response != "Y" && response != "N");

		if (response == "Y")
		{
			string from;
			string to;

			output.attackPlayerStats(*user);

			do{
				cout << "Where would you like to attack from? (1 - " << user->GetCountries().size() << ") ";
				getline(cin, from);
			} while (!isNumber(from) || (stoi(from) > user->GetCountries().size()));

			Country* att;
			do{
				cout << "Which country would you like to attack? (Type the name of the country) ";
				getline(cin, to);
				to = toupperCase(to);
				att = user->GetCountries()[stoi(from) - 1]->findAdjacent(to);
			} while (att == nullptr);

			Battle battle1(user->GetCountries().at(stoi(from) - 1), att);
		}
	}
	mainMenu();
}

void gameDriver::attackPhase(AI* comp){
	clearScreen();

	cout << "This is the attack phase for computer " << comp->getID() << " using the " << comp->stratType << " strategy." << endl;
	cout << "--------------------------------------------------------------------------\n\n";

	comp->strat->execute(comp);

	mainMenu();
}

//c) fortification phase (where a player may move some armies from one of his countries to another of his countries)
void gameDriver::fortification(Player* user){
	clearScreen();
	cout << "This is the fortification phase for player " << user->getID() << endl;
	cout << "---------------------------------------------------------\n\n";

	string answer;
	bool quit = false;
	output.fortificationPlayerStats(*user);

	answer = output.OutIn("Would you like to move any armies?", answer);

	while (!quit)
	{
		if (toupper(answer[0]) == 'Y')
		{
			int country1 = 0;
			int country2 = 0;
			int armies = 0;

			country1 = output.OutIn("Which country would you like to take armies from?", country1);
			country2 = output.OutIn("Which country would you like to move the armies?", country2);

			Country* start = (*user).GetCountries().at(country1-1);
			Country* end = (*user).GetCountries().at(country2-1);

			if (start->occupiedBy->name == end->occupiedBy->name)
			{
				do
				{
					armies = output.OutIn("How many armies?", armies);
				} while (!((armies > 0 || (armies < (*user).GetCountries().at(country1-1)->getNumberOfPieces())) && (((*user).GetCountries().at(country1-1)->getNumberOfPieces()) - armies) != 0));
		
				int sizeStart = start->getAdjacentCount();
				int sizeEnd = end->getAdjacentCount();

				for (int i = 0; i < sizeStart; i++)
				{
					if (start->getAdjacentCountry(i)->name == end->getAdjacentCountry(i)->name || start->getAdjacentCountry(i)->name == end->name)
					{
						start->getAdjacentCountry(i)->setNumberOfPieces(start->getAdjacentCountry(i)->getNumberOfPieces() - armies);
						end->getAdjacentCountry(i)->setNumberOfPieces(end->getAdjacentCountry(i)->getNumberOfPieces() + armies);
						quit = true;
						break;
					}
				}
			}
		}
		else
			quit = true;
	}


	output.fortificationPlayerStats(*user);

	mainMenu();
}

void gameDriver::fortification(AI* comp){
	clearScreen();
	cout << "This is the fortification phase for computer " << comp->getID() << endl;
	cout << "---------------------------------------------------------\n\n";

	output.PlayerStats(*comp);
	
	(*comp).strat->fortification(comp);

	output.PlayerStats(*comp);

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
	//getline(cin, response);

	if (response == 0)
		exit(0);
	else if (response == 1){
		string save;

		clearScreen();
		cout << "What would you like to save it as?\n";
		cin.ignore();
		getline(cin, save);
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
		outStream << computers[i]->stratType << ",";

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
		AI** comps;

		getline(inStream, line);
		thisMap = line.substr(line.find('=') + 1);

		getline(inStream, line);
		numberOfPlayers = stoi(line.substr(line.find('=') + 1));

		comps = new AI*[6 - numberOfPlayers];

		getline(inStream, line);
		whosTurn = stoi(line.substr(line.find('=') + 1));

		getline(inStream, line);
		phaseNum = stoi(line.substr(line.find('=') + 1));

		getline(inStream, line);
		line = line.substr(line.find('=') + 1);
		for (int i = 0; i < 6-numberOfPlayers; i++){
			comps[i] = new AI(i+1, line.substr(0, line.find(',')));
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

void gameDriver::updatePlayerContinents()
{
	for (int i = 0; i < numberOfPlayers; i++){
		for (int j = 0; j < myMap.getNumOfContinents(); j++){
			int k;
			for (k = 0; k < myMap.continents[j].getNumCountries(); k++){
				if (!players[i]->hasCountry(myMap.continents[j].countryArray[k]->getName()))
					break;
			}
			if (k == myMap.continents[j].getNumCountries() - 1){
				players[i]->AddContinent(&myMap.continents[j]);
			}
		}
	}
}

gameDriver::Builder::Builder(): numberOfPlayers(defaultNumberOfPlayers), whosTurn(defaultWhosTurn), phaseNum(defaultPhaseNum)
{
	if (computers == nullptr){
		for (int i = 0; i < 6 - numberOfPlayers; i++)
		{
			computers[i] = new AI(i + 1);		//
		}
	}

	for (int i = 0; i < numberOfPlayers; i++)
	{
		players[i] = new Player(i + 1, "player "+(i+1)); //TODO: Required player parameters 
	}

}

gameDriver::Builder& gameDriver::Builder::setComputers(AI** computers){
	this->computers = computers;
	return *this;
}

gameDriver::Builder& gameDriver::Builder::setPlayers(Player** players){
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

int gameDriver::getCardUnits(){
	int tmp = cardReturns;

	if (cardSetNum < 5){
		cardReturns += 2;
		cardSetNum++;
	}
	else if (cardSetNum == 5){
		cardReturns += 3;
		cardSetNum++;
	}
	else{
		cardReturns += 5;
		cardSetNum++;
	}

	return tmp;
}

bool gameDriver::isNumber(string s){
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

string gameDriver::toupperCase(string input)
{
	for (size_t i = 0; i < input.length(); i++)
		input[i] = toupper(input[i]);

	return input;
}