#ifndef PIECECREATOR_HPP
#define PIECECREATOR_HPP
/*#include "../pieces/piece.hpp"
#include "../pieces/bishop.hpp"
#include "../pieces/king.hpp"
#include "../pieces/empty.hpp"
#include "../pieces/knight.hpp"
#include "../pieces/pawn.hpp"
#include "../pieces/queen.hpp"
#include "../pieces/rook.hpp"
#include "../position.hpp"
*/
#include <iostream>
#include <string>

class Piece;
class Pawn;
class Rook;
class Knight;
class Bishop;
class King;
class Queen;
class Empty;
class Position;

class PieceCreator
{
	public:
	static Piece* create(std::string name, bool team, int row, int col);
};


#endif //PIECECREATOR_HPP
