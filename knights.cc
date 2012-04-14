#include <vector>
#include "knights.hpp"
BoardEntry::BoardEntry():steppedon(false) {}

Board::Board(int length, int width) {
	_board.resize(length);
	for (int i=0; i< length; i++) {
		_board[i].resize(width);
	}
}


