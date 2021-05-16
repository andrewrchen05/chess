#include "bishop.hpp"

std::string Bishop::identifier()
{
	std::ostringstream out;
	if(getTeam()==0) out << "W";
	else out << "B";
	out << "b";
	return out.str();
}

std::string Bishop::updateAllowedMoves(Chessboard* board){
	std::string moves;
	int row = pos.getRow(); //0-7
	int col = pos.getCol();
	bool done = false;
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

Bishop::Bishop(bool team, Position pos) : Piece(team, pos) { }

