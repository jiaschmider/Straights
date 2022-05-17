#ifndef TABLE_H
#define TABLE_H 

#include <iostream>
#include <memory>
#include <vector>

#include "card.h"

class Table {
  public:
	Table();
	// prints table contents
	void printTable();
	// clears clubs, diamonds, hearts, and spades
	void clearTable();
	// adds Card to table
	void addCard(std::shared_ptr<Card> Card);
	// returns a vector with pointers to all the cards on the table
	std::vector<std::shared_ptr<Card>> getCardsOnTable();

  private:  	
	std::vector<std::shared_ptr<Card>> clubs;
	std::vector<std::shared_ptr<Card>> diamonds;
	std::vector<std::shared_ptr<Card>> hearts;
	std::vector<std::shared_ptr<Card>> spades;		
	void sortCards(std::vector<std::shared_ptr<Card>> &cards);
};

#endif
