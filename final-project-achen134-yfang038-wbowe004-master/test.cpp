#include "chessboard.hpp"
#include "position.hpp"
#include "piececreator/PieceCreator.hpp"
#include "pieces/piece.hpp"
#include "pieces/pawn.hpp"
#include "pieces/rook.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

#include "gtest/gtest.h"

TEST(Piece, PawnPrint) {
	Position pos(2, 3);
    Piece* pawn = new Pawn(0, pos);
	EXPECT_EQ(pawn->print(), "Wp");
}
TEST(Piece, Equal){
	Position pos(7, 1);
	Piece* knight = new Knight(1, pos);
	Piece* knight2 = new Knight(1, pos);
	EXPECT_TRUE(knight->isEqual(knight2)); 
}

TEST(PositionTesting, StringtoRow){
	Position pos("a1");
	EXPECT_EQ(pos.getRow(), 0);
}
TEST(PositionTesting, StringtoCol){
	Position pos("a1");
	EXPECT_EQ(pos.getCol(), 0);
}
TEST(PositionTesting, RowColtoString){
	Position pos(7, 4);
	EXPECT_EQ(pos.getPosString(), "e8");
}
TEST(PositionTesting, FullCircle){
	Position pos(7, 4);
	pos.updatePos(pos.getPosString());
	EXPECT_EQ(pos.getRow(), 7);
}

TEST(BoardTesting, Initialized) {
	Chessboard board;
	Piece* piece = board.getPiece("e8"); //black king location
	EXPECT_EQ(piece->print(), "Bk");
}

TEST(MoveTesting, Initialized) {
	Chessboard* board = new Chessboard();
	Piece* piece = board->getPiece("e8"); //black king location
	EXPECT_EQ(piece->updateAllowedMoves(board), "");
}

TEST(MoveTesting, FirstPawn) {
	Chessboard board;
	Piece* piece = board.getPiece("e2");
	Position newPos("e4");
	piece->move(newPos, &board);
	EXPECT_EQ(piece->getPosition().getPosString(), "e4");
}

TEST(MoveTesting, UserInToMove) {
	Chessboard board;
	std::string userInput = "e2 e4";
	board.tryMove(userInput); //ensure string format is valid, get piece at e2, run that pieces' move function to e4
	
	Piece* piece = board.getPiece("e4");
	EXPECT_EQ(piece->print(), "Wp");
}

TEST(MoveTesting, KnightAllMoves) {
	Chessboard board;
	EXPECT_EQ(board.getPiece("g1")->updateAllowedMoves(&board), "f3 h3 ");
}

TEST(MoveTesting, PawnCapture) {
	Chessboard board;
	board.tryMove("e2 e4");
	board.tryMove("e7 e5");
	board.tryMove("d2 d4");
	board.tryMove("d7 d5");
	
	EXPECT_EQ(board.getPiece("d4")->updateAllowedMoves(&board), "e5 ");
}

TEST(MoveTesting, Bishop){
	std::string exampleSave = "e2 e3 g2 g3 f1 d3 d3 e4";
	Chessboard board;
	board.load(exampleSave);
	EXPECT_EQ(board.getPiece("e4")->updateAllowedMoves(&board), "d5 c6 b7 f5 g6 h7 d3 f3 g2 ");
}

TEST(MoveTesting, Queen){
        std::string exampleSave = "d2 d4 c2 c4 d1 a4";
        Chessboard board;
        board.load(exampleSave);
        EXPECT_EQ(board.getPiece("a4")->updateAllowedMoves(&board), "b4 a3 a5 a6 a7 b5 c6 d7 b3 c2 d1 ");
}

TEST(MoveTesting, Rook){
        std::string exampleSave = "h2 h4 h1 h3";
        Chessboard board;
        board.load(exampleSave);
        EXPECT_EQ(board.getPiece("h3")->updateAllowedMoves(&board), "g3 f3 e3 d3 c3 b3 a3 h2 h1 ");
}

TEST(MoveTesting, King){
        Chessboard board;
        Position pos;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				pos.updatePos(i,j);
				board.setPiece(pos, PieceCreator::create("empty", 0, pos.getRow(), pos.getCol()));
			}
		}
		pos.updatePos("e5");
		board.setPiece(pos, PieceCreator::create("king", 0, pos.getRow(), pos.getCol()));
        EXPECT_EQ(PieceHelper::cullMoves(board.getPiece("e5"), &board), "d6 e6 f6 f5 f4 e4 d4 d5 ");
}

TEST(SaveLoadTesting, LoadFromString){
	std::string exampleSave = "e2 e4 e7 e5 d2 d4 d7 d5";
	Chessboard board;
	board.load(exampleSave);
	EXPECT_EQ(board.getPiece("d4")->updateAllowedMoves(&board), "e5 ");
}

TEST(SaveLoadTesting, Turn) {
	std::string exampleSave = "e2 e4 e7 e5 d2 d4 d7 d5";
        Chessboard board;
	EXPECT_EQ(board.load(exampleSave), 0); 
}

/*
TEST(FactoryTest, CreateKnight) {
	Position pos(7, 1);
	Piece* knight = PieceCreator::create("knight", 1, pos); // std::string name, bool team, Position pos	Expecting create to be a static function
	Piece* knight2 = new Knight(1, pos);
	EXPECT_TRUE(   knight==knight2   ); // == operator overloaded in piece.hpp
}
*/
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

