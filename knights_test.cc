#include <ExtremeCUnit.h>
#include "knights.hpp"

TEST(KnightMoveOptions) {
	Board board(7,7);
	Knight knight1(board, 4,5);
	std::list<Position> positionList;
	knight1.moveOptions(positionList);
	AssertEqInt(positionList.size(), 6);
	std::list<Position>::iterator itr = positionList.begin();
	AssertEqInt(itr->x,2);
	AssertEqInt(itr->y,4);
	itr++;
	AssertEqInt(itr->x,2);
	AssertEqInt(itr->y,6);
	itr++;
	AssertEqInt(itr->x,6);
	AssertEqInt(itr->y,4);
	
	return 0;
}
TEST(MoveEveryWherePlayer) {
	Board board(7,7);
	Knight knight1(board, 4,5);
	MoveEveryWherePlayer player(board);
	player.givePiece(&knight1);
	AssertEqInt(knight1.getPosition().x,4);
	AssertEqInt(knight1.getPosition().y,5);
	player.takeTurn();
	AssertEqInt(knight1.getPosition().x,2);
	AssertEqInt(knight1.getPosition().y,4);
	
	
	return 0;
}
TEST(PlayGame) {
	Board board(8,8);
	Knight knight1(board, 4,0);
	MoveEveryWherePlayer player(board);
	player.givePiece(&knight1);
	int i=0;

	while (0 == haveTouchedEverySquare(board) && i < 100000) {
		player.takeTurn();
		i++;
	}
	AssertEqInt(i, 117);
	
	return 0;
}


TEST(KnightMoveTo) {
	Board board(7,7);
	Knight knight1(board, 4,5);
	std::list<Position> positionList;
	knight1.moveOptions(positionList);
	knight1.moveTo(positionList.front());

	knight1.moveOptions(positionList);
	AssertEqInt(positionList.size(), 8);
	std::list<Position>::iterator itr = positionList.begin();
	AssertEqInt(itr->x,0);
	AssertEqInt(itr->y,3);
	itr++;
	AssertEqInt(itr->x,0);
	AssertEqInt(itr->y,5);
	itr++;
	AssertEqInt(itr->x,4);
	AssertEqInt(itr->y,3);
	return 0;
}

TEST(haveTouchedEverySquareSmallest) {
	Board board(1,1);
	AssertEqInt(haveTouchedEverySquare(board), 0);
	Position p(0,0);
	board.setEntry(p);
	AssertEqInt(haveTouchedEverySquare(board), 1);
	return 0;
}
TEST(haveTouchedEverySquareLarger) {
	Board board(2,1);
	AssertEqInt(haveTouchedEverySquare(board), 0);
	Position p(0,0);
	board.setEntry(p);
	AssertEqInt(haveTouchedEverySquare(board), 0);
	p.x = 1;
	board.setEntry(p);
	AssertEqInt(haveTouchedEverySquare(board), 1);
	return 0;
}
