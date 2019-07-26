#include <iostream>
#include "Queen.h"
#include "Board.h"

using namespace std;

Queen::Queen(Color color, string name, int row, int column) : Piece(color, name, row, column)
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

bool Queen::canMove(int i, int j, int k, int l, Board* board) const
{
	if(board->isEmptyBetween(i,j,k,l) == true)
	{
		if( (k-i==l-j) || (k-i==j-l) || (k-i==0) || (l-j==0) )
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
