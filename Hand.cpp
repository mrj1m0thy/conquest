#include <iostream>
#include <string>

#include "Hand.h"

using namespace std;

void Hand::AddCard(Card* c)
{
	_hand.push_back(c);

	//Notify(this);
}

void Hand::RemoveCard(Card* c)
{
	for (size_t i = 0; i < _hand.size(); i++)
	{
		if (_hand[i] == c)
		{
			_hand.erase(_hand.begin() + i);
			break;
		}
	}

	//Notify(this);
}

void Hand::ViewHand()
{
	if (!IsEmpty())
	{
		for (size_t i = 0; i < _hand.size(); i++)
		{
			cout << "[Card " << i + 1 << "]: ";

			_hand[i]->Print();

			cout << endl;
		}
	}
	else
	{
		cout << "You have no cards" << endl;
	}
}

bool Hand::TradeIn(bool isComp)
{
	vector<Card**> trades;
	for (size_t i = 0; i < _hand.size() - 2; i++){
		for (size_t j = i + 1; j < _hand.size() - 1; j++){
			for (size_t k = j + 1; k < _hand.size(); k++){
				if (_hand[i] == _hand[j] && _hand[j] == _hand[k])
				{
					Card* tmp[3] = { _hand[i], _hand[j], _hand[k] };
					trades.push_back(tmp);
				}

				else if (_hand[i] != _hand[j] && _hand[i] != _hand[k] && _hand[j] != _hand[k])
				{
					Card* tmp[3] = { _hand[i], _hand[j], _hand[k] };
					trades.push_back(tmp);
				}

				else if (_hand[i]->GetFaceValue() == Wild || _hand[j]->GetFaceValue() == Wild || _hand[k]->GetFaceValue() == Wild)
				{
					Card* tmp[3] = { _hand[i], _hand[j], _hand[k] };
					trades.push_back(tmp);
				}
			}
		}
	}
	if (trades.size() > 0){
		if (isComp){
			for (int i = 0; i < 3; i++){
				for (size_t j = 0; j < _hand.size(); j++){
					if (trades[0][i] == _hand[j])
						_hand.erase(_hand.begin() + j);
				}
			}
			return true;
		}
		else{
			cout << "Choose one of the following sets of cards to discard: \n\n";
			for (size_t i = 0; i < trades.size(); i++)
			{
				cout << "[" << trades[i][0]->GetFaceValue() << ", " << trades[i][1]->GetFaceValue() << ", " << trades[i][2]->GetFaceValue() << "]: " << i + 1 << endl;
			}
			string response;
			do{
				cin.ignore();
				getline(cin, response);
			} while (!isNumber(response) || stoi(response) > int(trades.size()));

			for (int i = 0; i < 3; i++){
				for (size_t j = 0; j < _hand.size(); j++){
					if (trades[stoi(response)-1][i] == _hand[j])
						_hand.erase(_hand.begin() + j);
				}
			}
			return true;
		}
	}
	else{
		cout << "No valid trade options.\n";
		return false;
	}
}

bool Hand::isNumber(string s){
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}