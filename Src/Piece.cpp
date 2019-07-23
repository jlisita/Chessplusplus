#include <iostream>
#include "Piece.h"
#include "Board.h"

using namespace std;

Piece::Piece(Color color, int row, int column) : m_color(color), m_firstMove(false), m_row(row), m_column(column)
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

int Piece::getRow() const
{
	return m_row;
}

int Piece::getColumn() const
{
	return m_column;
}

ostream& operator<<( ostream &flux, Piece const& piece)
{
	piece.print(flux);
	return flux;
}


