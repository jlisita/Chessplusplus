#include <iostream>
#include "Knight.h"

using namespace std;

Knight::Knight(Color color) : Piece(color)
{
}

Knight::~Knight()
{
}

void Knight::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2658";
	}
	else
	{
		flux << "\u265E";
	}
}

bool Knight::canMove(int i, int j, int k, int l) const
{
	if  ( ( (k-i==2) && ( (l-j==1) || (l-j==-1) ) ) || ( (k-i==-2) && ( (l-j==1) || (l-j==-1) ) )
     || ( (k-i==1) && ( (l-j==2) || (l-j==-2) ) ) || ( (k-i==-1) && ( (l-j==2) || (l-j==-2) ) ) )
     {
     	return true;
     }
     return false;
}


