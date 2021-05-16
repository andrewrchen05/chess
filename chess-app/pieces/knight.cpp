#include "knight.hpp"


std::string Knight::identifier()
{
	std::ostringstream out;
	if(getTeam()==0) out << "W";
	else out << "B";
	out << "n";
	return out.str();
}

std::string Knight::updateAllowedMoves(Chessboard* board){
	std::string moves;
	int row = pos.getRow();
	int col = pos.getCol();
	Position checker(0, 0);
	// uul (up up left)
	if(PieceHelper::onBoard(row+2, col-1)){
		checker.updatePos(row+2, col-1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") //if the piece holds an enemy piece or is empty
		moves = moves + checker.getPosString() + " ";
	}
	
	// uur
	if(PieceHelper::onBoard(row+2, col+1)){
		checker.updatePos(row+2, col+1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// rru
	if(PieceHelper::onBoard(row+1, col+2)){
		checker.updatePos(row+1, col+2);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// rrd
	if(PieceHelper::onBoard(row-1, col+2)){
		checker.updatePos(row-1, col+2);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// ddr
	if(PieceHelper::onBoard(row-2, col+1)){
		checker.updatePos(row-2, col+1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// ddl
	if(PieceHelper::onBoard(row-2, col-1)){
		checker.updatePos(row-2, col-1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// lld
	if(PieceHelper::onBoard(row-1, col-2)){
		checker.updatePos(row-1, col-2);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// llu
	if(PieceHelper::onBoard(row+1, col-2)){
		checker.updatePos(row+1, col-2);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	return moves;
}

Knight::Knight(bool team, Position pos) : Piece(team, pos) { }
