#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class Output
{
private:

public:
	Output() {};

	template <typename T>
	void OutputData(T t)
	{
		cout << t;
	}

	template <typename T>
	T OutputData(string out1, T varout, string out2 = "")
	{
		cout << out1;
		cout << varout;
		cout << out2;
		cout << endl;
	}

	template <typename T>
	inline T OutIn(string out1, T in)
	{
		cout << out1;
		cin >> in;

		return in;
	};

	void PlayerStats(Player);
	
	void fortificationPlayerStats(Player);
	
	void attackPlayerStats(Player);

	void NewLine();

	void StartMenu();
};

#endif