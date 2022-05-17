#include "card.h"

Card::Card(int face, char suit): face{face}, suit{suit} {}

// returns face as integer
int Card::getFace(){
	return face;
}

// returns suit as character
char Card::getSuit(){
	return suit;
}	

// print card in the form "AS", "2S" and so on
void Card::printCard(){
		char faceChar;

		if (face == 1) faceChar = 'A';
		else if (face == 10) faceChar = 'T';
		else if (face == 11) faceChar = 'J';
		else if (face == 12) faceChar = 'Q';
		else if (face == 13) faceChar = 'K';
		else faceChar = '0' + face;

		std::cout << faceChar << suit;
}
