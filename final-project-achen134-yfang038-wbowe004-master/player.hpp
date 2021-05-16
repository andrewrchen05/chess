#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "chessboard.hpp"

class Player {
	public:
		virtual void executeTurn(Chessboard* chessboard) = 0;
		virtual bool playerTurn() = 0;
		virtual bool inGame() = 0;
		virtual void setTurn(bool) = 0;
	private:
		//virtual std::string identifier() = 0;
		bool turn;
		bool gameStatus;
};

class White : public Player {
	public:
		White();	//white goes first so initialize turn variable at start
		void executeTurn(Chessboard* chessboard);
		bool playerTurn();
		bool inGame();	//if any player quits game, game will end
		void setTurn(bool);
	private:
		//std::string identifier();
		bool turn;
		bool gameStatus;
};

class Black : public Player {
	public:
		Black();
                void executeTurn(Chessboard* chessboard);
                bool playerTurn();
		bool inGame();
		void setTurn(bool);
        private:
                //std::string identifier();
		bool turn;
		bool gameStatus;
};

#endif
