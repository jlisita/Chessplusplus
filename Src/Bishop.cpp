#include <iostream>
#include "Bishop.h"
#include "Board.h"

using namespace std;

Bishop::Bishop(Color color, string name, int row, int column) : Piece(color, name, row, column)
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
	if(board->isEmptyBetween(i,j,k,l) == true)
	{
		if( (k-i==l-j) || (k-i==j-l) )
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
