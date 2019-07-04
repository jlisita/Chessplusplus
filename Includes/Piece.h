#ifndef PIECE_H
#define PIECE_H

enum Color
{
	WHITE,BLACK
};

class Piece
{

public:

	Piece(Color color = WHITE);

	virtual ~Piece();

	Color getColor() const;

	virtual void print(std::ostream &flux) const = 0;

protected:

	Color m_color;


};

std::ostream& operator<<( std::ostream &flux, Piece const& piece);

#endif