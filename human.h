#ifndef HUMAN_H
#define HUMAN_H 

#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include "player.h"

class Human : public Player {
  public:
	Human(Hand hand);
	// dicards card of face face and suit suit
	void discard(char face, char suit) override;
	// plays card of face face and suit suit
	std::shared_ptr<Card> play(char face, char suit, Table table) override;
};

#endif
