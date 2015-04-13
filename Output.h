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
	void OutputData(T);
	
	template <typename T>
	T OutputData(string, T, string);

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



//You can put menus in here 