#ifndef PAWN_HPP
#define PAWN_HPP
#include "piece.hpp"

class Chessboard;

class Pawn : public Piece
{
	virtual std::string identifier();
	public:
	virtual std::string updateAllowedMoves(Chessboard* board);
	Pawn(bool team, Position pos);
	virtual std::string type(){return "pawn";}
};




#endif //PAWN_HPP
