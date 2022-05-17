#ifndef DECK_H
#define DECK_H 

#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "card.h"
#include "hand.h"

class Deck {
  public:
	Deck();
	// Shuffles the deck using seed psudo random seed
	void shuffle(int seed);
	// returns the players set of 13 cards, ex if player = 0 you get the first 13 cards as a hand
	Hand deal(int player);
	// Prints deck
	void printDeck();

  private:
	std::vector<Card> deck;
};

#endif
