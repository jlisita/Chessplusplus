#include <iostream>
#include "King.h"

using namespace std;

King::King(Color color) : Piece(color)
{
}

King::~King()
{
}

void King::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2654";
	}
	else
	{
		flux << "\u265A";
	}
}


