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


