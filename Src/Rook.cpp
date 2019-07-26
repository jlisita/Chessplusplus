#include <iostream>
#include "Rook.h"
#include "Board.h"

using namespace std;

Rook::Rook(Color color, string name, int row, int column) : Piece(color, name, row, column)
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
	if(board->isEmptyBetween(i,j,k,l) == true)
	{
		if( (k-i==0) || (l-j==0) )
		{
			return true;
		}
		else
		{
			cout << "mouvement impossible pour cette pièce" << endl;
			return false;
		}
	}
	else
	{
			cout << "Il y a une piece entre ces 2 positions qui rend le déplacement impossible" << endl;
		return false;
	}
}


