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

	Piece(Color color = WHITE, int row = 0, int column = 0);

	virtual ~Piece();

	Color getColor() const;

	bool getFirstMove() const;

	void setFirstMove();

	int getRow() const;

	int getColumn() const;

	virtual void print(std::ostream &flux) const = 0;

	virtual bool canMove(int i, int j, int k, int l, Board* Board) const = 0;

	virtual std::string getName() const = 0;


protected:

	Color m_color;
	bool m_firstMove;
	int m_row;
	int m_column;


};

std::ostream& operator<<( std::ostream &flux, Piece const& piece);

#endif