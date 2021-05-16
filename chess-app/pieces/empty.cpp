#include "empty.hpp"


std::string Empty::identifier()
{
	return "  ";
}

std::string Empty::updateAllowedMoves(Chessboard* board){
	return "";
}

Empty::Empty(bool team, Position pos) : Piece(team, pos) { }

