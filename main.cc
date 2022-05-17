#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "deck.h"
#include "player.h"
#include "human.h"
#include "computer.h"

int main(int argc, char *argv[]) {	
	
	if(argc < 2){
		std::cout << "Please provide at least one integer as an argument" << std::endl;
		return 0;
	}

	Deck deck;
	Table table;
	std::vector<std::shared_ptr<Player>> players;

	bool newRound = true;
	int whoseTurn=0;
	int plays = 0;

	std::string cmd;

	for(int i = 0; i < 4; i++) {
		std::cout << "Is Player"<< i+1 << " a human (h) or a computer (c)?"<< std::endl;
		std::cin >> cmd;
		while(cmd.at(0) != 'c' && cmd.at(0) != 'h') {
			std::cout << "Please only input (h) or (c).\n";
			std::cin>>cmd;
		}
		if(cmd.at(0) == 'h') players.push_back(std::make_shared<Human>(deck.deal(i)));
		else  players.push_back(std::make_shared<Computer>(deck.deal(i)));
	}

	try {
		while (true) {
			
			if(newRound) {

				plays = 0;
				table.clearTable();

				deck.shuffle(std::atoi(argv[1]));
				for(int i = 0; i < 4; i++){
					players[i]->newHand(deck.deal(i));
					if(players[i]->legalPlays(table).size() > 0) whoseTurn = i;
				}

				int winnerScore = players[0]->getScore();
				int winner = 0;
				bool gameDone = false;
				
				
				for (int i = 0; i < 4; i++){
					if(players[i]->getScore() < winnerScore){
						winnerScore = players[i]->getScore();
						winner = i;
					}
					if(players[i]->getScore()>= 80)gameDone = true;
				}
				
				if(gameDone) {
					std::cout <<"Player"<< winner+1 << " wins!\n";
					return 1;
				} 
				else{
					std::cout << "A new round begins. It’s Player"<< whoseTurn+1 <<"’s turn to play."<< std::endl;
					newRound = false;
					table.printTable();
					players[whoseTurn]->printHand();
					players[whoseTurn]->printLegalPlays(table);
				}
			}
			else if(plays > 51){

				for(int i = 0; i < 4; i++) {
					int roundScore = 0;
					std::cout << "Player"<< i+1 << "’s discards:";
					for(unsigned int j = 0; j < players[i]->getDiscardPile().size(); j++){
						roundScore = roundScore + players[i]->getDiscardPile()[j]->getFace();
						std::cout << " ";
						players[i]->getDiscardPile()[j]->printCard();
					}
					std::cout << "\nPlayer"<< i + 1 << "’s score: " << players[i]->getScore();
					std:: cout << " + " << roundScore << " = " << roundScore + players[i]->getScore()<< "\n";
				}			
				newRound = true;

			}
			else {
				bool played = false;
				if(players[whoseTurn]->isHuman()){
					std::cin >> cmd;
					if(cmd == "quit") return 1;
					if(cmd == "ragequit") {
						players[whoseTurn] = std::make_shared<Computer>(players[whoseTurn]);
					}
					if (cmd == "deck") {
						deck.printDeck();
					}
					else if (cmd == "discard") {
						std::cin >> cmd;
						if(players[whoseTurn]->legalPlays(table).size() > 0) {
							std::cerr << "You have a legal play.\n";
						}
						else {
							players[whoseTurn]->discard(cmd.at(0), cmd.at(1));
							std::cout << "Player"<< whoseTurn+1 <<" discards " << cmd <<"."<< std::endl;
							played = true;
						}
					}
					else if (cmd == "play") {
						std::cin >> cmd;
						if(!players[whoseTurn]->legalPlay(cmd.at(0), cmd.at(1), table)){
							std::cerr << "This is not a legal play.\n";
						}
						else{
							std::shared_ptr<Card> playedCard = players[whoseTurn]->play(cmd.at(0), cmd.at(1), table);
							table.addCard(playedCard);
							std::cout << "Player"<< whoseTurn+1 <<" plays ";
							playedCard->printCard();
							std::cout <<"."<< std::endl;
							played = true;
						}
						
					}
					else {
						std::cerr << "Unrecognized command" << cmd <<"!\n";
					}
				}				
				else {
					if(players[whoseTurn]->legalPlays(table).size() > 0){
						std::shared_ptr<Card> playedCard = players[whoseTurn]->play('A', '1', table);
						table.addCard(playedCard);
						std::cout << "Player"<< whoseTurn+1 <<" plays ";
						playedCard->printCard();
						std::cout <<"."<< std::endl;
						played = true;
					}
					else{
						players[whoseTurn]->discard('A', '1');
						std::cout << "Player"<< whoseTurn+1 <<" discards ";
						players[whoseTurn]->getDiscardPile().back()->printCard();
						std::cout <<"."<< std::endl;
						played = true;
					}				
				}
				if(played){
					plays++;
					if(plays < 52){					
						whoseTurn++;
						if(whoseTurn == 4) whoseTurn = 0;
						table.printTable();
						players[whoseTurn]->printHand();
						players[whoseTurn]->printLegalPlays(table);
					}					
				}
			}
		}

	}
	catch(std::ios::failure &){
	}
	players.clear();
}

