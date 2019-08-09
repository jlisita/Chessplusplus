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

	Piece(Color color = WHITE, std::string name = "", int row = 0, int column = 0);

	virtual ~Piece();

	Color getColor() const;

	bool getFirstMove() const;

	void setFirstMove();

	int getRow() const;

	int getColumn() const;

	std::string getName() const;

	virtual void print(std::ostream &flux) const = 0;

	virtual bool canMove(int i, int j, int k, int l, Board* Board) const = 0;

	void setPosition(int i, int j);

protected:

	Color m_color;
	std::string m_name;
	int m_row;
	int m_column;
	bool m_firstMove;


};

std::ostream& operator<<( std::ostream &flux, Piece const& piece);

#endif