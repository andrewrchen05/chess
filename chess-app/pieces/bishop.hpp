#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "piece.hpp"

class Chessboard;

class Bishop : public Piece
{
	virtual std::string identifier();
	protected:
	public:
	virtual std::string updateAllowedMoves(Chessboard* board);
	Bishop(bool team, Position pos);
	virtual std::string type(){return "bishop";}
};


#endif //BISHOP_HPP
