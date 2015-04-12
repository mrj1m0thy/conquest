#include <iostream>

#include "Card.h"

using namespace std;

Card :: Card()
{
	_faceValue = Infantry;
}

Card :: Card(FaceValue fv)
{
	_faceValue = fv;
}

bool Card :: operator == (Card other)
{
	return _faceValue == other._faceValue;
}

void Card :: Print()
{
	switch (_faceValue)
	{
	case Infantry: cout << "Infantry";
		break;
	case Cavalry: cout << "Cavalry";
		break;
	case Artillery: cout << "Artillery";
		break;
	case Wild: cout << "Wild";
		break;
	}
}