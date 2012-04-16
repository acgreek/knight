#include <vector>
#include <list>
struct BoardEntry {
	BoardEntry();
	int steppedon;
};
struct Position {
	Position(int ix, int iy) : x(ix), y(iy) {} 
	int x;	
	int y;
};

class Board {
	public:
		Board(int length, int width) ;
		void setEntry(Position & p) {
			_board[p.x][p.y].steppedon++;
		}
		int getCount(Position & p) {
			return _board[p.x][p.y].steppedon;
		}
		int getLength() {
			_board.size();
		}
		int getWidth() {
			if (getLength() == 0) 
				return 0;
			_board[0].size();
		}
		friend int haveTouchedEverySquare(Board & board);

	private:
		std::vector<std::vector<BoardEntry> > _board;
};
class ChessPiece {
	public: 
		ChessPiece(Board &board, int x, int y): board_(board), position_(x,y) {
			board_.setEntry(position_);
		}
		virtual void moveOptions(std::list<Position> & positionList) = 0;
		virtual void moveTo(Position & position) {
			position_ = position;
			board_.setEntry(position);
		}
		const Position getPosition() const {
			return position_;
		}
		
		
	protected: 
		Board &board_;
		Position position_;
	private:
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
/**
 * @return 1 if have touched every square, 0 otherwise
 */
int haveTouchedEverySquare(Board & board) {
	int x=0, y= 1;
	int status = 1;
	BOOST_FOREACH (std::vector<BoardEntry> &column,board._board) {

		BOOST_FOREACH(BoardEntry & e, column) {
			printf(" %d", e.steppedon);
			if (0 == e.steppedon) 
				status=0;
		}
		printf("\n");
	}

	printf("=================\n");
	return status;
}
