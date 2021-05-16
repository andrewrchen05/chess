#ifndef KING_HPP
#define KING_HPP
#include "piece.hpp"

class Chessboard;

class King : public Piece
{
	virtual std::string identifier();
	public:
	virtual std::string updateAllowedMoves(Chessboard* board);
	King(bool team, Position pos);
	virtual std::string type(){return "king";}
};

#endif //KING_HPP
