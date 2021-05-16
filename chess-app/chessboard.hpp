#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <vector>
#include <sstream>
#include <fstream>
#include "pieces/piece.hpp"
#include "position.hpp"
#include "piececreator/PieceCreator.hpp"

class Piece;
class PieceCreator;

class Chessboard {
	public:
		Chessboard();
		void showBoard();
		void showBoardFlipped();
		void showPrompt();
		void playGame();
		Piece* getPiece(int row, int col);
		Piece* getPiece(std::string lN);
		Piece* getPiece(Position pos);
		Piece* getKing(bool team);
		void setPiece(Position pos, Piece* moved);
		bool tryMove(std::string input);
		void save(int slot);
		int load(int slot);//non-functional if board isn't fresh
		int load(std::string savedMoves);
		std::string undo();
		std::string getHistory();
		int gameStatus();
	private:
		bool fresh = true; //once a piece is moved the board is no longer fresh
		std::vector<std::vector<Piece*>> board{8, std::vector<Piece*>(8, nullptr)};
		std::string moveHistory;
};

#endif
