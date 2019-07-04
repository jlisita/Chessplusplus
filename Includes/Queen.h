#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece
{

public:

	Queen(Color color = WHITE);

	~Queen();

	void print(std::ostream &flux) const;

};

#endif