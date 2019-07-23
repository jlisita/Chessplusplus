#include <iostream>
#include "Rook.h"
#include "Board.h"

using namespace std;

Rook::Rook(Color color, int row, int column) : Piece(color, row, column)
{
}

Rook::~Rook()
{
}

void Rook::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2656";
	}
	else
	{
		flux << "\u265C";
	}
}

bool Rook::canMove(int i, int j, int k, int l, Board* board) const
{
	if( (k-i==0) || (l-j==0) )
	{
		return true;
	}
	return false;
}

string Rook::getName() const
{
	return "Rook";
}


