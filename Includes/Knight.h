#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece
{

public:

	Knight(Color color = WHITE);

	~Knight();

	void print(std::ostream &flux) const;

};

#endif