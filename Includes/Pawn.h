#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"


class Pawn : public Piece
{

public:

	Pawn(Color color = WHITE, int row = 0, int column = 0);

	~Pawn();

	void print(std::ostream &flux) const;

	bool canMove(int i, int j, int k, int l, Board* board) const;

	std::string getName() const;

};

#endif