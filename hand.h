#ifndef HAND_H
#define HAND_H 

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "card.h"
#include "table.h"

class Hand {
  public:
	Hand(std::vector<std::shared_ptr<Card>> cards);
	// returns the legal plays based on current state of table
	std::vector<std::shared_ptr<Card>> legalPlays(Table table);
	// Removes card of face face and suit suit from cards, and returns that card
	std::shared_ptr<Card> getCard(int face, char suit);
	// returns the cards in hand
	std::vector<std::shared_ptr<Card>> getCards();	
	// print the cards in hand
	void printHand();

  private:
	std::vector<std::shared_ptr<Card>> cards;		
};

#endif
