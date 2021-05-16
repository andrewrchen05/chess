#include "chessboard.hpp"
#include "pieces/piecehelper.hpp"

Piece* Chessboard::getPiece(int row, int col){
	Position pos(row,col);
	return getPiece(pos);
}

Piece* Chessboard::getPiece(std::string lN){
	Position pos(lN);
	return getPiece(pos);
}

Piece* Chessboard::getPiece(Position pos){
	if(PieceHelper::onBoard(pos)) return board[pos.getRow()][pos.getCol()];
	else return nullptr;
}

Piece* Chessboard::getKing(bool team){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			if(getPiece(i, j)->type()=="king" && getPiece(i, j)->getTeam()==team) return getPiece(i, j);
		}
	}
	return nullptr;
}

void Chessboard::setPiece(Position pos, Piece* moved){
	this->board[pos.getRow()][pos.getCol()] = moved;
}

std::string Chessboard::getHistory() { // for testing purposes
	return moveHistory;
}

void Chessboard::save(int slot){
	std::ofstream of;
	switch(slot){
		case(1): of.open("1.sav"); break;
		case(2): of.open("2.sav"); break;
		case(3): of.open("3.sav"); break;
	}
	of << moveHistory;
	of.close();
}

int Chessboard::load(int slot){ // returns: -1 if failed, 0 if it is white's turn, 1 if it is black's turn
	if(!fresh) return -1;
	std::ifstream saveFile;
	std::string savedMoves;
	switch(slot){
		case(1): saveFile.open("1.sav"); break;
		case(2): saveFile.open("2.sav"); break;
		case(3): saveFile.open("3.sav"); break;
	}
	std::getline(saveFile, savedMoves);
	saveFile.close();
	int turn = 0;
	while(savedMoves.size()>0){
		tryMove(savedMoves.substr(0, 5));
		turn = (turn+1)%2;
		savedMoves = savedMoves.erase(0,6); //deletes first 6 chars from string, AKA the first move
	}
	return turn;
}

int Chessboard::load(std::string savedMoves){ // for testing purposes
	moveHistory = "";
	if(!fresh) return -1;
	int turn = 0;
	while(savedMoves.size()>0){
		tryMove(savedMoves.substr(0, 5));
		turn = (turn+1)%2;
		savedMoves = savedMoves.erase(0,6); //deletes first 6 chars from string, AKA the first move
	}
	return turn;
}

std::string Chessboard::undo() {
	return moveHistory.substr(0, moveHistory.size() - 6);
	std::cout << "Move history after undo: " << moveHistory << std::endl;
}

bool Chessboard::tryMove(std::string input){
	if(input.size()!=5){
		std::cout<<"Invalid move input! Format example: \"e2 e4\"\n";
		return false;
	}
	Position pos(input.substr(0,2));
	if (!PieceHelper::onBoard(pos)) {
		std::cout<<"Invalid move input! "<<pos.getPosString()<<" is not a valid position.\n";
		return false;
	}
	Position newPos(input.substr(3,2));
	if (!PieceHelper::onBoard(newPos)) {
		std::cout<<"Invalid move input! "<<newPos.getPosString()<<" is not a valid position.\n";
		return false;
	}
	bool success = getPiece(pos)->move(newPos, this);
	if(success){
		moveHistory = moveHistory + input + " ";
		fresh = false;
		return true;
	}
	else {
		std::cout << "Invalid move input! This move is not possible.\n";
		return false;
	}
}

int Chessboard::gameStatus(){
	bool whiteChecked = getKing(0)->inDanger(this);
	bool blackChecked = getKing(1)->inDanger(this);
	int whiteMoves = PieceHelper::totalPossibleMoves(0, this);
	int blackMoves = PieceHelper::totalPossibleMoves(1, this);
	if(whiteMoves>0 && blackMoves>0 && !whiteChecked && !blackChecked)	return 0;
	if(whiteMoves>0 && blackMoves>0 && whiteChecked && !blackChecked)	return 1;
	if(whiteMoves>0 && blackMoves>0 && !whiteChecked && blackChecked)	return 2;
	if(whiteMoves==0 && blackMoves>0 && whiteChecked && !blackChecked)	return 3;
	if(whiteMoves>0 && blackMoves==0 && !whiteChecked && blackChecked)	return 4;
	if(whiteMoves==0 && blackMoves>0 && !whiteChecked && !blackChecked)	return 5;
	if(whiteMoves>0 && blackMoves==0 && !whiteChecked && !blackChecked)	return 6;
	return 0;
}

Chessboard::Chessboard() {
	board[7][0] = PieceCreator::create("rook", 1, 7, 0);
	board[7][1] = PieceCreator::create("knight", 1, 7, 1);
	board[7][2] = PieceCreator::create("bishop", 1, 7, 2);
	board[7][3] = PieceCreator::create("queen", 1, 7, 3);
	board[7][4] = PieceCreator::create("king", 1, 7, 4);
	board[7][5] = PieceCreator::create("bishop", 1, 7, 5);
	board[7][6] = PieceCreator::create("knight", 1, 7, 6);
	board[7][7] = PieceCreator::create("rook", 1, 7, 7);
	
	
	for (int i = 0; i < 8; ++i) {
		board[6][i] = PieceCreator::create("pawn", 1, 6, i);
		board[1][i] = PieceCreator::create("pawn", 0, 1, i);
	}
	for (int i = 2; i < 6; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = PieceCreator::create("empty", 0, i, j);
		}
	}

	board[0][0] = PieceCreator::create("rook", 0, 0, 0);
	board[0][1] = PieceCreator::create("knight", 0, 0, 1);
	board[0][2] = PieceCreator::create("bishop", 0, 0, 2);
	board[0][3] = PieceCreator::create("queen", 0, 0, 3);
	board[0][4] = PieceCreator::create("king", 0, 0, 4);
	board[0][5] = PieceCreator::create("bishop", 0, 0, 5);
	board[0][6] = PieceCreator::create("knight", 0, 0, 6);
	board[0][7] = PieceCreator::create("rook", 0, 0, 7);
}


void Chessboard::showBoard(){
	std::ostringstream out;
	out << " ╔═════════════════════════╗\n";

	out << "8║ "<<board[7][0]->print()<<"│"<<board[7][1]->print()<<"│"<<board[7][2]->print()<<"│"<<board[7][3]->print()<<"│"<<board[7][4]->print()<<"│"<<board[7][5]->print()<<"│"<<board[7][6]->print()<<"│"<<board[7][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "7║ "<<board[6][0]->print()<<"│"<<board[6][1]->print()<<"│"<<board[6][2]->print()<<"│"<<board[6][3]->print()<<"│"<<board[6][4]->print()<<"│"<<board[6][5]->print()<<"│"<<board[6][6]->print()<<"│"<<board[6][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "6║ "<<board[5][0]->print()<<"│"<<board[5][1]->print()<<"│"<<board[5][2]->print()<<"│"<<board[5][3]->print()<<"│"<<board[5][4]->print()<<"│"<<board[5][5]->print()<<"│"<<board[5][6]->print()<<"│"<<board[5][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "5║ "<<board[4][0]->print()<<"│"<<board[4][1]->print()<<"│"<<board[4][2]->print()<<"│"<<board[4][3]->print()<<"│"<<board[4][4]->print()<<"│"<<board[4][5]->print()<<"│"<<board[4][6]->print()<<"│"<<board[4][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "4║ "<<board[3][0]->print()<<"│"<<board[3][1]->print()<<"│"<<board[3][2]->print()<<"│"<<board[3][3]->print()<<"│"<<board[3][4]->print()<<"│"<<board[3][5]->print()<<"│"<<board[3][6]->print()<<"│"<<board[3][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "3║ "<<board[2][0]->print()<<"│"<<board[2][1]->print()<<"│"<<board[2][2]->print()<<"│"<<board[2][3]->print()<<"│"<<board[2][4]->print()<<"│"<<board[2][5]->print()<<"│"<<board[2][6]->print()<<"│"<<board[2][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "2║ "<<board[1][0]->print()<<"│"<<board[1][1]->print()<<"│"<<board[1][2]->print()<<"│"<<board[1][3]->print()<<"│"<<board[1][4]->print()<<"│"<<board[1][5]->print()<<"│"<<board[1][6]->print()<<"│"<<board[1][7]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "1║ "<<board[0][0]->print()<<"│"<<board[0][1]->print()<<"│"<<board[0][2]->print()<<"│"<<board[0][3]->print()<<"│"<<board[0][4]->print()<<"│"<<board[0][5]->print()<<"│"<<board[0][6]->print()<<"│"<<board[0][7]->print()<<" ║\n";

	out << " ╚═════════════════════════╝\n";
	out << "   a  b  c  d  e  f  g  h\n";
	std::cout<<out.str();
}


void Chessboard::showBoardFlipped(){
	std::ostringstream out;
	out << " ╔═════════════════════════╗\n";

	out << "1║ "<<board[0][7]->print()<<"│"<<board[0][6]->print()<<"│"<<board[0][5]->print()<<"│"<<board[0][4]->print()<<"│"<<board[0][3]->print()<<"│"<<board[0][2]->print()<<"│"<<board[0][1]->print()<<"│"<<board[0][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "2║ "<<board[1][7]->print()<<"│"<<board[1][6]->print()<<"│"<<board[1][5]->print()<<"│"<<board[1][4]->print()<<"│"<<board[1][3]->print()<<"│"<<board[1][2]->print()<<"│"<<board[1][1]->print()<<"│"<<board[1][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "3║ "<<board[2][7]->print()<<"│"<<board[2][6]->print()<<"│"<<board[2][5]->print()<<"│"<<board[2][4]->print()<<"│"<<board[2][3]->print()<<"│"<<board[2][2]->print()<<"│"<<board[2][1]->print()<<"│"<<board[2][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "4║ "<<board[3][7]->print()<<"│"<<board[3][6]->print()<<"│"<<board[3][5]->print()<<"│"<<board[3][4]->print()<<"│"<<board[3][3]->print()<<"│"<<board[3][2]->print()<<"│"<<board[3][1]->print()<<"│"<<board[3][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "5║ "<<board[4][7]->print()<<"│"<<board[4][6]->print()<<"│"<<board[4][5]->print()<<"│"<<board[4][4]->print()<<"│"<<board[4][3]->print()<<"│"<<board[4][2]->print()<<"│"<<board[4][1]->print()<<"│"<<board[4][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "6║ "<<board[5][7]->print()<<"│"<<board[5][6]->print()<<"│"<<board[5][5]->print()<<"│"<<board[5][4]->print()<<"│"<<board[5][3]->print()<<"│"<<board[5][2]->print()<<"│"<<board[5][1]->print()<<"│"<<board[5][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "7║ "<<board[6][7]->print()<<"│"<<board[6][6]->print()<<"│"<<board[6][5]->print()<<"│"<<board[6][4]->print()<<"│"<<board[6][3]->print()<<"│"<<board[6][2]->print()<<"│"<<board[6][1]->print()<<"│"<<board[6][0]->print()<<" ║\n";

	out<<" ║───┼──┼──┼──┼──┼──┼──┼───║\n";
	out << "8║ "<<board[7][7]->print()<<"│"<<board[7][6]->print()<<"│"<<board[7][5]->print()<<"│"<<board[7][4]->print()<<"│"<<board[7][3]->print()<<"│"<<board[7][2]->print()<<"│"<<board[7][1]->print()<<"│"<<board[7][0]->print()<<" ║\n";

	out << " ╚═════════════════════════╝\n";
	out << "   h  g  f  e  d  c  b  a\n";
	std::cout<<out.str();
}
