#include <iostream>
#include <string>
#include <stack>
#include "player.hpp"

White::White() {
	turn = true;
	gameStatus = true;
}

bool White::inGame() {
	return gameStatus;
}

bool White::playerTurn() {
        return turn;
}

void White::setTurn(bool turn) {
        this->turn = turn;
}

void White::executeTurn(Chessboard* chessboard) {
	std::string move;
	while(1) {
		chessboard->showBoard();
		if (chessboard->gameStatus() == 1) {
         	        std::cout << "YOU ARE IN CHECK" << std::endl;
		
		}
		else if (chessboard->gameStatus() == 3) {
			std::cout << "YOU HAVE BEEN CHECKMATED" << std::endl;
			gameStatus = false;
			return;
		}
		else if (chessboard->gameStatus() == 5) {
			std::cout << "YOU HAVE NO MORE MOVES, DRAW" << std::endl;
                        gameStatus = false;
                        return;
		}
		std::cout << "\nEnter 'exit' to end game, 'save' to save game in slots 1-3" << std::endl;
		std::cout << "Your turn, Player 1: ";   
        	std::getline (std::cin,move);
		std::cout << "Move: " << move << "\n";
		if (move == "exit") {
			gameStatus = false;
			return;
		} 
		else if (move == "save") {
			int slot = 0;
			std::cout << "\nEnter slot to save game in (1-3): ";
			std::cin >> slot;
			chessboard->save(slot);
			gameStatus = false;	
			return;
		}
		if(chessboard->tryMove(move)){
			chessboard->getPiece(move.substr(0,2))->move(move.substr(3,2),chessboard);
			chessboard->showBoard();
			std::cout << "Please hit ENTER to confirm move, type 'undo' to undo: \n";
			std::getline (std::cin,move);
			if (move == "undo") {
				std::string revisedMoves = chessboard->undo();
				Chessboard* newchessboard = new Chessboard();
				newchessboard->load(revisedMoves);
				chessboard = newchessboard;
				continue;
			} 
			return;
		} else { // invalid message printed in tryMove()
			std::cout << "Please try again!\n";
		}
	}
}


Black::Black() {
	turn = false;
	gameStatus = true;
}

bool Black::inGame() {
	return gameStatus;
}

bool Black::playerTurn() {
        return turn;
}

void Black::setTurn(bool turn) {
	this->turn = turn;
}

void Black::executeTurn(Chessboard* chessboard) {
        std::string move;
        while(1) {
                chessboard->showBoardFlipped();
		if (chessboard->gameStatus() == 2) {
                        std::cout << "YOU ARE IN CHECK" << std::endl;
                }
                else if (chessboard->gameStatus() == 4) {
                        std::cout << "YOU HAVE BEEN CHECKMATED, YOU LOSE" << std::endl;
                	gameStatus = false;
                        return;
		}       
                else if (chessboard->gameStatus() == 6) {
                        std::cout << "YOU HAVE NO MORE MOVES, DRAW" << std::endl;
                        gameStatus = false;
			return;
                }
		std::cout << "\nEnter 'exit' to end game, 'save' to save game in slots 1-3" << std::endl;
		std::cout << "Your turn, Player 2: ";
                std::getline (std::cin,move);
                std::cout << "Move: " << move << "\n";
                if (move == "exit") {
                        gameStatus = false;
                        return;
                }
		else if (move == "save") {
                        int slot = 0;
                        std::cout << "\nEnter slot to save game in (1-3): ";
                        std::cin >> slot;
                        chessboard->save(slot);
                        gameStatus = false;
                        return;
                }
                if(chessboard->tryMove(move)){
                        chessboard->getPiece(move.substr(0,2))->move(move.substr(3,2),chessboard);
                        chessboard->showBoard();
			std::cout << "Please hit ENTER to confirm move, type 'undo' to undo: \n";
                        std::getline (std::cin,move);
                        if (move == "undo") {
                        	std::string revisedMoves = chessboard->undo();
                                Chessboard* newchessboard = new Chessboard();
                                newchessboard->load(revisedMoves);
                                //Chessboard* temp = nullptr;
				//temp = chessboard;
				chessboard = newchessboard;
                                //delete temp;
				continue;
			}
                        return;
		} else { // invalid message printed in tryMove()                       
				std::cout << "Please try again!\n";
		}
	}
}


