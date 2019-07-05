#include <iostream>
#include "Pawn.h"

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

bool Pawn::canMove(int i, int j, int k, int l) const
{
	if(getColor() == WHITE)
	{
		if( ( (i==1) && (j==l) && (k-i==2) )
	    || ( (j==l) && (k-i == 1) )
	    || ( (k==i+1) && ((l==j+1) || (l==j-1)) ) )
		{
			return true;
		}
	}
	else
	{
		if( ( (i==6) && (j==l) && (k-i==-2) )
		|| ( (j==l) && (k-i==-1) )
		|| ( (k==i-1) && ((l==j-1) || (l==j+1)) ) )
		{
			return true;
		}
	}
	return false;
}


