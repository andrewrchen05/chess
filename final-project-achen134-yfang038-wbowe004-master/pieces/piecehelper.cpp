#include "piecehelper.hpp"

bool PieceHelper::onBoard(Position pos){
	int row = pos.getRow();
	int col = pos.getCol();
	if( row<0 || row>7) return false;
	if( col<0 || col>7) return false;
	return true;
}

bool PieceHelper::onBoard(int row, int col){
	if( row<0 || row>7) return false;
	if( col<0 || col>7) return false;
	return true;
}

bool PieceHelper::selfCheck(Piece* piece, Chessboard* board){
	Piece* king = board->getKing(piece->getTeam());
	if(king->inDanger(board)) return true;
	return false;
}

int PieceHelper::totalPossibleMoves(bool team, Chessboard* board){
	int possibleMoves = 0;
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			if(board->getPiece(i, j)->getTeam()==team) possibleMoves+= board->getPiece(i, j)->numMoves(board);
		}
	}
	return possibleMoves;
}

std::string PieceHelper::cullMoves(Piece* piece, Chessboard* board){
	std::string allAllowedMoves = piece->updateAllowedMoves(board); //"b4 a3 a5 a6 a7 b5 c6 d7 b3 c2 d1 "
	int moveIterator = 0;
	Position oldPos = piece->getPosition();
	Position tryPos;
	Piece* temp;
	while(moveIterator < allAllowedMoves.size()){
		tryPos.updatePos(allAllowedMoves.substr(moveIterator,2));
		temp = board->getPiece(tryPos);
		board->setPiece(tryPos, piece);
		board->setPiece(oldPos, PieceCreator::create("empty", piece->getTeam(), oldPos.getRow(), oldPos.getCol()));
		
		if(PieceHelper::selfCheck(piece, board)){//if you put yourself in check
			allAllowedMoves = allAllowedMoves.erase(moveIterator, 3);
		}
		else{
			moveIterator += 3;
		}
		board->setPiece(oldPos, piece);
		board->setPiece(tryPos, temp);
	}
	return allAllowedMoves;
}
