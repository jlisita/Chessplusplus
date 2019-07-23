#ifndef QUEEN_H
#define QUEEN_H

#include <string>
#include "Piece.h"

class Queen : public Piece
{

public:

	Queen(Color color = WHITE, int row = 0, int column = 0);

	~Queen();

	void print(std::ostream &flux) const;

	bool canMove(int i, int j, int k, int l, Board* board) const;

	std::string getName() const;

};

#endif