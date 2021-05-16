#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece.hpp"

class Chessboard;

class Queen : public Piece
{
	virtual std::string identifier();
	public:
	virtual std::string updateAllowedMoves(Chessboard* board);
	Queen(bool team, Position pos);
	virtual std::string type(){return "queen";}
};

#endif //QUEEN_HPP
