#include "king.hpp"

std::string King::identifier()
{
	std::ostringstream out;
	if(getTeam()==0) out << "W";
	else out << "B";
	out << "k";
	return out.str();
}

std::string King::updateAllowedMoves(Chessboard* board){
	std::string moves;
	int row = pos.getRow();
	int col = pos.getCol();
	Position checker(0, 0);
	// ul (up left)
	if(PieceHelper::onBoard(row+1, col-1)){
		checker.updatePos(row+1, col-1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// u
	if(PieceHelper::onBoard(row+1, col)){
		checker.updatePos(row+1, col);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// ur
	if(PieceHelper::onBoard(row+1, col+1)){
		checker.updatePos(row+1, col+1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// r
	if(PieceHelper::onBoard(row, col+1)){
		checker.updatePos(row, col+1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// dr
	if(PieceHelper::onBoard(row-1, col+1)){
		checker.updatePos(row-1, col+1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// d
	if(PieceHelper::onBoard(row-1, col)){
		checker.updatePos(row-1, col);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// dl
	if(PieceHelper::onBoard(row-1, col-1)){
		checker.updatePos(row-1, col-1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// l
	if(PieceHelper::onBoard(row, col-1)){
		checker.updatePos(row, col-1);
		if((board->getPiece(checker)->getTeam()!=this->getTeam()) || board->getPiece(checker)->print()=="  ") 
		moves = moves + checker.getPosString() + " ";
	}
	
	// castle left
	// castle right
	return moves;
}

King::King(bool team, Position pos) : Piece(team, pos) { }



