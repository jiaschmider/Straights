#ifndef PLAYER_H
#define PLAYER_H 

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "card.h"
#include "hand.h"

class Player {
  public:
	Player(Hand hand);
	virtual ~Player(){};
	// returns all legal plays
	std::vector<std::shared_ptr<Card>> legalPlays(Table table);
	// returns if this face and suit is a legal play
	bool legalPlay(char face, char suit, Table table);
	// print all legal plays
	void printLegalPlays(Table table);
	// returns all discarded cards
	std::vector<std::shared_ptr<Card>> getDiscardPile() const;
	// sets players hand to hand
	void newHand(Hand hand);
	// returns score
	int getScore() const;
	// returns hand
	//Hand getHand() const;
	// returns whether or no player is human
	bool isHuman();
	// prints the players cards in hand
	void printHand();

	virtual void discard(char face, char suit) = 0;
	virtual std::shared_ptr<Card> play(char face, char suit, Table table) = 0;
  
  protected:
	Hand hand;
	int score;
	bool human; 
	std::vector<std::shared_ptr<Card>> discardPile;
};

#endif
