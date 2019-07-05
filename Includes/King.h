#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{

public:

	King(Color color = WHITE);

	~King();

	void print(std::ostream &flux) const;

	bool canMove(int xi, int yi, int xf, int yf) const;


};

#endif