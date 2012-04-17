#ifndef CHESS_GAME_HPP
#define CHESS_GAME_HPP
#include "board_game.hpp"

class ChessPiece:public BoardGamePiece {
	public:
		ChessPiece(Board &board,int x, int y) :BoardGamePiece(board, x,y) {} ;
};

class Knight : public ChessPiece{
	public:

		Knight(Board &board,int x, int y) :ChessPiece(board, x,y) {} ;

		virtual void moveOptions(std::list<Position> & positionList) {
			int blength = board_.getLength();
			int bwidth = board_.getWidth();
			int move1 =2;
			int move2 =1;
			int ix=0, iy=0;
			positionList.clear();
			ix = position_.x - move1; 	
			iy = position_.y - move2; 	
			if (ix >= 0 && iy >=0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x - move1; 	
			iy = position_.y + move2; 	
			if (ix >= 0 && iy < blength)
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + move1; 	
			iy = position_.y - move2; 	
			if (ix < bwidth && iy >=0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + move1; 	
			iy = position_.y + move2; 	
			if (ix < bwidth && iy < blength)
				addSorted(positionList,Position(ix, iy));
			ix = position_.x - move2; 	
			iy = position_.y - move1; 	
			if (ix >= 0 && iy >=0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x - move2; 	
			iy = position_.y + move1; 	
			if (ix >= 0 && iy < blength)
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + move2; 	
			iy = position_.y - move1; 	
			if (ix < bwidth && iy >=0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + move2; 	
			iy = position_.y + move1; 	
			if (ix < bwidth && iy < blength)
				addSorted(positionList,Position(ix, iy));
		}
	private:
		virtual void addSorted(std::list<Position> & positionList, Position p) {
			if (positionList.size() ==0)
				positionList.push_front(p);
			else if (board_.getCount(positionList.front()) > board_.getCount(p))
				positionList.push_front(p);
			else
				positionList.push_back(p);
		}
		
};
#endif
