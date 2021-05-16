#include "position.hpp"

Position::Position(){
		this->updatePos(0, 0);
}

Position::Position(int row, int col) {
	this->updatePos(row, col);
}

Position::Position(std::string letterNumber) {
	this->updatePos(letterNumber);
}

void Position::updatePos(int row, int col) {
	this->row = row;
	this->col = col;
	std::stringstream ss;
	ss << char(col+97) << char(row+49);
	ln = ss.str();
}

void Position::updatePos(std::string letterNumber) {
	this->ln = letterNumber;
	col = int(letterNumber[0]-97);
	row = int(letterNumber[1]-49);
}

int Position::getRow() {
	return row;
}

int Position::getCol() {
	return col;
}

std::string Position::getPosString() {
	return ln;
}
