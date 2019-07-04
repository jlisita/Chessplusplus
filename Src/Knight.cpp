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


