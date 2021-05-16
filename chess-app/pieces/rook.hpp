#ifndef ROOK_HPP
#define ROOK_HPP
#include "piece.hpp"

class Chessboard;

class Rook : public Piece
{
	std::string identifier();	
	public:
	std::string updateAllowedMoves(Chessboard* board);
	Rook(bool team, Position pos);
	virtual std::string type(){return "rook";}
};




#endif //ROOK_HPP
