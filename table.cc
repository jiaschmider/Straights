#include "table.h"

Table::Table(){}

// prints table contents
void Table::printTable() {
	char faceChar;
	int face;

	std::cout << "Clubs:";
	for(unsigned int i = 0; i < clubs.size() ; i++){
		face = clubs[i]->getFace();
		if (face == 1) faceChar = 'A';
		else if (face == 10) faceChar = 'T';
		else if (face == 11) faceChar = 'J';
		else if (face == 12) faceChar = 'Q';
		else if (face == 13) faceChar = 'K';
		else faceChar = '0' + face;
		std::cout << " " << faceChar;
		
	}
	std::cout << "\n";
	std::cout << "Diamonds:";
	for(unsigned int i = 0; i < diamonds.size() ; i++){
		face = diamonds[i]->getFace();
		if (face == 1) faceChar = 'A';
		else if (face == 10) faceChar = 'T';
		else if (face == 11) faceChar = 'J';
		else if (face == 12) faceChar = 'Q';
		else if (face == 13) faceChar = 'K';
		else faceChar = '0' + face;
		std::cout << " " << faceChar;
	}
	std::cout << "\n";
	std::cout << "Hearts:";
	for(unsigned int i = 0; i < hearts.size() ; i++){
		face = hearts[i]->getFace();
		if (face == 1) faceChar = 'A';
		else if (face == 10) faceChar = 'T';
		else if (face == 11) faceChar = 'J';
		else if (face == 12) faceChar = 'Q';
		else if (face == 13) faceChar = 'K';
		else faceChar = '0' + face;
		std::cout << " " << faceChar;
	}
	std::cout << "\n";
	std::cout << "Spades:";
	for(unsigned int i = 0; i < spades.size() ; i++){
		face = spades[i]->getFace();
		if (face == 1) faceChar = 'A';
		else if (face == 10) faceChar = 'T';
		else if (face == 11) faceChar = 'J';
		else if (face == 12) faceChar = 'Q';
		else if (face == 13) faceChar = 'K';
		else faceChar = '0' + face;
		std::cout << " " << faceChar;
	}
	std::cout << "\n";
}

// clears clubs, diamonds, hearts, and spades
void Table::clearTable(){
	clubs.clear();
	diamonds.clear();
	hearts.clear();
	spades.clear();
}

// adds Card to table
void Table::addCard(std::shared_ptr<Card> card){
	char suit = card->getSuit();
	if( suit == 'C') {
		clubs.push_back(card);
		sortCards(clubs);
	}
	if( suit == 'D') {
		diamonds.push_back(card);
		sortCards(diamonds);
	}
	if( suit == 'H') {
		hearts.push_back(card);
		sortCards(hearts);
	}
	if( suit == 'S') {
		spades.push_back(card);
		sortCards(spades);
	}
}

void Table::sortCards(std::vector<std::shared_ptr<Card>> &cards){
	for( unsigned int i = 0; i < cards.size() - 1; i++){
		for(unsigned int j = i + 1 ; j < cards.size(); j++){
			if(cards[i]->getFace() > cards[j]->getFace()) cards[i].swap(cards[j]);
		}
	}
}


// returns a vector with pointers to all the cards on the table
std::vector<std::shared_ptr<Card>> Table::getCardsOnTable(){
	std::vector<std::shared_ptr<Card>> cardsOnTable;
	cardsOnTable.reserve(clubs.size()+diamonds.size()+hearts.size()+spades.size());
	cardsOnTable.insert(cardsOnTable.end(), clubs.begin(), clubs.end());
	cardsOnTable.insert(cardsOnTable.end(), diamonds.begin(), diamonds.end());
	cardsOnTable.insert(cardsOnTable.end(), hearts.begin(), hearts.end());
	cardsOnTable.insert(cardsOnTable.end(), spades.begin(), spades.end());
	return cardsOnTable;
}

