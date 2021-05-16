#include "pawn.hpp"

std::string Pawn::identifier()
{
	std::ostringstream out;
	if(getTeam()==0) out << "W";
	else out << "B";
	out << "p";
	return out.str();
}

std::string Pawn::updateAllowedMoves(Chessboard* board){
	std::string moves;
	int row = pos.getRow();
	int col = pos.getCol();
	Position checker(0, 0);
	//white
	if(this->getTeam()==0){
		if(!hasMoved() && PieceHelper::onBoard(row+2, col) && board->getPiece(row+1, col)->print()=="  "){
			checker.updatePos(row+2, col);
			if(board->getPiece(checker)->print()=="  ") moves = moves + checker.getPosString() + " ";
		}
		checker.updatePos(row+1, col);
		if(PieceHelper::onBoard(checker) && board->getPiece(checker)->print()=="  ") moves = moves + checker.getPosString() + " ";
		
		checker.updatePos(row+1, col+1);
		if(PieceHelper::onBoard(checker) && board->getPiece(checker)->print()!="  " && board->getPiece(checker)->getTeam()!=this->team) moves = moves + checker.getPosString() + " ";
		
		checker.updatePos(row+1, col-1);
		if(PieceHelper::onBoard(checker) && board->getPiece(checker)->print()!="  " && board->getPiece(checker)->getTeam()!=this->team) moves = moves + checker.getPosString() + " ";
		
		// en passant
	}
	
	//black
	if(this->getTeam()==1){
		if(!hasMoved() && PieceHelper::onBoard(row-2, col) && board->getPiece(row-1, col)->print()=="  "){
			checker.updatePos(row-2, col);
			if(board->getPiece(checker)->print()=="  ") moves = moves + checker.getPosString() + " ";
		}
		checker.updatePos(row-1, col);
		if(PieceHelper::onBoard(checker) && board->getPiece(checker)->print()=="  ") moves = moves + checker.getPosString() + " ";
		
		checker.updatePos(row-1, col+1);
		if(PieceHelper::onBoard(checker) && board->getPiece(checker)->print()!="  " && board->getPiece(checker)->getTeam()!=this->team) moves = moves + checker.getPosString() + " ";
		
		checker.updatePos(row-1, col-1);
		if(PieceHelper::onBoard(checker) && board->getPiece(checker)->print()!="  " && board->getPiece(checker)->getTeam()!=this->team) moves = moves + checker.getPosString() + " ";
		
		// en passant
	}
	return moves;
}

Pawn::Pawn(bool team, Position pos) : Piece(team, pos) { }

