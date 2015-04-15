#include <iostream>
#include "WinLoss.h"
#include "Player.h"

using namespace std;

void WinLoss::Update(Player* p)
{
	double total = p->GetBattlesWon() + p->GetBattlesLost();
	double win = p->GetBattlesWon();
	double loss = p->GetBattlesLost();

	cout << "Win Percentage: " << (win/total)*100 << "%" << endl;
	cout << "Loss Percentage: " << (loss/total)*100 << "%" << endl << endl << endl;
}