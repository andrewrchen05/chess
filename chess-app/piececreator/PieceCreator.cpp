#include "PieceCreator.hpp"
#include "../pieces/piece.hpp"
#include "../pieces/bishop.hpp"
#include "../pieces/king.hpp"
#include "../pieces/empty.hpp"
#include "../pieces/knight.hpp"
#include "../pieces/pawn.hpp"
#include "../pieces/queen.hpp"
#include "../pieces/rook.hpp"
#include "../position.hpp"


Piece* PieceCreator::create(std::string name, bool team, int row, int col){
                Position pos(row, col);
                if(name=="pawn") {
                        Piece* piece = new Pawn(team, pos);
                        return piece;
                } else if(name=="rook") {
                        Piece* piece = new Rook(team, pos);
                        return piece;
                } else if(name=="knight") {
                        Piece* piece =new Knight(team, pos);
                        return piece;
                } else if(name=="bishop") {
                        Piece* piece = new Bishop(team, pos);
                        return piece;
                } else if(name=="queen") {
                        Piece* piece = new Queen(team, pos);
                        return piece;
                } else if(name=="king") {
                        Piece* piece = new King(team, pos);
                        return piece;
                } else{ //default condition so something is always returned
                        Piece* piece = new Empty(team, pos);
                        return piece;
                }
	}
