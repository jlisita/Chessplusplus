#include <iostream>
#include "Pawn.h"
#include "Board.h"

using namespace std;



Pawn::Pawn(Color color, string name, int row, int column) : Piece(color,name, row, column)
{
}

Pawn::~Pawn()
{
}

void Pawn::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2659";
	}
	else
	{
		flux << "\u265F";
	}
}

bool Pawn::canMove(int i, int j, int k, int l, Board* board) const
{
	if(board->isEmptyBetween(i,j,k,l) == true)
	{
		if(getColor() == WHITE)
		{
			if( ( (m_firstMove==true) && (j==l) && (k-i==2) && board->isEmpty(k,l) )
		    || ( (j==l) && (k-i == 1) && board->isEmpty(k,l) )
		    || ( (k==i+1) && ((l==j+1) || (l==j-1)) && !board->isEmpty(k,l)) )
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
			if( ( (m_firstMove==true) && (j==l) && (k-i==-2) && board->isEmpty(k,l) )
			|| ( (j==l) && (k-i==-1) && board->isEmpty(k,l) && board->isEmpty(k,l) )
			|| ( (k==i-1) && ((l==j-1) || (l==j+1)) && !board->isEmpty(k,l)) )
			{
				return true;
			}
			else
			{
				cout << "mouvement impossible pour cette pièce" << endl;
				return false;
			}
		}
	}
	else
	{
		cout << "Il y a une piece entre ces 2 positions qui rend le déplacement impossible" << endl;
		return false;
	}
}


