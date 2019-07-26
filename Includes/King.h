#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{

public:

	King(Color color = WHITE, std::string name = "", int row = 0, int column = 0);

	~King();

	void print(std::ostream &flux) const;

	bool canMove(int i, int j, int k, int l, Board* baord) const;

};

#endif