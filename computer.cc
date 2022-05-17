#include "computer.h"

Computer::Computer(Hand hand): Player(hand) {
	human = false;
}

// Copy constructor that takes in Player
Computer::Computer(const std::shared_ptr<Player>& ihuman) : Player(ihuman->getHand()) {
	human = false;
	score = ihuman->getScore();
	discardPile = ihuman->getDiscardPile();
}

// Discards first card in discard pile
void Computer::discard(char face, char suit){
	discardPile.push_back(hand.getCard(hand.getCards()[0]->getFace(), hand.getCards()[0]->getSuit()));
}

// Plays first playable card
std::shared_ptr<Card> Computer::play(char face, char suit, Table table){
	return hand.getCard(legalPlays(table)[0]->getFace(), legalPlays(table)[0]->getSuit());
}

