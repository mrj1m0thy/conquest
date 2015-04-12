#include "Output.h"

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