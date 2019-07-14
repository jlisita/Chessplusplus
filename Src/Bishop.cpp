#include <iostream>
#include "Bishop.h"
#include "Board.h"

using namespace std;

Bishop::Bishop(Color color) : Piece(color)
{
}

Bishop::~Bishop()
{
}

void Bishop::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2657";
	}
	else
	{
		flux << "\u265D";
	}
}

bool Bishop::canMove(int i, int j, int k, int l, Board* board) const
{
	if( (k-i==l-j) || (k-i==j-l) )
	{
		return true;
	}
	return false;
}


