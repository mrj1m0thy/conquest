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
	T OutIn(string, T);

	void PlayerStats(Player);

	void NewLine();

	void StartMenu();
	
};

#endif



//You can put menus in here 