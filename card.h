#ifndef CARD_H
#define CARD_H 

#include <memory>
#include <vector>
#include <iostream>

class Card {
  public:
	Card(int face, char suit);
	int getFace(); // returns face as integer
	char getSuit(); // returns suit as character
	void printCard(); // print card in the form "AS", "2S" and so on
		

  private:
	int face;
	char suit;
		
};

#endif
