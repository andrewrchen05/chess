CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Chess)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
	test.cpp
	chessboard.cpp
	player.cpp
	position.cpp
	pieces/piece.cpp
	pieces/pawn.cpp
	pieces/rook.cpp
	pieces/knight.cpp
	pieces/bishop.cpp
	pieces/queen.cpp
	pieces/king.cpp
	pieces/empty.cpp
	pieces/piecehelper.cpp
	piececreator/PieceCreator.cpp
)

ADD_EXECUTABLE(chess
	main.cpp
	chessboard.cpp
	player.cpp
	position.cpp
	pieces/piece.cpp
	pieces/pawn.cpp
	pieces/rook.cpp
	pieces/knight.cpp
	pieces/bishop.cpp
	pieces/queen.cpp
	pieces/king.cpp
	pieces/empty.cpp
	pieces/piecehelper.cpp
	piececreator/PieceCreator.cpp
)

ADD_EXECUTABLE(chess1
        main1.cpp
        chessboard.cpp
        player.cpp
        position.cpp
        pieces/piece.cpp
        pieces/pawn.cpp
        pieces/rook.cpp
        pieces/knight.cpp
        pieces/bishop.cpp
        pieces/queen.cpp
        pieces/king.cpp
        pieces/empty.cpp
        pieces/piecehelper.cpp
	piececreator/PieceCreator.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
