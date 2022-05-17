#include "deck.h"

Deck::Deck() {
	deck = std::vector<Card>{};

	for(int i=0; i < 4; i++){
		for(int j=1; j < 14; j++){
			char suit;
			char face = j;
			if (i == 0) suit = 'C';
			else if (i == 1) suit = 'D';
			else if (i == 2) suit = 'H';
			else suit = 'S';
			Card newCard = Card(face, suit);
			deck.push_back(newCard);
		}
	}
}

// Shuffles the deck using seed psudo random seed
void Deck::shuffle(int seed){
	std::default_random_engine rng{seed};
	std::shuffle( deck.begin(), deck.end(), rng );
}

// returns the players set of 13 cards, ex if player = 0 you get the first 13 cards as a hand
Hand Deck::deal(int player){
	std::vector<std::shared_ptr<Card>> cards;
	for(int i = 0; i < 13; i++){
		cards.push_back(std::make_shared<Card>(deck[player*13 + i]));
	}
	Hand newHand = Hand(cards);
	return newHand;
}

// Prints deck
void Deck::printDeck(){ 
	for(int i=0; i < 4; i++){
		for(int j=0; j < 13; j++){
			deck[i*13+j].printCard();
			if(j< 12) std::cout << " ";
		}
		std::cout << "\n";
	}
}

