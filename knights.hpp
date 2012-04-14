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
		
		
	protected: 
		Board &board_;
		Position position_;
	private:
};

class Knight : public ChessPiece{
	public:
		Knight(Board &board,int x, int y) :ChessPiece(board, x,y) {} ;

		virtual void moveOptions(std::list<Position> & positionList) {
			int ix=0, iy=0;
			positionList.clear();
			ix = position_.x - 3; 	
			iy = position_.y - 2; 	
			if (ix > 0 && iy >0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x - 3; 	
			iy = position_.y + 2; 	
			if (ix > 0 && iy < 7)
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + 3; 	
			iy = position_.y - 2; 	
			if (ix < 7 && iy >0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + 3; 	
			iy = position_.y + 2; 	
			if (ix < 7 && iy < 7)
				addSorted(positionList,Position(ix, iy));
			ix = position_.x - 2; 	
			iy = position_.y - 3; 	
			if (ix > 0 && iy >0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x - 2; 	
			iy = position_.y + 3; 	
			if (ix > 0 && iy < 7)
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + 2; 	
			iy = position_.y - 3; 	
			if (ix < 7 && iy >0 )
				addSorted(positionList,Position(ix, iy));
			ix = position_.x + 2; 	
			iy = position_.y + 3; 	
			if (ix < 7 && iy < 7)
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
