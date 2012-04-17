#ifndef BOARD_GAME_HPP
#define BOARD_GAME_HPP
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
			return _board.size();
		}
		int getWidth() {
			if (getLength() == 0) 
				return 0;
			return _board[0].size();
		}
		friend int haveTouchedEverySquare(Board & board);
		friend void drawBoard(Board & board);

	private:
		std::vector<std::vector<BoardEntry> > _board;
};

#endif
