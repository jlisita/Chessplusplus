#include <iostream>
#include <string>
#include "Piece.h"
#include "Board.h"

using namespace std;

Piece::Piece(Color color, string name, int row, int column) : m_color(color), m_name(name), m_row(row), m_column(column), m_firstMove(true)
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

string Piece::getName() const
{
	return m_name;
}

ostream& operator<<( ostream &flux, Piece const& piece)
{
	piece.print(flux);
	return flux;
}


