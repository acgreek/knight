#include <ExtremeCUnit.h>
#include "knights.hpp"

TEST(KnightMoveOptions) {
	Board board(7,7);
	Knight knight1(board, 4,5);
	std::list<Position> positionList;
	knight1.moveOptions(positionList);
	AssertEqInt(positionList.size(), 3);
	std::list<Position>::iterator itr = positionList.begin();
	AssertEqInt(itr->x,1);
	AssertEqInt(itr->y,3);
	itr++;
	AssertEqInt(itr->x,2);
	AssertEqInt(itr->y,2);
	itr++;
	AssertEqInt(itr->x,6);
	AssertEqInt(itr->y,2);
	
	return 0;
}

TEST(KnightMoveTo) {
	Board board(7,7);
	Knight knight1(board, 4,5);
	std::list<Position> positionList;
	knight1.moveOptions(positionList);
	knight1.moveTo(positionList.front());

	knight1.moveOptions(positionList);
	AssertEqInt(positionList.size(), 3);
	std::list<Position>::iterator itr = positionList.begin();
	AssertEqInt(itr->x,4);
	AssertEqInt(itr->y,1);
	itr++;
	AssertEqInt(itr->x,4);
	AssertEqInt(itr->y,5);
	itr++;
	AssertEqInt(itr->x,3);
	AssertEqInt(itr->y,6);
	return 0;
}
