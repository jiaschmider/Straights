#include "player.h"

Player::Player(Hand hand): hand{hand}, score{0} {}

// returns all legal plays
bool Player::legalPlay(char face, char suit, Table table){
	std::vector<std::shared_ptr<Card>> legal = legalPlays(table);
	int faceInt;
	if(face == 'A') faceInt = 1;
	else if(face == 'T') faceInt = 10;
	else if(face == 'J') faceInt = 11;
	else if(face == 'Q') faceInt = 12;
	else if(face == 'K') faceInt = 13;
	else faceInt = face-'0';
	bool n = false;
	for(unsigned int i =0; i < legal.size(); i++){
		if(legal[i]->getFace() == faceInt && legal[i]->getSuit() ==suit) n = true;
	}
	return n;
}


bool Player::legalDiscard(char face, char suit, Table table){
	std::vector<std::shared_ptr<Card>> legal = discardPile;
	int faceInt;
	if(face == 'A') faceInt = 1;
	else if(face == 'T') faceInt = 10;
	else if(face == 'J') faceInt = 11;
	else if(face == 'Q') faceInt = 12;
	else if(face == 'K') faceInt = 13;
	else faceInt = face-'0';
	bool n = false;
	for(unsigned int i =0; i < legal.size(); i++){
		if(legal[i]->getFace() == faceInt && legal[i]->getSuit() ==suit) n = true;
	}
	return n;
}


// returns if this face and suit is a legal play
// returns the legal plays based on current state of table
std::vector<std::shared_ptr<Card>> Player::legalPlays(Table table){
	std::vector<std::shared_ptr<Card>> playableCards;
	std::vector<std::shared_ptr<Card>> tableCards = table.getCardsOnTable();
	std::vector<std::shared_ptr<Card>> cards = hand.getCards();
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



//std::vector<std::shared_ptr<Card>> Player::legalPlays(Table table){
//	return hand.legalPlays(table);
//}

// print all legal plays
void Player::printLegalPlays(Table table) {
	std::cout << "Legal plays:";
	for(unsigned int i = 0; i < legalPlays(table).size(); i++){
		std::cout << " ";
		legalPlays(table)[i]->printCard();
	}
	std::cout << "\n";
}

// returns all discarded cards
std::vector<std::shared_ptr<Card>> Player::getDiscardPile() const{
	return discardPile;
}

// sets players hand to hand
void Player::newHand(Hand hand){
	for(unsigned int i = 0; i < discardPile.size(); i++ ){
		score = score + discardPile[i]->getFace();
	}
	discardPile.clear();
	this->hand = hand;

}

// returns score
int Player::getScore() const{
	return score;
}

// returns whether or no player is human
void Player::printHand(){
	hand.printHand();
}

// prints the players cards in hand
bool Player::isHuman(){
	return human;
}

//Hand Player::getHand() const{
//	return hand;
//}

