#include <iostream>
#include "Rook.h"

using namespace std;

Rook::Rook(Color color) : Piece(color)
{
}

Rook::~Rook()
{
}

void Rook::print(std::ostream &flux) const
{
	if(m_color == WHITE)
	{
		flux << "\u2656";
	}
	else
	{
		flux << "\u265C";
	}
}


