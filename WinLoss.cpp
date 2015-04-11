#include <iostream>
#include "WinLoss.h"
#include "Player.h"

using namespace std;

void WinLoss::Update(Player* p)
{
	/*
	cout << "Player: " << p->GetColour() << endl;
	cout << "Countries Controlled: " << p->GetCountriesOwned() << endl;
	cout << "Armies Owned: " << p->GetArmiesOwned() << endl;
	cout << "Cards in Hand: " << p->GetHandSize() << endl << endl << endl;
	*/

	double total = p->GetBattlesWon() + p->GetBattlesLost();
	double win = p->GetBattlesWon();
	double loss = p->GetBattlesLost();

	cout << "Win Percentage: " << (win/total)*100 << "%" << endl;
	cout << "Loss Percentage: " << (loss/total)*100 << "%" << endl << endl << endl;
}