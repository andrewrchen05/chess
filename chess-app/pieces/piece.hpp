#ifndef PIECE_HPP
#define PIECE_HPP
#include <iostream>
#include <sstream>
#include "../chessboard.hpp"
#include "../position.hpp"
#include "piecehelper.hpp"

class Chessboard;

class Piece
{
	virtual std::string identifier() = 0;
	protected:
		bool moved; //important for castling
		Position pos;
		bool team = 0;
	public:
		virtual std::string updateAllowedMoves(Chessboard* board) = 0;
		Piece(bool team, Position pos);
		bool move(Position pos, Chessboard* board);
		std::string print();
		bool hasMoved();
		Position getPosition();
		bool getTeam();
		bool isEqual(Piece* other);
		bool inDanger(Chessboard* board);
		int numMoves(Chessboard* board);
		virtual std::string type() = 0;
};

#endif //PIECE_HPP
