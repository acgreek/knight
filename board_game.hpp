#ifndef BOARD_GAME_HPP
#define BOARD_GAME_HPP
#include <vector>
#include <list>
#include <boost/foreach.hpp>

struct Position {
	Position(int ix, int iy) : x(ix), y(iy) {} 
	int x;	
	int y;
};

class GamePiece {
	public:
		GamePiece(int x, int y): position_(x,y) {}
		const Position getPosition() const {
			return position_;
		}
	protected:
		Position position_;
};

struct BoardEntry {
	BoardEntry() ;
	int steppedon;
	GamePiece * piece;

};

class Board {
	public:
		Board(int length, int width) ;
		void setPiece(GamePiece * piece) {
			const Position &p = piece->getPosition();
			_board[p.x][p.y].piece = piece;
			_board[p.x][p.y].steppedon++;
		}
		void removePiece(GamePiece * piece) {
			const Position &p = piece->getPosition();
			if (_board[p.x][p.y].piece  == piece)
				_board[p.x][p.y].piece = NULL;
		}
		int getCount(Position & p) {
			return _board[p.x][p.y].steppedon;
		}
		int getLength() {
			return _board.size();
		}
		int getWidth() {
			if (getLength() == 0) 
				return 0;
			return _board[0].size();
		}
		const std::vector<std::vector<BoardEntry> > & getBoard() {
			return _board;
		}
		int testSquares(int (*func)(const BoardEntry & e)) const{
			BOOST_FOREACH (const std::vector<BoardEntry> &column,_board) {
				BOOST_FOREACH(const BoardEntry & e, column) {
					if (0 == func (e))
						return 0;
				}
			}
			return 1;
		}
	private:
		std::vector<std::vector<BoardEntry> > _board;
};
class BoardGamePiece:public GamePiece {
	public: 
		BoardGamePiece(Board &board, int x, int y): GamePiece(x,y),board_(board)  {
			board_.setPiece(this);
		}
		virtual void moveOptions(std::list<Position> & positionList) = 0;
		virtual void moveTo(Position & position) {
			board_.removePiece(this);
			position_ = position;
			board_.setPiece(this);
		}
	protected: 
		virtual void addSorted(std::list<Position> & positionList, Position p) {
			if (positionList.size() ==0)
				positionList.push_front(p);
			else if (board_.getCount(positionList.front()) > board_.getCount(p))
				positionList.push_front(p);
			else
				positionList.push_back(p);
		}
		
		Board &board_;
	private:
};

class BoardView {
};

class Player {
	public:
		Player(Board &b) :board_(b) {}
		void givePiece(BoardGamePiece *aPiece) {
			p_ = aPiece;
		}
		virtual void takeTurn() = 0 ;
	protected:
		Board &board_;
		BoardGamePiece *p_;
};

#include <stdio.h>

class SimpleASCIIBoardView : public BoardView{
	public:
		SimpleASCIIBoardView(Board & board):board_(board) { }
		void draw() {
			BOOST_FOREACH (const std::vector<BoardEntry> &column,board_.getBoard()) {

				BOOST_FOREACH(const BoardEntry & e, column) {
					printf(" %d", e.steppedon);
				}
				printf("\n");
			}
			printf("=================\n");
		}
	private: 
		Board & board_;
};

#endif
