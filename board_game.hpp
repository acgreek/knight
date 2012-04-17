#ifndef BOARD_GAME_HPP
#define BOARD_GAME_HPP
#include <vector>
#include <list>
#include <boost/foreach.hpp>
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
class BoardGamePiece {
	public: 
		BoardGamePiece(Board &board, int x, int y): board_(board), position_(x,y) {
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

class BoardView {
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
