#ifndef KNIGHTS_HPP
#define KNIGHTS_HPP
#include "chess_game.hpp"
class Player {
	public:
		Player(Board &b) :board_(b) {}
		void givePiece(ChessPiece *aPiece) {
			p_ = aPiece;
		}
		virtual void takeTurn() = 0 ;
	protected:
		Board &board_;
		ChessPiece *p_;
};
class MoveEveryWherePlayer: public Player {
	public:
		MoveEveryWherePlayer(Board & b) :Player(b) {}
		void takeTurn() {
			std::list<Position> positionList;
			p_->moveOptions(positionList);
			p_->moveTo(positionList.front());
		}
	private:
};



int steppedOn(const BoardEntry &e) {
	return e.steppedon == 0 ? 0 :1 ;
}

/**
 * @return 1 if have touched every square, 0 otherwise
 */
int haveTouchedEverySquare(Board & board) {
	return board.testSquares(steppedOn);
}
#endif
