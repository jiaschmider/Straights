#ifndef COMPUTER_H
#define COMPUTER_H 

#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include "player.h"

class Computer : public Player {
  public:
	Computer(Hand hand);
	// Copy constructor that takes in Player
	explicit Computer(const std::shared_ptr<Player>& human);
	
	// Discards first card in discard pile
	void discard(char face, char suit) override;
	// Plays first playable card
	std::shared_ptr<Card> play(char face, char suit, Table table) override;
};

#endif
