#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{

public:

	Bishop(Color color = WHITE, int row = 0, int column = 0);

	~Bishop();

	void print(std::ostream &flux) const;

	bool canMove(int i, int j, int k, int l, Board* board) const;

	std::string getName() const;

};

#endif