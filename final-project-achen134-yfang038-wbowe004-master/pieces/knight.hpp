#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "piece.hpp"

class Chessboard;

class Knight : public Piece
{
	virtual std::string identifier();
	public:
	virtual std::string updateAllowedMoves(Chessboard* board);
	Knight(bool team, Position pos);
	virtual std::string type(){return "knight";}
};




#endif //KNIGHT_HPP
