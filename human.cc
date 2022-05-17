#include "human.h"

Human::Human(Hand hand): Player(hand) {
	human = true;
}

void Human::discard(char face, char suit){
	int faceInt;
	if(face == 'A') faceInt = 1;
	else if(face == 'T') faceInt = 10;
	else if(face == 'J') faceInt = 11;
	else if(face == 'Q') faceInt = 12;
	else if(face == 'K') faceInt = 13;
	else faceInt = face-'0';
//	std::cout << "human thinks this is "<< faceInt;
	discardPile.push_back(hand.getCard(faceInt,suit));
}

std::shared_ptr<Card> Human::play(char face, char suit, Table table){
		int faceInt;
	if(face == 'A') faceInt = 1;
	else if(face == 'T') faceInt = 10;
	else if(face == 'J') faceInt = 11;
	else if(face == 'Q') faceInt = 12;
	else if(face == 'K') faceInt = 13;
	else faceInt = face-'0';
	return hand.getCard(faceInt, suit);
}

