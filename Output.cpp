#include "Output.h"
#include "Country.h"
#include "player.h"
#include <iomanip>

using namespace std;

template <typename T>
void Output::OutputData(T t)
{
	cout << t;
}

template <typename T>
T Output::OutputData(string out1, T varout, string out2 = "")
{
	cout << out1;
	cout << t;
	cout << out2;
	cout << endl;
}

template <typename T>
T Output::OutIn(string out1, T in)
{
	cout << out1;
	cin >> in;

	return t;
}

void Output::PlayerStats(Player p)
{
	cout << "Player: " << p.getID() << endl << endl;
	for (int i = 0; i < p.GetCountries().size(); i++)
	{
		if (i == 0)
		{
			cout << setw(15) << "| Country (Number of Armies)|	Surrounding Countries -> Player (Number of Armies)|" << endl;
			cout << left << "\n-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
		}
		cout << "| " << right << setw(20) << p.GetCountries().at(i)->getName() << " (" << p.GetCountries().at(i)->getNumberOfPieces() << ") | ";
		
		Country** a = p.GetCountries().at(i)->getAdjacent();

		for (int index = 0; index < p.GetCountries().at(i)->getAdjacentCount(); index++)
		{
			cout << setw(10) << (*a)->getName() << " - > " << (*a)->getOccupiedBy()->name << " (" << (*a)->getNumberOfPieces() << ") | ";
		}
		
		cout << left << "\n-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}	
}

void Output::NewLine()
{
	cout << endl;
}

void Output::StartMenu()
{
	cout << "================================================================================" << endl;
	cout << "                      RRRRRRR    II   SSSSSS   KK    KK  TM" << endl;
	cout << "                      RR    RR   II  SS        KK  KK" << endl;
	cout << "                      RRRRRRR    II   SSSSSS   KKKKK" << endl;
	cout << "                      RR    RR   II        SS  KK  KK" << endl;
	cout << "                      RR     RR  II   SSSSSS   KK    KK" << endl;
	cout << "================================================================================" << endl;
	cout << endl;
	cout << "Welcome to Risk!" << endl << endl;
}