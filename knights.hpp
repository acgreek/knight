#include <vector>
struct BoardEntry {
	BoardEntry();
	bool steppedon;
};
class Board {
	public:
		Board(int length, int width) ;
		
	private:
		std::vector<std::vector<BoardEntry> > _board;
};
