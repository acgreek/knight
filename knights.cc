#include <vector>
struct BoardEntry {
	BoardEntry():steppedon(false) {}
	bool steppedon;
};
class Board {
	public:
		Board(int length, int width) {
			_board.resize(length);
			for (int i=0; i< length; i++) {
				_board[i].resize(width);
			}
		}
		
	private:
		std::vector<std::vector<BoardEntry> > _board;
};

#include <ExtremeCUnit.h>

TEST(run) {
	Board board(7,7);

	return 0;
}
