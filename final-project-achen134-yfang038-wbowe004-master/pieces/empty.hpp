#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "piece.hpp"

class Chessboard;

class Empty : public Piece
{
	virtual std::string identifier();
	public:
	virtual std::string updateAllowedMoves(Chessboard* board);
	Empty(bool team, Position pos);
	virtual std::string type(){return "empty";}
};
#endif //EMPTY_HPP
