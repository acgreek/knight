#include <vector>
#include "knights.hpp"
BoardEntry::BoardEntry():steppedon(0) {}

Board::Board(int length, int width) {
	_board.resize(length);
	for (int i=0; i< length; i++) {
		_board[i].resize(width);
	}
}


