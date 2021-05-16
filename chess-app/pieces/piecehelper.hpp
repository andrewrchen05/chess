#ifndef __PIECEHELPER_HPP__
#define __PIECEHELPER_HPP__
#include <iostream>
#include "piece.hpp"
#include "../chessboard.hpp"
#include "../position.hpp"

class Piece;
class Chessboard;

class PieceHelper{
	public:
	//bool onBoard for 2 ints (row, col) and position
	static bool onBoard(Position pos);
	static bool onBoard(int row, int col);
	static bool selfCheck(Piece* piece, Chessboard* board);
	static std::string cullMoves(Piece* piece, Chessboard* board);
	static int totalPossibleMoves(bool team, Chessboard* board);
};


#endif//__PIECEHELPER_HPP__
