#include <iostream>
#include "Piece.h"
#include "Board.h"

using namespace std;

Piece::Piece(Color color) : m_color(color), m_firstMove(false)
{
}

Piece::~Piece()
{
}

Color Piece::getColor() const
{
	return m_color;
}


bool Piece::getFirstMove() const
{
	return m_firstMove;
}

void Piece::setFirstMove()
{
	m_firstMove = true;
}


ostream& operator<<( ostream &flux, Piece const& piece)
{
	piece.print(flux);
	return flux;
}


