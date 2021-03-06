#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece
{

public:

	Knight(Color color = WHITE, std::string name = "", int row = 0, int column = 0);

	~Knight();

	void print(std::ostream &flux) const;

	bool canMove(int i, int j, int k, int l, Board* board) const;

};

#endif