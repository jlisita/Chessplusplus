#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece
{

public:

	Rook(Color color = WHITE);

	~Rook();

	void print(std::ostream &flux) const;

	bool canMove(int i, int j, int k, int l, Board* board) const;

};

#endif