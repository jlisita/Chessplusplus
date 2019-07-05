#include <iostream>
#include "Queen.h"

using namespace std;

Queen::Queen(Color color) : Piece(color)
{
}

Queen::~Queen()
{
}

void Queen::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2655";
	}
	else
	{
		flux << "\u265B";
	}
}

bool Queen::canMove(int i, int j, int k, int l) const
{
	if( (k-i==l-j) || (k-i==j-l) || (k-i==0) || (l-j==0) )
	{
		return true;
	}
	return false;
}


