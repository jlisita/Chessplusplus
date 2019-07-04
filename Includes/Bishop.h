#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece
{

public:

	Bishop(Color color = WHITE);

	~Bishop();

	void print(std::ostream &flux) const;

};

#endif