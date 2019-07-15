#ifndef PIECE_H
#define PIECE_H

class Board;

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

	bool getFirstMove() const;

	void setFirstMove();

	virtual void print(std::ostream &flux) const = 0;

	virtual bool canMove(int i, int j, int k, int l, Board* Board) const = 0;


protected:

	Color m_color;
	bool m_firstMove;


};

std::ostream& operator<<( std::ostream &flux, Piece const& piece);

#endif