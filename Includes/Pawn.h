#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"


class Pawn : public Piece
{

public:

	Pawn(Color color = WHITE);

	~Pawn();

	void print(std::ostream &flux) const;


};

#endif