#include <iostream>
#include "Bishop.h"

using namespace std;

Bishop::Bishop(Color color) : Piece(color)
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


