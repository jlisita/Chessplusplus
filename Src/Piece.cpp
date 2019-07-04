#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece(Color color) : m_color(color)
{
}

Piece::~Piece()
{
}

Color Piece::getColor() const
{
	return m_color;
}

ostream& operator<<( ostream &flux, Piece const& piece)
{
	piece.print(flux);
	return flux;
}


