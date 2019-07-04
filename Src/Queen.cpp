#include <iostream>
#include "Queen.h"

using namespace std;

Queen::Queen(Color color) : Piece(color)
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


