#include "hand.h"

Hand::Hand(std::vector<std::shared_ptr<Card>> cards): cards{cards} {}

// returns the legal plays based on current state of table
std::vector<std::shared_ptr<Card>> Hand::legalPlays(Table table){
	std::vector<std::shared_ptr<Card>> playableCards;
	std::vector<std::shared_ptr<Card>> tableCards = table.getCardsOnTable();
	if(tableCards.empty()){
		for(unsigned int i = 0; i < cards.size(); i++){
			if(cards[i]->getFace() == 7 && cards[i]->getSuit() == 'S') playableCards.push_back(cards[i]);
		}
	}
	else {
		for(unsigned int i = 0; i < cards.size(); i++){
			
			if(cards[i]->getFace() == 7) playableCards.push_back(cards[i]);
			else {
				for(unsigned int j = 0; j < tableCards.size(); j++){
					if(tableCards[j]->getSuit() == cards[i]->getSuit()){
						if((tableCards[j]->getFace() == cards[i]->getFace() + 1) || (tableCards[j]->getFace() == cards[i]->getFace()-1)){
							playableCards.push_back(cards[i]);
						}
					}
				}
			}
		}
	}
	return playableCards;
}

// Removes card of face face and suit suit from cards, and returns that card
std::shared_ptr<Card> Hand::getCard(int face, char suit){
	std::shared_ptr<Card> card;
	for(unsigned int i = 0; i < cards.size(); i++){
		if(cards[i]->getFace() == face && cards[i]->getSuit() == suit){
			card = cards[i];
			cards.erase(cards.begin()+i);
		}

	}
	return card;
}

// returns the cards in hand
std::vector<std::shared_ptr<Card>> Hand::getCards(){
	return cards;
}

// print the cards in hand
void Hand::printHand(){
	std::cout << "Your hand:";
	for(unsigned int i = 0; i < cards.size(); i++){
		std::cout << " ";
		cards[i]->printCard();
	}
	std::cout << "\n";
}
