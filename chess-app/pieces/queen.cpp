#include "queen.hpp"

std::string Queen::identifier()
{
	std::ostringstream out;
	if(getTeam()==0) out << "W";
	else out << "B";
	out << "q";
	return out.str();
}

std::string Queen::updateAllowedMoves(Chessboard* board){
	std::string moves;
	int row = pos.getRow(); //0-7
	int col = pos.getCol();
	bool done = false;
	for(int i=col-1; PieceHelper::onBoard(row, i) && !done; i--){ // left
		Position checker(row, i);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	for(int i=col+1; PieceHelper::onBoard(row, i) && !done; i++){ //right
		Position checker(row, i);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	for(int i=row-1; PieceHelper::onBoard(i, col) && !done; i--){ //down
		Position checker(i, col);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	for(int i=row+1; PieceHelper::onBoard(i, col) && !done; i++){ //up
		Position checker(i, col);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	
	
	for(int i=row+1, j=col-1; PieceHelper::onBoard(i, j) && !done; i++, j--){ //up left
		Position checker(i, j);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	for(int i=row+1, j=col+1; PieceHelper::onBoard(i, j) && !done; i++, j++){ //up right
		Position checker(i, j);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	for(int i=row-1, j=col-1; PieceHelper::onBoard(i, j) && !done; i--, j--){ //down left
		Position checker(i, j);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	for(int i=row-1, j=col+1; PieceHelper::onBoard(i, j) && !done; i--, j++){ //down right
		Position checker(i, j);
		if((board->getPiece(checker)->getTeam()==this->getTeam()) && board->getPiece(checker)->print()!="  ") done = true; //board->getPiece(checker)->print()!="  " to check if that place isn't empty
		else if((board->getPiece(checker)->getTeam()!=this->getTeam()) && board->getPiece(checker)->print()!="  "){
			moves = moves + checker.getPosString() + " ";
			done = true;
		}
		else moves = moves + checker.getPosString() + " ";
	}
	done = false;
	return moves;
}

Queen::Queen(bool team, Position pos) : Piece(team, pos) { }

