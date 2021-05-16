#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>

#include "chessboard.hpp"
#include "player.hpp"

bool file_exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

void playGame(Player* player1, Player* player2) {
	std::cout << "MENU:\n\n";
	std::cout << "1. Start a new game\n2. Load a saved game\n\n";
	std::string option;
	std::cout << "Choose an option: ";
	std::getline(std::cin, option);
	if (option == "1") {
		Chessboard* chessboard = new Chessboard();
		
		while(player1->inGame() && player2->inGame()) {
			if (player1->playerTurn()) {
				player1->executeTurn(chessboard);
				player1->setTurn(false);
				player2->setTurn(true);
			} else if (player2->playerTurn()) {
				player2->executeTurn(chessboard);
				player1->setTurn(true);
                        	player2->setTurn(false);
			}
		}	
	} 
	else if (option == "2") {
		std::cout << "The following games are saved:\n\n";
		if (file_exists("1.sav")) {
			std::cout << "Game: \"1.sav\"\n";
		} else if (file_exists("2.sav")) {
			std::cout << "Game: \"2.sav\"\n"; 
		} else if (file_exists("3.sav")) { 
			std::cout << "Game: \"3.sav\"\n";
		} else {
			std::cout << "No games are saved\n";
		}
		std::cout << "\nPlease enter the name of the file to load: ";
		std::string filename;
		std::cin >> filename;
		
		int slot = 0;
		if (filename == "1.sav") {
			slot = 1;
		} else if (filename == "2.sav") {
			slot = 2;
		} else if (filename == "3.sav") {
			slot = 3;
		} else {
			return;
		}

		Chessboard* chessboard = new Chessboard();
                
		int slotSuccess = chessboard->load(slot);
		if (slotSuccess == -1) {
			return;
		} else if (slotSuccess = 0) {
			player1->setTurn(true);
			player2->setTurn(false);
		} else {
			player1->setTurn(false);
			player2->setTurn(true);
		}			

		while(player1->inGame() && player2->inGame()) {
                        if (player1->playerTurn()) {
                                player1->executeTurn(chessboard);
                                player1->setTurn(false);
                                player2->setTurn(true);
                        } else if (player2->playerTurn()) {
                                player2->executeTurn(chessboard);
                                player1->setTurn(true);
                                player2->setTurn(false);
                        }
                }	
				
	}
}

int main() {
	Player* white = new White();
	Player* black = new Black();
	std::cout << "**************************\n";
	std::cout << "Welcome to 2 PLAYER CHESS\n";	
	std::cout << "**************************\n\n";
	playGame(white, black);
		
	return 0;
}

