#include <iostream>
#include "King.h"
#include "Board.h"

using namespace std;

King::King(Color color) : Piece(color)
{
}

King::~King()
{
}

void King::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2654";
	}
	else
	{
		flux << "\u265A";
	}
}

bool King::canMove(int i, int j, int k, int l, Board* board) const
{
	if( ( (k-i==1) &&  ( (j==l) || (l-j==1) || (l-j==-1) ) )
	||  ( (k-i==-1) && ( (j==l) || (l-j==1) || (l-j==-1) ) )
	||  ( (k-i==0) && ( (l-j==1) || (l-j==-1) ) ) )
	{
		return true;
	}
	return false;
}


