#ifndef CARD_H
#define CARD_H

enum FaceValue { Infantry, Cavalry, Artillery, Wild };

class Card
{
private: 
	FaceValue _faceValue;
public:
	Card();	// Default Constructor.
	Card(FaceValue);	// Regular Constructor.
	
	bool operator == (Card);	//The following operator is based on FaceValue.
  
	void SetFaceValue(FaceValue fv) { _faceValue = fv; }
	FaceValue GetFaceValue() { return _faceValue; }
  
	void Print();	//Prints the Card.
};

#endif
