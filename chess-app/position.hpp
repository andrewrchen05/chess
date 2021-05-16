#ifndef POSITION_HPP
#define POSITION_HPP
#include <string>
#include <iostream>
#include <sstream> //stringstream

class Position {
	public:
		Position();
		Position(int row, int col); // initialized at default setup
		Position(std::string letterNumber);
		void updatePos(int row, int col);
		void updatePos(std::string letterNumber);
		int getRow();
		int getCol();
		std::string getPosString();

	private:
		std::string ln;
		int row;
		int col;

};
#endif
