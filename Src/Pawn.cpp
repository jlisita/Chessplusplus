#include <iostream>
#include "Pawn.h"
#include "Board.h"

using namespace std;



Pawn::Pawn(Color color) : Piece(color)
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
	if(getColor() == WHITE)
	{
		if( ( (m_firstMove==true) && (j==l) && (k-i==2) )
	    || ( (j==l) && (k-i == 1) )
	    || ( (k==i+1) && ((l==j+1) || (l==j-1)) && !board->isEmpty(k,l)) )
		{
			return true;
		}
	}
	else
	{
		if( ( (m_firstMove==true) && (j==l) && (k-i==-2) )
		|| ( (j==l) && (k-i==-1) )
		|| ( (k==i-1) && ((l==j-1) || (l==j+1)) && !board->isEmpty(k,l)) )
		{
			return true;
		}
	}
	return false;
}


