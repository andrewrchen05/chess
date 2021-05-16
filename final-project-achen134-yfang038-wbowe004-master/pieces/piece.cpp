#include "piece.hpp"

Piece::Piece(bool team, Position pos){
	this->team = team;
	this->pos = pos;
}

std::string Piece::print(){
	std::ostringstream os;
	os << identifier();
	return os.str();
}

bool Piece::hasMoved(){return moved;}

Position Piece::getPosition(){return pos;}

bool Piece::getTeam(){return team;}

bool Piece::isEqual(Piece* other){ // for testing purposes
	if(this->getTeam()!=other->getTeam()) return false;
	if(this->getPosition().getPosString()!=other->getPosition().getPosString()) return false; //assuming Position overloads == operator
	if(this->print()!=other->print()) return false; //could fail if localization fails to make each piece unique in identifier
	return true;
}

bool Piece::inDanger(Chessboard* board){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			if(board->getPiece(i, j)->updateAllowedMoves(board).find(this->getPosition().getPosString())!=std::string::npos && board->getPiece(i, j)->getTeam()!=this->getTeam()) return true;
		}
	}
	return false;
}

int Piece::numMoves(Chessboard* board){
	std::string allMoves = PieceHelper::cullMoves(this, board);
	return allMoves.size()/3;
}


bool Piece::move(Position newPos, Chessboard* board){
	if(PieceHelper::cullMoves(this, board).find(newPos.getPosString())!=std::string::npos){
		Piece* temp = board->getPiece(newPos);
		board->setPiece(newPos, this);
		board->setPiece(pos, PieceCreator::create("empty", this->getTeam(), pos.getRow(), pos.getCol()));

		pos.updatePos(newPos.getPosString());
		delete temp;
		moved = true;
		return true;
	}
	else return false;
	//determine if the move is valid by checking if
	//1. spot isn't taken by your piece
	//2. spot is reachable by this piece
	//3. doesn't cause yourself to be checked
}
