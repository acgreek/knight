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

#include <boost/foreach.hpp>
#include <stdio.h>

void drawBoard(Board & board) {
	BOOST_FOREACH (std::vector<BoardEntry> &column,board._board) {

		BOOST_FOREACH(BoardEntry & e, column) {
			printf(" %d", e.steppedon);
		}
		printf("\n");
	}
	printf("=================\n");
}
/**
 * @return 1 if have touched every square, 0 otherwise
 */
int haveTouchedEverySquare(Board & board) {
	BOOST_FOREACH (std::vector<BoardEntry> &column,board._board) {

		BOOST_FOREACH(BoardEntry & e, column) {
			if (0 == e.steppedon) 
				return 0;
		}
	}
	return 1;
}
#endif
